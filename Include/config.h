#ifndef CONFIG_H
#define CONFIG_H


#include <PulseSensorPlayground.h> // library that probably needs to be added
#include "DHT.h"

// temperature STUFF
extern int temperaturePin; // Analog pin A0
#define DHTTYPE DHT11

// Gas stuff
extern const int mq2Pin;   // Pin where the analog output of the MQ-2 is connected

// Wifi part
extern const char* ssid;
extern const char* password;
extern const char* server; // IP or domain
extern const int port;


// sound sensor stuff
extern int soundPin;
extern const int sampleWindow;
extern unsigned int sample;


// pulse Sensor
extern const int OUTPUT_TYPE; // or PROCESSING_VISUALIZER

// PulseSensor Pin Definitions
extern const int PULSE_INPUT;
extern const int PULSE_BLINK;
extern const int PULSE_FADE;
extern const int THRESHOLD;

// --- Object ---
extern PulseSensorPlayground pulseSensor;

#endif