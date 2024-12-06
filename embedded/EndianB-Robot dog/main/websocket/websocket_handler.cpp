#include "websocket_handler.h"
#include <WiFiClient.h>

WebSocketClient::WebSocketClient(const char* ip, uint16_t port) 
    : server_ip(ip), server_port(port) {}

bool WebSocketClient::Connect() {
  if (client.connect(server_ip, server_port)) {
    isConnected = true;
    client.println("Client connected");
    return true;
  }
  return false;
}

void WebSocketClient::Reconnect() {
  if (!isConnected) {
    Serial.print("Connecting to server...");
    if (client.connect(server_ip, server_port)) {
      Serial.println("Connected");
      isConnected = true;
      client.println("Client connected");
    } else {
      Serial.println("Connection failed");
    }
  }
}

bool WebSocketClient::IsConnected() const {
  return isConnected;
}

String WebSocketClient::ReadData() {
  return client.readStringUntil('\n');
}

void WebSocketClient::SendData(const String& data) {
  if (isConnected) {
    client.println(data);
  }
}

void WebSocketClient::CloseConnection() {
  client.stop();
  isConnected = false;
}
