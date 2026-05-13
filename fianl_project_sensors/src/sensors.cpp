#include "sensors.h"

namespace Sensors {

void initSensors(DHT& dht, uint8_t mq2Pin, uint8_t flamePin) {
  dht.begin();
  pinMode(mq2Pin, INPUT);
  pinMode(flamePin, INPUT);

  Serial.println("Sensors init complete");
}

SensorReadings readSensors(DHT& dht, uint8_t mq2Pin, uint8_t flamePin) {
  SensorReadings readings{};
  readings.humidity = dht.readHumidity();
  readings.temperatureC = dht.readTemperature();
  const int mq2Reading = analogRead(mq2Pin);
  const int mq2Clamped = constrain(mq2Reading, 0, 1023);
  const int mq2Percent = map(mq2Clamped, 0, 1023, 0, 100);
  const int flameReading = digitalRead(flamePin);
  readings.mq2Raw = mq2Reading;
  readings.mq2Percent = mq2Percent;
  readings.flameValue = flameReading;
  readings.mq2Ok = mq2Reading >= 0 && mq2Reading <= 1023;
  readings.flameOk = flameReading == LOW || flameReading == HIGH;
  readings.dhtOk = !(isnan(readings.humidity) || isnan(readings.temperatureC));
  return readings;
}

void printSensorReadings(const SensorReadings& readings) {
  Serial.println("------------------------------");

  if (!readings.dhtOk) {
    Serial.println("DHT read failed");
  } else {
    Serial.print("Temperature (C): ");
    Serial.println(readings.temperatureC);
    Serial.print("Humidity (%): ");
    Serial.println(readings.humidity);
  }

  Serial.print("MQ-2: ");
  if (readings.mq2Ok) {
    Serial.print(readings.mq2Percent);
    Serial.print("% (raw ");
    Serial.print(readings.mq2Raw);
    Serial.println(")");
  } else {
    Serial.println("null");
  }

  Serial.print("Flame: ");
  if (readings.flameOk) {
    Serial.println(readings.flameValue);
  } else {
    Serial.println("null");
  }
}

}  // namespace Sensors
