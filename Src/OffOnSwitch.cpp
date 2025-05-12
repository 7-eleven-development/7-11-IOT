#include <Arduino.h>
#include "gasSensor.h"
#include "wifiHandler.h"
#include "config.h"
#include "router.h"
#include "soundSensor.h"
#include "pulseSensor.h"
#include "temperatureSensor.h"
#include <OffOnSwitch.h>


void switchSensor(Sensor sensorType)
{
    switch (sensorType) 
    {
    case TEMPERATURESENSOR: 
    {
        digitalWrite(temperatureSensorPowerPin, HIGH);
        int temperatureLevel = readTemperatureSensor();
        Serial.println("Temperature Sensor State Reached");
        Serial.println(temperatureLevel);
        sendSensorData(&temperatureLevel, SENSOR_INT, "temperatureValue", "/api/temp");
        break;
    }
    case AIRSENSOR: 
    {
        digitalWrite(airSensorPowerPin, HIGH);
        int gasLevel = readGasSensor();           // Read the gas sensor value
        Serial.println("gas Sensor State Reached");
        Serial.println(gasLevel);
        sendSensorData(&gasLevel, SENSOR_INT, "gasValue","/api/airQuality");                 // Send gas data over Wi-Fi
        break;
    }
    case SOUNDSENSOR: 
    {
        digitalWrite(soundSensorPowerPin, HIGH);
        float soundLevel = readSoundSensor();
        Serial.println("sound Sensor State Reached");
        Serial.println(soundLevel);
        sendSensorData(&soundLevel, SENSOR_FLOAT, "soundValue", "/api/sound"); 
        break;
    }
    default:
        Serial.println("Unsupported sensor");
        break;
    }
}


void turnOffSensors()
{
    digitalWrite(temperatureSensorPowerPin, LOW);
    digitalWrite(airSensorPowerPin, LOW);
    digitalWrite(soundSensorPowerPin, LOW);
}

int stateSensorCounter = 0; // global variable

void switchSensorState()
{
    turnOffSensors();
    if(stateSensorCounter == 0)
    {
        switchSensor(TEMPERATURESENSOR);
        stateSensorCounter++;
    } 
    else if(stateSensorCounter == 1)
    {
        switchSensor(AIRSENSOR);
        stateSensorCounter++;
    }
    else if(stateSensorCounter == 2)
    {
        switchSensor(SOUNDSENSOR);
        stateSensorCounter++;
    }
    else if(stateSensorCounter == 3)
    {
        // resets the counter
        stateSensorCounter = 0;
    }
}
