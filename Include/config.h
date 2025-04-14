#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h> // this might be a bad idea
#include "../virtuabotixRTC/virtuabotixRTC.h" // Include the RTC library

// temperature STUFF
extern int temperaturePin; 
extern int temperatureSensorValue;
extern float temperatureCelsius;

// Movement stuff
extern int pirPin;
extern int pirMovementValue;

// gas detection stuff
extern int gasPin;
extern float gasLevel; 

// RTC stuff
extern virtuabotixRTC myRTC; // RTC object

#endif