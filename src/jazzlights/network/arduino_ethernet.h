#ifndef JL_NETWORK_ARDUINO_ETHERNET_H
#define JL_NETWORK_ARDUINO_ETHERNET_H

#include "jazzlights/config.h"

#if JL_ETHERNET && !JL_ESP32_ETHERNET

#include <Ethernet.h>
#include <SPI.h>

#include "jazzlights/network/network.h"

namespace jazzlights {

class ArduinoEthernetNetwork : public UdpNetwork {
 public:
  static ArduinoEthernetNetwork* get();

  NetworkStatus update(NetworkStatus status, Milliseconds currentTime) override;
  int recv(void* buf, size_t bufsize, std::string* details) override;
  void send(void* buf, size_t bufsize) override;
  NetworkDeviceId getLocalDeviceId() const override { return localDeviceId_; }
  NetworkType type() const override { return NetworkType::kEthernet; }
  std::string getStatusStr(Milliseconds currentTime) override;

 private:
  explicit ArduinoEthernetNetwork();

  static NetworkDeviceId QueryLocalDeviceId();

  const NetworkDeviceId localDeviceId_ = QueryLocalDeviceId();
  uint16_t port_ = DefaultUdpPort();
  const char* mcastAddr_ = DefaultMulticastAddress();
  EthernetUDP udp_;
};

}  // namespace jazzlights

#endif  // JL_ETHERNET && !JL_ESP32_ETHERNET

#endif  // JL_NETWORK_ARDUINO_ETHERNET_H
