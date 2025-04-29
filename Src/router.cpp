#include "config.h"
#include "router.h"
#include <WiFiNINA.h> 


// Cannot currently connect to an URL, will later need to be refactored when that is relevant
// connect the URL through a get request from backend.

void sendSensorData(int sensorValue, const char* key, const char* path)
{
  WiFiClient client;
  

  if(client.connect(server, port)) {
    String json = "{\"" + String(key) + "\": " + String(sensorValue) + "}"; // Send gas data in JSON format

    client.println("POST " + String(path) + " HTTP/1.1");
    client.println("Host: " + String(server));
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(json.length());
    client.println();  // End of header
    client.println(json);  // Send the actual JSON data


    Serial.println("Sent to " + String(path) + ": " + json);


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
