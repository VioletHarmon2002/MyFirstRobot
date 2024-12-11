#include "websocket_handler.h"
#include <WiFiClient.h>

WebSocketClient::WebSocketClient(const char* ip, uint16_t port) 
    : server_ip(ip), server_port(port) {}

bool WebSocketClient::Connect() {
  if (client.connect(server_ip, server_port)) {
    is_connected = true;
    client.println("Client connected");
    return true;
  }
  return false;
}

void WebSocketClient::Reconnect() {
  if (!is_connected) {
    Serial.print("Connecting to server...");
    if (client.connect(server_ip, server_port)) {
      Serial.println("Connected");
      is_connected = true;
      client.println("Client connected");
    } else {
      Serial.println("Connection failed");
    }
  }
}

bool WebSocketClient::IsConnected() const {
  return is_connected;
}

String WebSocketClient::ReadData() {
  String json = client.readStringUntil('\n');
  Serial.println("Received JSON: " + json);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, json);
  if (error) {
    Serial.print("JSON deserialization failed: ");
    Serial.println(error.c_str());
    return;
  }
  String command = doc["command"];
  Serial.println("Command: " + command);
  currentCommand = command;

  return command;
}

void WebSocketClient::SendData(const String& data) {
  if (is_connected) {
    client.println(data);
  }
}

void WebSocketClient::CloseConnection() {
  client.stop();
  is_connected = false;
}
