#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h> // this might be a bad idea

// temperature STUFF
int temperaturePin = A0; // Analog pin A0
int temperatureSensorValue = 0; // later converted into voltage
float temperatureCelsius = 0.0;

// Movement stuff
int pirPin = A1; // Analog pin A1
int pirMovementValue = 0;

// gas detection stuff
int gasPin = A2;
float gasLevel = 0; 

#endif