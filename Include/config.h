#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h> // this might be a bad idea
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// temperature STUFF
extern int temperaturePin;         // Analog pin A0
extern int temperatureSensorValue; // later converted into voltage
extern float temperatureCelsius;

// Movement stuff
extern int pirPin; // Analog pin A1
extern int pirMovementValue;

// gas detection stuff
extern int gasPin;
extern float gasLevel;

// sound sensor stuff
extern int soundPin;
extern const int sampleWindow;
extern unsigned int sample;

// GPS stuff
extern const int RXPin; // Serial RX pin
extern const int TXPin; // Serial TX pin
extern const uint32_t GPSBaud; // Baud rate for GPS module
extern TinyGPSPlus gps; // TinyGPSPlus object
extern SoftwareSerial ss; // SoftwareSerial object for GPS communication

#endif