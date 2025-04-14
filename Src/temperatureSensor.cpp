#include "temperatureSensor.h"
#include "config.h"

void temperatureSensor()
{
  temperatureSensorValue = analogRead(temperaturePin);
  float voltage = temperatureSensorValue * (5.0 / 1023.0);
  temperatureCelsius = (voltage - 0.5) * 100.0;

  Serial.print("Temperature in Celcius: ");
  Serial.println(temperatureCelsius);
}