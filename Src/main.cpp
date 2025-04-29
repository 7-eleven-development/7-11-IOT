#include <Arduino.h>
#include "gasSensor.h"
#include "wifiHandler.h"
#include "config.h"
#include "router.h"

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
    sendSensorData(gasLevel, "gasLevel","/api/gas");                  // Send gas data over Wi-Fi
  }
}