#include "temperatureSensor.h"
#include "DHT.h"
#include "config.h"
#include <WiFiS3.h>

DHT dht(temperaturePin, DHTTYPE);

float temperatureCelsius = 0.0;

void temperatureSensor()
{
  temperatureCelsius = dht.readTemperature();

  if (isnan(temperatureCelsius)) {
    Serial.println("Failed to read temperature from DHT11 sensor!");
  } else {
    Serial.print("Temperature in Celsius: ");
    Serial.println(temperatureCelsius);
  }
}

// may want to rework this code eventually as we send in more data and controll it globally at one place
// Assumes the code is sent through HTTP, and sends it in JSON
void sendTemperature(float temp)
{
  WiFiClient client;


  if(client.connect(server, port))
  {
    String json = "{\"temperature\": " + String(temp, 1) + "}"; 

    client.println("POST " + String(path) + " HTTP/1.1");
    client.println("Host: " + String(server));
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(json.length());
    client.println();  // End of header
    client.println(json);  // Send the actual JSON data
    Serial.println(" Sent: " + json);

    while(client.connected())
    {
        String line = client.readStringUntil('\n');
        if(line == "\r") break;
    }

    while(client.available())
    {
      String line = client.readStringUntil('\n');
      Serial.println(line); // prints a response from backend
    }

    client.stop();
  }
  else
  {
    Serial.println(" Failed to connect to backend.");
  }
}