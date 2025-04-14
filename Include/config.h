#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h> // this might be a bad idea

// temperature STUFF
int temperaturePin = A0; // Analog pin A0
#define DHTTYPE DHT11

// Movement stuff
int pirPin = A1; // Analog pin A1
int pirMovementValue = 0;

// gas detection stuff
int gasPin = A2;
float gasLevel = 0; 


// Wifi part
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* server = "192.168.1.100"; // IP or domain
const int port = 3000;
const char* path = "/temperature";

#endif