#include "jazzlights/vest.h"

#include "jazzlights/config.h"

#ifdef ARDUINO

#include <memory>
#include <mutex>

#include "jazzlights/board.h"
#include "jazzlights/button.h"
#include "jazzlights/core2.h"
#include "jazzlights/fastled_wrapper.h"
#include "jazzlights/instrumentation.h"
#include "jazzlights/networks/arduino_esp_wifi.h"
#include "jazzlights/networks/arduino_ethernet.h"
#include "jazzlights/networks/esp32_ble.h"
#include "jazzlights/player.h"

#if CORE2AWS
#define LED_PIN 32
#elif defined(ESP32)
#if M5STAMP_PICO
#define LED_PIN 32
#elif M5STAMP_C3U
#define LED_PIN 1
#else  // M5STAMP
#define LED_PIN 26
#define LED_PIN2 32
#endif  // M5STAMP
#else
#error "Unexpected board"
#endif

#ifndef BRIGHTER2
#define BRIGHTER2 0
#endif  // BRIGHTER2

namespace jazzlights {

static std::mutex gLockedLedMutex;

Network* GetWiFiNetwork() { return ArduinoEspWiFiNetwork::get(); }

class FastLedRenderer : public Renderer {
 public:
  explicit FastLedRenderer(size_t numLeds) : ledMemorySize_(numLeds * sizeof(CRGB)) {
    ledsPlayer_ = reinterpret_cast<CRGB*>(calloc(ledMemorySize_, 1));
    ledsLocked_ = reinterpret_cast<CRGB*>(calloc(ledMemorySize_, 1));
    ledsFastLed_ = reinterpret_cast<CRGB*>(calloc(ledMemorySize_, 1));
    if (ledsPlayer_ == nullptr || ledsLocked_ == nullptr || ledsFastLed_ == nullptr) {
      jll_fatal("Failed to allocate %zu*%zu", numLeds, sizeof(CRGB));
    }
  }
  ~FastLedRenderer() {
    free(ledsPlayer_);
    free(ledsLocked_);
    free(ledsFastLed_);
  }

  // 4 wires with specified data rate.
  template <ESPIChipsets CHIPSET, uint8_t DATA_PIN, uint8_t CLOCK_PIN, EOrder RGB_ORDER, uint32_t SPI_DATA_RATE>
  static std::unique_ptr<FastLedRenderer> Create(size_t numLeds) {
    std::unique_ptr<FastLedRenderer> r = std::unique_ptr<FastLedRenderer>(new FastLedRenderer(numLeds));
    r->ledController_ =
        &FastLED.addLeds<CHIPSET, DATA_PIN, CLOCK_PIN, RGB_ORDER, SPI_DATA_RATE>(r->ledsFastLed_, numLeds);
    return r;
  }

  // 4 wires with default data rate.
  template <ESPIChipsets CHIPSET, uint8_t DATA_PIN, uint8_t CLOCK_PIN, EOrder RGB_ORDER>
  static std::unique_ptr<FastLedRenderer> Create(size_t numLeds) {
    std::unique_ptr<FastLedRenderer> r = std::unique_ptr<FastLedRenderer>(new FastLedRenderer(numLeds));
    r->ledController_ = &FastLED.addLeds<CHIPSET, DATA_PIN, CLOCK_PIN, RGB_ORDER>(r->ledsFastLed_, numLeds);
    return r;
  }

  // 3 wires.
  template <template <uint8_t DATA_PIN, EOrder RGB_ORDER> class CHIPSET, uint8_t DATA_PIN, EOrder RGB_ORDER>
  static std::unique_ptr<FastLedRenderer> Create(size_t numLeds) {
    std::unique_ptr<FastLedRenderer> r = std::unique_ptr<FastLedRenderer>(new FastLedRenderer(numLeds));
    r->ledController_ = &FastLED.addLeds<CHIPSET, DATA_PIN, RGB_ORDER>(r->ledsFastLed_, numLeds);
    return r;
  }

  void render(InputStream<Color>& colors) override {
    size_t i = 0;
    for (auto color : colors) {
      RgbaColor rgba = color.asRgba();
      ledsPlayer_[i] = CRGB(rgba.red, rgba.green, rgba.blue);
      i++;
    }
  }

  uint32_t GetPowerAtFullBrightness() const {
    return calculate_unscaled_power_mW(ledController_->leds(), ledController_->size());
  }

  void copyLedsFromPlayerToLocked() {
    freshLedLockedDataAvailable_ = true;
    memcpy(ledsLocked_, ledsPlayer_, ledMemorySize_);
  }
  bool copyLedsFromLockedToFastLed() {
    const bool freshData = freshLedLockedDataAvailable_;
    if (freshData) {
      memcpy(ledsFastLed_, ledsLocked_, ledMemorySize_);
      freshLedLockedDataAvailable_ = false;
    }
    return freshData;
  }

