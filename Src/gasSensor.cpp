#include "gasSensor.h"
#include "config.h"

// handles logic related to the gas sensor
void gasSensor()
{ 
	gasLevel = analogRead(gasPin); 
	Serial.print("Gas Level: ");
	Serial.println(gasLevel);  
}