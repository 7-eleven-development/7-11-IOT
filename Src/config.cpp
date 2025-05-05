
#include "config.h"

// temperature STUFF
int temperaturePin = A0;
int temperatureSensorValue = 0;
float temperatureCelsius = 0.0;

// Movement stuff
int pirPin = A1;
int pirMovementValue = 0;

// gas detection stuff
int gasPin = A2;
float gasLevel = 0.0;

// sound sensor stuff
int soundPin = A3;
const int sampleWindow = 100;
unsigned int sample;

const int OUTPUT_TYPE = SERIAL_PLOTTER; // or PROCESSING_VISUALIZER

// PulseSensor Pin Definitions
const int PULSE_INPUT = A4;
const int PULSE_BLINK = LED_BUILTIN;
const int PULSE_FADE = 5;
const int THRESHOLD = 650;

// --- Object ---
PulseSensorPlayground pulseSensor;
