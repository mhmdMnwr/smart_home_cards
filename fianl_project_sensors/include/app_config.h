#pragma once

#include <Arduino.h>
#include <DHT.h>

namespace AppConfig {

inline constexpr char WIFI_SSID[] = "Mnwr's M14";
inline constexpr char WIFI_PASSWORD[] = "mnwrameur20044";

inline constexpr char MQTT_SERVER[] = "10.249.34.89";
inline constexpr uint16_t MQTT_PORT = 1883;
inline constexpr char MQTT_CLIENT_PREFIX[] = "WeMosClient";

inline constexpr char GAS_TOPIC[] = "smartHome/devices/mq2/gas/state";
inline constexpr char TEMPERATURE_TOPIC[] = "smartHome/devices/dht11/temperature/state";
inline constexpr char HUMIDITY_TOPIC[] = "smartHome/devices/dht11/humidity/state";
inline constexpr char FIRE_TOPIC[] = "smartHome/devices/fireSensor/fire/state";


inline constexpr uint8_t DHT_PIN = D6;
inline constexpr uint8_t MQ2_PIN = A0;
inline constexpr uint8_t FLAME_PIN = D4;
inline constexpr uint8_t DHT_TYPE = DHT11;


inline constexpr uint32_t LOOP_DELAY_MS = 3000;
inline constexpr uint32_t MQTT_RETRY_DELAY_MS = 2000;

}  // namespace AppConfig
