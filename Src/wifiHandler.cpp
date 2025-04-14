#include <Arduino.h>
#include <WiFi.h>
#include "config.h"
#include <WiFiS3.h>
#include "wifiHandler.h"


void connectToWiFi(int timeout) {
    Serial.print("Connecting to WiFi");

    int status = WL_IDLE_STATUS;
    int startAttemptTime = millis();

// keeps looping only if the elapsed time is less than the timeout, if the wifi hasnt connected
    while (status != WL_CONNECTED && millis() - startAttemptTime < timeout) {
        status = WiFi.begin(ssid, password);
        delay(1000);
        Serial.print(".");
    }

    if (status == WL_CONNECTED) {
        Serial.println("\nConnected to WiFi!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("\n WiFi not connected — continuing without connection.");
    }
}