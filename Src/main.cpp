#include <Arduino.h>
#include "temperatureSensor.h"
#include "movementSensor.h"
#include "gasSensor.h"
#include "config.h"

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(gasPin, INPUT);
}

void loop()
{
  gasSensor();
  // temperatureSensor();
  // movementSensor();
}
