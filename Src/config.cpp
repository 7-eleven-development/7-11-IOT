#include <Arduino.h> // this might be a bad idea
#include <config.h>

// gas stuff
const int mq2Pin = A1;   // Pin where the analog output of the MQ-2 is connected

// Wifi part
const char* ssid = "Chas Academy"; // "Chas Academy"
const char* password = "EverythingLouderThanEverythingElse"; // "EverythingLouderThanEverythingElse"
const char* server = "192.143.0.00"; // IP or domain : use the command (ipconfig) in command terminal to find out what it is
const int port = 3001;

// sound sensor stuff
int soundPin = A3;
const int sampleWindow = 100;
unsigned int sample;


// pulse Sensor
const int OUTPUT_TYPE = SERIAL_PLOTTER; // or PROCESSING_VISUALIZER
const int PULSE_INPUT = A4;
const int PULSE_BLINK = LED_BUILTIN;
const int PULSE_FADE = 5;
const int THRESHOLD = 650;
PulseSensorPlayground pulseSensor;


// temperature sensor
int temperaturePin = A0; // Analog pin A0

// power pins
const int soundSensorPowerPin = 6;
const int temperatureSensorPowerPin = 7;
const int airSensorPowerPin = 8;