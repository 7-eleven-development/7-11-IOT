#include <Arduino.h>

int temperaturePin = A0; // Analog pin A0
int temperatureSensorValue = 0; // later converted into voltage
float temperatureCelsius = 0.0;

int pirPin = A1; // Analog pin A1
int pirMovementValue = 0;

int gasPin = A2;
float gasLevel = 0; 

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

}


// handles logic related to the temperature sensor
void temperatureSensor()
{
  temperatureSensorValue = analogRead(temperaturePin);
  float voltage = temperatureSensorValue * (5.0 / 1023.0); 
  temperatureCelsius = (voltage - 0.5) * 100.0;
  
  Serial.print("Temperature in Celcius: ");
  Serial.println(temperatureCelsius);
}


// handles logic related to the movement sensor
void movementSensor()
{
  pirMovementValue = analogRead(pirPin);
  
  Serial.print("Movement Value: ");
  Serial.println(pirMovementValue);
}

// handles logic related to the gas sensor
void gasSensor()
{ 
	gasLevel = analogRead(gasPin); 
	Serial.print("Gas Level: ");
	Serial.println(gasLevel);  
}