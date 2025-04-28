#include <Arduino.h> // this might be a bad idea
#include <config.h>

// temperature STUFF
int temperaturePin = 2; // Analog pin A0
DHT dht(temperaturePin, DHTTYPE);

// Wifi part
const char* ssid = "Chas Academy";
const char* password = "EverythingLouderThanEverythingElse";
const char* server = "10.100.2.48"; // IP or domain
const int port = 3000;
const char* path = "/temperature";
