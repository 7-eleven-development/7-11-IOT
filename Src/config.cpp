#include <Arduino.h> // this might be a bad idea
#include <config.h>

// gas stuff
const int mq2Pin = A1;   // Pin where the analog output of the MQ-2 is connected

// Wifi part
const char* ssid = "Chas Academy";
const char* password = "EverythingLouderThanEverythingElse";
const char* server = "10.100.2.72"; // IP or domain : use the command (ipconfig) in command terminal to find out what it is
const int port = 3001;
const char* path = "/temperature";
