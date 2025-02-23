#ifndef JL_NETWORK_ARDUINO_ESP_WIFI_H
#define JL_NETWORK_ARDUINO_ESP_WIFI_H

#include "jazzlights/config.h"

#if JL_WIFI

#include "jazzlights/network/network.h"

#ifndef JL_ESP_WIFI
#define JL_ESP_WIFI 1
#endif  // JL_ESP_WIFI

#if JL_ESP_WIFI

#include <WiFi.h>
#include <WiFiUdp.h>

namespace jazzlights {

class ArduinoEspWiFiNetwork : public UdpNetwork {
 public:
  static ArduinoEspWiFiNetwork* get();

  NetworkStatus update(NetworkStatus status, Milliseconds currentTime) override;
  int recv(void* buf, size_t bufsize, std::string* details) override;
  void send(void* buf, size_t bufsize) override;
  NetworkDeviceId getLocalDeviceId() const override { return localDeviceId_; }
  NetworkType type() const override { return NetworkType::kWiFi; }
  std::string getStatusStr(Milliseconds currentTime) override;

  struct StaticConf {
    const char* ip;
    const char* gateway;
    const char* subnetMask;
  };

 private:
  explicit ArduinoEspWiFiNetwork() {}

  static constexpr wl_status_t kUninitialized = static_cast<wl_status_t>(123);
  static std::string WiFiStatusToString(wl_status_t status);
  static NetworkDeviceId QueryLocalDeviceId();

  uint16_t port_ = DefaultUdpPort();
  const char* mcastAddr_ = DefaultMulticastAddress();
  WiFiUDP udp_;
  StaticConf* staticConf_ = nullptr;
  const NetworkDeviceId localDeviceId_ = QueryLocalDeviceId();
  wl_status_t currentWiFiStatus_ = kUninitialized;
  Milliseconds timeOfLastWiFiStatusTransition_ = -1;
  bool attemptingDhcp_ = true;
};

}  // namespace jazzlights

#endif  // JL_ESP_WIFI
#endif  // JL_WIFI
#endif  // JL_NETWORK_ARDUINO_ESP_WIFI_H
