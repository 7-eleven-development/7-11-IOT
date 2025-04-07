#include "temperatureSensor.h"
#include "config.h"

int temperaturePin = A0; // Analog pin A0
int temperatureSensorValue = 0; // later converted into voltage
float temperatureCelsius = 0.0;


void temperatureSensor()
{
  temperatureSensorValue = analogRead(temperaturePin);
  float voltage = temperatureSensorValue * (5.0 / 1023.0); 
  temperatureCelsius = (voltage - 0.5) * 100.0;
  
  Serial.print("Temperature in Celcius: ");
  Serial.println(temperatureCelsius);
}