#include "config.h"
#include "pulseSensor.h"

int readPulseSensor()
{
    delay(20);
    pulseSensor.outputSample(); // Output current sample

    // If a beat was detected, output beat info
    if (pulseSensor.sawStartOfBeat())
    {
        return pulseSensor.getBeatsPerMinute();
    }
    return 0;
} 