  void sendToLeds(uint8_t brightness = 255) { ledController_->showLeds(brightness); }

 private:
  size_t ledMemorySize_;
  CRGB* ledsPlayer_;
  bool freshLedLockedDataAvailable_ = false;
  CRGB* ledsLocked_;  // Protected by gLockedLedMutex.
  CRGB* ledsFastLed_;
  CLEDController* ledController_;
};

#if JAZZLIGHTS_ARDUINO_ETHERNET
NetworkDeviceId GetEthernetDeviceId() {
  // The W5500 chip we use doesn't come with a MAC address, so we
  // tell it to use the ESP32's Wi-Fi MAC address plus one.
  NetworkDeviceId deviceId = GetWiFiNetwork()->getLocalDeviceId();
  deviceId.data()[5]++;
  if (deviceId.data()[5] == 0) {
    deviceId.data()[4]++;
    if (deviceId.data()[4] == 0) {
      deviceId.data()[3]++;
      if (deviceId.data()[3] == 0) {
        deviceId.data()[2]++;
        if (deviceId.data()[2] == 0) {
          deviceId.data()[1]++;
          if (deviceId.data()[1] == 0) { deviceId.data()[0]++; }
        }
      }
    }
  }
  return deviceId;
}
ArduinoEthernetNetwork ethernetNetwork(GetEthernetDeviceId());
#endif  // JAZZLIGHTS_ARDUINO_ETHERNET
Player player;

std::unique_ptr<FastLedRenderer> mainVestRenderer;
std::unique_ptr<FastLedRenderer> mainVestRenderer2;

void sendLedsToFastLed() {
  bool shouldWrite;
  bool shouldWrite2 = false;
  {
    const std::lock_guard<std::mutex> lock(gLockedLedMutex);
    shouldWrite = mainVestRenderer->copyLedsFromLockedToFastLed();
    if (mainVestRenderer2) { shouldWrite2 = mainVestRenderer2->copyLedsFromLockedToFastLed(); }
  }
  SAVE_COUNT_POINT(LedPrintLoop);
  if (!shouldWrite && !shouldWrite2) { return; }

  uint32_t brightness = getBrightness();  // May be reduced if this exceeds our power budget with the current pattern

#if MAX_MILLIWATTS
  uint32_t powerAtFullBrightness = mainVestRenderer->GetPowerAtFullBrightness();
  if (mainVestRenderer2) { powerAtFullBrightness += mainVestRenderer2->GetPowerAtFullBrightness(); }
  const uint32_t powerAtDesiredBrightness =
      powerAtFullBrightness * brightness / 256;  // Forecast power at our current desired brightness
  player.powerLimited = (powerAtDesiredBrightness > MAX_MILLIWATTS);
  if (player.powerLimited) { brightness = brightness * MAX_MILLIWATTS / powerAtDesiredBrightness; }

  jll_debug("pf%6u    pd%5u    bu%4u    bs%4u    mW%5u    mA%5u%s", powerAtFullBrightness,
            powerAtDesiredBrightness,     // Full-brightness power, desired-brightness power
            getBrightness(), brightness,  // Desired and selected brightness
            powerAtFullBrightness * brightness / 256,
            powerAtFullBrightness * brightness / 256 / 5,  // Selected power & current
            player.powerLimited ? " (limited)" : "");
#endif  // MAX_MILLIWATTS
  SAVE_TIME_POINT(Brightness);

  ledWriteStart();
  SAVE_COUNT_POINT(LedPrintSend);
  if (shouldWrite) { mainVestRenderer->sendToLeds(brightness); }
  SAVE_TIME_POINT(MainLED);
  if (shouldWrite2) {
#if BRIGHTER2
    brightness += (255 - brightness) / 2;
#endif  // BRIGHTER2
    mainVestRenderer2->sendToLeds(brightness);
  }
  ledWriteEnd();
  SAVE_TIME_POINT(SecondLED);
}

TaskHandle_t gFastLedTaskHandle = nullptr;
// Index 0 is normally reserved by FreeRTOS for stream and message buffers. However, the default precompiled FreeRTOS
// kernel for arduino/esp-idf only allows a single notification, so we use index 0 here. We don't use stream or message
// buffers on this specific task so we should be fine.
constexpr UBaseType_t kFastLedNotificationIndex = 0;
static_assert(kFastLedNotificationIndex < configTASK_NOTIFICATION_ARRAY_ENTRIES, "index too high");
void fastLedTaskFunction(void* /*parameters*/) {
  while (true) {
    sendLedsToFastLed();
    // Block this task until we are notified that there is new data to write.
    (void)ulTaskGenericNotifyTake(kFastLedNotificationIndex, pdTRUE, portMAX_DELAY);
  }
}

void vestSetup(void) {
  Milliseconds currentTime = timeMillis();
  Serial.begin(115200);
#if CORE2AWS
  core2SetupStart(player, currentTime);
#else   // CORE2AWS
  setupButtons();
#endif  // CORE2AWS

#if IS_STAFF
  mainVestRenderer = std::move(FastLedRenderer::Create<WS2811, LED_PIN, RGB>(GetLayout()->pixelCount()));
#elif IS_ROPELIGHT
  mainVestRenderer = std::move(FastLedRenderer::Create<WS2812, LED_PIN, BRG>(GetLayout()->pixelCount()));
#else  // Vest.
  mainVestRenderer = std::move(FastLedRenderer::Create<WS2812B, LED_PIN, GRB>(GetLayout()->pixelCount()));
#endif
  player.addStrand(*GetLayout(), *mainVestRenderer);

  if (GetLayout2()) {
    mainVestRenderer2 = std::move(FastLedRenderer::Create<WS2812B, LED_PIN2, GRB>(GetLayout2()->pixelCount()));
    player.addStrand(*GetLayout2(), *mainVestRenderer2);
  }

#if FAIRY_WAND || IS_STAFF || IS_CAPTAIN_HAT
  player.setBasePrecedence(500);
  player.setPrecedenceGain(100);
#else
  player.setBasePrecedence(1000);
  player.setPrecedenceGain(1000);
#endif

#if ESP32_BLE
  player.connect(Esp32BleNetwork::get());
#endif  // ESP32_BLE
  player.connect(GetWiFiNetwork());
#if JAZZLIGHTS_ARDUINO_ETHERNET
  player.connect(&ethernetNetwork);
#endif  // JAZZLIGHTS_ARDUINO_ETHERNET
  player.begin(currentTime);

#if CORE2AWS
  core2SetupEnd(player, currentTime);
#endif  // CORE2AWS

  // The Arduino loop is pinned to core 1 so we pin FastLED writes to core 0.
  BaseType_t ret = xTaskCreatePinnedToCore(fastLedTaskFunction, "FastLED", configMINIMAL_STACK_SIZE + 400,
                                           /*parameters=*/nullptr,
                                           /*priority=*/30, &gFastLedTaskHandle, /*coreID=*/0);
  if (ret != pdPASS) { jll_fatal("Failed to create FastLED task"); }
}

void vestLoop(void) {
  SAVE_TIME_POINT(LoopStart);
  Milliseconds currentTime = timeMillis();
#if CORE2AWS
  core2Loop(player, currentTime);
#else  // CORE2AWS
  SAVE_TIME_POINT(Core2);
  // Read, debounce, and process the buttons, and perform actions based on button state.
  doButtons(player, *GetWiFiNetwork(),
#if ESP32_BLE
            *Esp32BleNetwork::get(),
#endif  // ESP32_BLE
            currentTime);
#endif  // CORE2AWS
  SAVE_TIME_POINT(Buttons);

#if ESP32_BLE
  Esp32BleNetwork::get()->runLoop(currentTime);
#endif  // ESP32_BLE
  SAVE_TIME_POINT(Bluetooth);

  const bool shouldRender = player.render(currentTime);
  SAVE_TIME_POINT(Player);
  if (!shouldRender) { return; }
  {
    const std::lock_guard<std::mutex> lock(gLockedLedMutex);
    mainVestRenderer->copyLedsFromPlayerToLocked();
    if (mainVestRenderer2) { mainVestRenderer2->copyLedsFromPlayerToLocked(); }
  }

  // Notify the FastLED task that there is new data to write.
  (void)xTaskGenericNotify(gFastLedTaskHandle, kFastLedNotificationIndex,
                           /*notification_value=*/0, eNoAction, /*previousNotificationValue=*/nullptr);
  vTaskDelay(1);  // Yield.
}

std::string wifiStatus(Milliseconds currentTime) { return GetWiFiNetwork()->getStatusStr(currentTime); }

std::string bleStatus(Milliseconds currentTime) {
#if ESP32_BLE
  return Esp32BleNetwork::get()->getStatusStr(currentTime);
#else   // ESP32_BLE
  return "Not supported";
#endif  // ESP32_BLE
}

std::string otherStatus(Player& player, Milliseconds currentTime) {
  char otherStatusStr[100] = "Leading";
  if (player.followedNextHopNetwork() == GetWiFiNetwork()) {
    snprintf(otherStatusStr, sizeof(otherStatusStr) - 1, "Following Wi-Fi nh=%u", player.currentNumHops());
  }
#if ESP32_BLE
  else if (player.followedNextHopNetwork() == Esp32BleNetwork::get()) {
    snprintf(otherStatusStr, sizeof(otherStatusStr) - 1, "Following BLE nh=%u", player.currentNumHops());
  }
#endif  // ESP32_BLE
  return std::string(otherStatusStr);
}

}  // namespace jazzlights

#endif  // ARDUINO
