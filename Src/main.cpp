#include <Arduino.h>
#include "temperatureSensor.h"
#include "wifiHandler.h"

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

    int temperature = readTemperatureSensor();               // Read the temperature
    sendTemperature(temperature); // Send it over WiFi
  }
}