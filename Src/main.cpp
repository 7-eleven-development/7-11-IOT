#include <Arduino.h>
#include "temperatureSensor.h" 
#include "movementSensor.h"
#include "gasSensor.h"

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  gasSensor();
  temperatureSensor();
  movementSensor();
}

