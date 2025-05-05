#ifndef ROUTER_H
#define ROUTER_H


enum SensorType {
    SENSOR_INT,
    SENSOR_FLOAT
};


// Function prototype
void sendSensorData(void* sensorValue, SensorType type, const char* key, const char* path);

#endif
