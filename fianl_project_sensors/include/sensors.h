#pragma once

#include <Arduino.h>
#include <DHT.h>

namespace Sensors {

struct SensorReadings {
  float humidity;
  float temperatureC;
  int mq2Raw;
  int mq2Percent;
  int flameValue;
  bool mq2Ok;
  bool flameOk;
  bool dhtOk;
};

void initSensors(DHT& dht, uint8_t mq2Pin, uint8_t flamePin);
SensorReadings readSensors(DHT& dht, uint8_t mq2Pin, uint8_t flamePin);
void printSensorReadings(const SensorReadings& readings);

}  // namespace Sensors
