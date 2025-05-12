#include <Arduino.h>
#include "gasSensor.h"
#include "wifiHandler.h"
#include "config.h"
#include "router.h"
#include "soundSensor.h"
#include "pulseSensor.h"
#include "temperatureSensor.h"
#include <OffOnSwitch.h>
#include <microControllerID.h>

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
    switchSensorState();
    
    int pulseLevel = readPulseSensor();
    sendSensorData(&pulseLevel, SENSOR_INT, "pulseValue", "/api/pulse"); 

    String ID = readDeviceID();
    sendSensorData(&ID, SENSOR_STRING, "ID", "api/id");
    // Serial.println(ID);
  }
}