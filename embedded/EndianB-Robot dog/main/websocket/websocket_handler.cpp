#include "websocket_handler.h"
#include "mac_address/mac_address.h"
#include <ArduinoJson.h>

// Instantiate the MACAddressHelper class
MACAddressHelper macAddressHelper;

WebSocketClient::WebSocketClient(const char* ip, uint16_t port)
  : server_ip(ip), server_port(port) {}

bool WebSocketClient::Connect()
{
  if (client.connect(server_ip, server_port))
  {
    is_connected = true;
    client.println("Client connected");
    return true;
  }
  return false;
}

void WebSocketClient::Reconnect() {
  if (!client.connected()) {
    Serial.print("Connecting to server ");
    Serial.print(server_ip);
    Serial.print(":");
    Serial.println(server_port);
    if (client.connect(server_ip, server_port)) {
      is_connected = true;
      client.println("Client connected");
      Serial.println("Connection successful");
    } else {
      is_connected = false;
      Serial.println("Connection failed");
    }
  }
}

bool WebSocketClient::IsConnected() const {
    return is_connected;
}

String WebSocketClient::ReadData() {
  // Get and print the MAC address
  String macAddress = macAddressHelper.getMACAddress();
  if (client.available()) {
    String json = client.readStringUntil('\n');  // Read the incoming JSON data
    Serial.println("Received JSON: " + json);

    // Parse the JSON data
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, json);

    if (error) {
      Serial.print("JSON deserialization failed: ");
      Serial.println(error.c_str());
      return "";  // Return an empty string on error
    }

    // Extract the command from the JSON
    String command = doc["command"];
    Serial.println("Command: " + command);
    String robotId = doc["robotId"];
    Serial.println("Robot ID: " + robotId);

    if(robotId != macAddress) {
      Serial.println("Robot ID does not match");
      Serial.println("Expected: " + macAddress);
      Serial.println("Received: " + robotId);
      return "";  // Return an empty string if the robot ID does not match
    }
    
    // Return the command
    return command;
  }
  return "";  // Return an empty string if no data is available
}

void WebSocketClient::SendData(const String &data)
{
  if (is_connected)
  {
    client.println(data);
  }
}

void WebSocketClient::CloseConnection()
{
  client.stop();
  is_connected = false;
}