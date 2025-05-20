#ifndef ROUTER_H
#define ROUTER_H


enum SensorType {
    SENSOR_INT,
    SENSOR_FLOAT,
    SENSOR_STRING
};


// Function prototype
void sendSensorData(void* sensorValue,
                    SensorType type,
                    const char* key1,
                    const char* path,
                    const char* customHost = nullptr,   
                    const char* key2 = nullptr,         
                    const String& value2 = "",
                    const char* key3 = nullptr,         
                    const String& value3 = "");

#endif
