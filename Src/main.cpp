#include <Arduino.h>
#include "temperatureSensor.h" 
#include "movementSensor.h"
#include "gasSensor.h"

#include "rtc.h"
#include "config.h" // Include the config file for global variables

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  myRTC.setDS1302Time(18, 20, 10, 1, 14, 4, 2025);
}

void loop()
{
  gasSensor();
  temperatureSensor();
  movementSensor();
  updateRTC(); // Update the RTC and print the time


}

