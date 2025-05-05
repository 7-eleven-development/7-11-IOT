#include "config.h"
#include "pulseSensor.h"

void pulseReading()
{
    delay(20);
    pulseSensor.outputSample(); // Output current sample

    // If a beat was detected, output beat info
    if (pulseSensor.sawStartOfBeat())
    {
        pulseSensor.outputBeat();
    }
}