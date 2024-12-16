#ifndef WEBSOCKET_HANDLER_H
#define WEBSOCKET_HANDLER_H

#include <WiFiClient.h>

class WebSocketClient {
 public:
  WebSocketClient(const char* ip, uint16_t port);
  bool Connect();
  void Reconnect();
  bool IsConnected() const;
  String ReadData();
  void SendData(const String& data);
  void CloseConnection();

 private:
  const char* server_ip;
  uint16_t server_port;
  WiFiClient client;
  bool is_connected = false;
};

#endif  // WEBSOCKET_HANDLER_H
