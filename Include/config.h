#ifndef CONFIG_H
#define CONFIG_H

#include "DHT.h"

// temperature STUFF
extern int temperaturePin; // Analog pin A0
#define DHTTYPE DHT11
extern DHT dht;

// Gas stuff
extern const int mq2Pin;   // Pin where the analog output of the MQ-2 is connected

// Wifi part
extern const char* ssid;
extern const char* password;
extern const char* server; // IP or domain
extern const int port;


// extern const char* path;

#endif