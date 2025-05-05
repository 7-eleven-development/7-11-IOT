#ifndef CONFIG_H
#define CONFIG_H

#include <PulseSensorPlayground.h>
#include <Arduino.h> // this might be a bad idea

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

extern const int OUTPUT_TYPE; // or PROCESSING_VISUALIZER

// PulseSensor Pin Definitions
extern const int PULSE_INPUT;
extern const int PULSE_BLINK;
extern const int PULSE_FADE;
extern const int THRESHOLD;

// --- Object ---
extern PulseSensorPlayground pulseSensor;

#endif