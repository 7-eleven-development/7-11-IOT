#ifndef CONFIG_H
#define CONFIG_H


// temperature STUFF
extern int temperaturePin; // Analog pin A0
#define DHTTYPE DHT11


// Wifi part
extern const char* ssid;
extern const char* password;
extern const char* server; // IP or domain
extern const int port;
extern const char* path;

#endif