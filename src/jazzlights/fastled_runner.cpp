#include "jazzlights/fastled_runner.h"

#ifdef ARDUINO

#include "jazzlights/instrumentation.h"
#include "jazzlights/ui.h"
#include "jazzlights/util/log.h"

namespace jazzlights {

// Index 0 is normally reserved by FreeRTOS for stream and message buffers. However, the default precompiled FreeRTOS
// kernel for arduino/esp-idf only allows a single notification, so we use index 0 here. We don't use stream or message
// buffers on this specific task so we should be fine.
constexpr UBaseType_t kFastLedNotificationIndex = 0;
static_assert(kFastLedNotificationIndex < configTASK_NOTIFICATION_ARRAY_ENTRIES, "index too high");

void FastLedRunner::SendLedsToFastLed() {
  bool shouldWriteToAtLeastOne = false;
  std::vector<bool> shouldWrite(renderers_.size(), false);
  {
    const std::lock_guard<std::mutex> lock(lockedLedMutex_);
    for (size_t i = 0; i < renderers_.size(); i++) {
      shouldWrite[i] = renderers_[i]->copyLedsFromLockedToFastLed();
      if (shouldWrite[i]) { shouldWriteToAtLeastOne = true; }
    }
  }
  SAVE_COUNT_POINT(LedPrintLoop);
  if (!shouldWriteToAtLeastOne) { return; }

  uint32_t brightness = getBrightness();  // May be reduced if this exceeds our power budget with the current pattern

#if MAX_MILLIWATTS
  uint32_t powerAtFullBrightness = 0;
  for (auto& renderer : renderers_) { powerAtFullBrightness += renderer->GetPowerAtFullBrightness(); }
  const uint32_t powerAtDesiredBrightness =
      powerAtFullBrightness * brightness / 256;  // Forecast power at our current desired brightness
  player_->powerLimited = (powerAtDesiredBrightness > MAX_MILLIWATTS);
  if (player_->powerLimited) { brightness = brightness * MAX_MILLIWATTS / powerAtDesiredBrightness; }

  jll_debug("pf%6u    pd%5u    bu%4u    bs%4u    mW%5u    mA%5u%s", powerAtFullBrightness,
            powerAtDesiredBrightness,     // Full-brightness power, desired-brightness power
            getBrightness(), brightness,  // Desired and selected brightness
            powerAtFullBrightness * brightness / 256,
            powerAtFullBrightness * brightness / 256 / 5,  // Selected power & current
            player_->powerLimited ? " (limited)" : "");
#endif  // MAX_MILLIWATTS
  SAVE_TIME_POINT(Brightness);

  ledWriteStart();
  SAVE_COUNT_POINT(LedPrintSend);
  for (size_t i = 0; i < renderers_.size(); i++) {
    uint32_t b = brightness;
#if BRIGHTER2
    if (i > 0) { b += (255 - b) / 2; }
#endif  // BRIGHTER2
    if (shouldWrite[i]) { renderers_[i]->sendToLeds(b); }
  }
  SAVE_TIME_POINT(MainLED);
  ledWriteEnd();
}

void FastLedRunner::Render() {
  {
    const std::lock_guard<std::mutex> lock(lockedLedMutex_);
    for (auto& renderer : renderers_) { renderer->copyLedsFromPlayerToLocked(); }
  }

  // Notify the FastLED task that there is new data to write.
  (void)xTaskGenericNotify(taskHandle_, kFastLedNotificationIndex,
                           /*notification_value=*/0, eNoAction, /*previousNotificationValue=*/nullptr);
  vTaskDelay(1);  // Yield.
}

/*static*/ void FastLedRunner::TaskFunction(void* parameters) {
  FastLedRunner* runner = reinterpret_cast<FastLedRunner*>(parameters);
  while (true) {
    runner->SendLedsToFastLed();
    // Block this task until we are notified that there is new data to write.
    (void)ulTaskGenericNotifyTake(kFastLedNotificationIndex, pdTRUE, portMAX_DELAY);
  }
}

void FastLedRunner::Start() {
  // The Arduino loop is pinned to core 1 so we pin FastLED writes to core 0.
  BaseType_t ret = xTaskCreatePinnedToCore(TaskFunction, "FastLED", configMINIMAL_STACK_SIZE + 400,
                                           /*parameters=*/this,
                                           /*priority=*/30, &taskHandle_, /*coreID=*/0);
  if (ret != pdPASS) { jll_fatal("Failed to create FastLED task"); }
}

}  // namespace jazzlights

#endif  // ARDUINO
