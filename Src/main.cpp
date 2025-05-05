#include <Arduino.h>
#include "gasSensor.h"
#include "wifiHandler.h"
#include "config.h"
#include "router.h"
#include "soundSensor.h"
#include "pulseSensor.h"
#include "temperatureSensor.h"

unsigned long lastSendTime = 0;
const unsigned long sendInterval = 5000; // 5 seconds

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  connectToWiFi(10000); // connect once at boot
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastSendTime >= sendInterval) {
    lastSendTime = currentTime;

    int gasLevel = readGasSensor();           // Read the gas sensor value
    sendSensorData(&gasLevel, SENSOR_INT, "gasValue","/api/airQuality");                  // Send gas data over Wi-Fi

    float soundLevel = readSoundSensor();
    // worth mentioning its int, string, string: so the float dissapears, mabye refactor the int to be a void pointer instead, that way it can accept any input;
    sendSensorData(&soundLevel, SENSOR_FLOAT, "gasValue", "/api/airQuality"); 

    int pulseLevel = readPulseSensor();
    sendSensorData(&pulseLevel, SENSOR_INT, "gasValue", "/api/airQuality"); 

    int temperatureLevel = readPulseSensor();
    sendSensorData(&temperatureLevel, SENSOR_INT, "gasValue", "/api/airQuality"); 

  }
}