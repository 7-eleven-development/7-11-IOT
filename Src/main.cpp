#include <Arduino.h>
#include "temperatureSensor.h"
#include "movementSensor.h"
#include "gasSensor.h"
#include "soundSensor.h"
#include "pulseSensor.h"
#include "config.h"

void setup()
{
  Serial.begin(9600);
  // pinMode(LED_BUILTIN, OUTPUT);
  pinMode(soundPin, INPUT);
  

  // Initialize PulseSensor
  pulseSensor.analogInput(PULSE_INPUT);
  pulseSensor.blinkOnPulse(PULSE_BLINK);
  pulseSensor.fadeOnPulse(PULSE_FADE);
  pulseSensor.setSerial(Serial);
  pulseSensor.setOutputType(OUTPUT_TYPE);
  pulseSensor.setThreshold(THRESHOLD);

  if (!pulseSensor.begin())
  {
    // PulseSensor initialization failed
    while (true)
    {
      digitalWrite(PULSE_BLINK, LOW);
      delay(50);
      Serial.println('!');
      digitalWrite(PULSE_BLINK, HIGH);
      delay(50);
    }
  }
}

void loop()
{
  // gasSensor();
  // temperatureSensor();
  // movementSensor();
  // readSoundSensor();
  pulseReading();
}
