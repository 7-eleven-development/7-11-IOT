#include "gasSensor.h"  
#include "config.h"
#include <WiFiNINA.h> 


// Function to read the gas sensor
int readGasSensor()
{
  int gasLevel = analogRead(mq2Pin);  
  Serial.println("Reading gas concentration...");
  

  if (gasLevel > 100) {  // 100 is just an example threshold
    Serial.print("Gas concentration detected: ");
    Serial.println(gasLevel);
  } else {
    Serial.println("No significant gas detected.");
  }
  
  return gasLevel;
}

// Function to send the gas data to the server in JSON format
void sendGasData(int gasLevel)
{
  WiFiClient client;


  if(client.connect(server, port)) {
    String json = "{\"gasLevel\": " + String(gasLevel) + "}"; // Send gas data in JSON format

    client.println("POST " + String(path) + " HTTP/1.1");
    client.println("Host: " + String(server));
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(json.length());
    client.println();  // End of header
    client.println(json);  // Send the actual JSON data
    Serial.println("Sent: " + json);

    while(client.connected()) {
        String line = client.readStringUntil('\n');
        if(line == "\r") break;
    }

    while(client.available()) {
      String line = client.readStringUntil('\n');
      Serial.println(line); // prints a response from backend
    }

    client.stop();
  }
  else {
    Serial.println("Failed to connect to backend.");
    Serial.print("Server IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("Port: ");
    Serial.println(port);
  }
}
