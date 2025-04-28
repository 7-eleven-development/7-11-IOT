#include "temperatureSensor.h"
#include "config.h"

// handles logic related to the movement sensor
void readMovementSensor()
{
  pirMovementValue = analogRead(pirPin);

  Serial.print("Movement Value: ");
  Serial.println(pirMovementValue);
}