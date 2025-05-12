#ifndef OFFONSWITCH_H
#define OFFONSWITCH_H

enum Sensor {
    TEMPERATURESENSOR,
    AIRSENSOR,
    SOUNDSENSOR
};

void switchSensor(Sensor sensorType);
void turnOffSensors();
void switchSensorState();

#endif