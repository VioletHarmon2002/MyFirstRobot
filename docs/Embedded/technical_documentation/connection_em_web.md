# Documentation for Robot Network Code

## Overview
This project establishes a robot’s network connectivity and command-handling capabilities, with key components for Wi-Fi management and WebSocket communication. It uses modular classes for better separation of concerns and code readability.

---

## WebSocket Handler
The `WebSocketClient` class in **`websocket_handler.cpp`** handles WebSocket communication with a remote server.

### Key Features
- **Connect to a server**:
  - `Connect()` establishes a WebSocket connection with the server.
  - `Reconnect()` retries connecting if the connection is lost.
- **Send and receive data**:
  - `SendData(const String& data)` sends JSON data to the server.
  - `ReadData()` reads JSON data from the server, deserializing it to extract the command.
- **Connection management**:
  - `IsConnected()` checks the connection status.
  - `CloseConnection()` safely disconnects the client.

### Code Highlights
#### Constructor
```cpp
WebSocketClient::WebSocketClient(const char* ip, uint16_t port) 
    : server_ip(ip), server_port(port) {}
```
Initializes the WebSocket client with server IP and port.

#### JSON Handling in `ReadData`
```cpp
DynamicJsonDocument doc(1024);
DeserializationError error = deserializeJson(doc, json);
if (error) {
  Serial.print("JSON deserialization failed: ");
  Serial.println(error.c_str());
  return;
}
```
Parses incoming JSON strings to extract commands, while handling deserialization errors.

---

## Wi-Fi Manager
The `WiFiManagerHelper` class in **`wifi_manager.cpp`** manages Wi-Fi connectivity using the WiFiManager library.

### Key Features
- **Automatic Wi-Fi connection**:
  - `connectToWiFi(const char* ssid)` attempts to connect to a specified Wi-Fi network, retrying up to 5 times.
- **Custom callbacks**:
  - `setOnConnectionFailedCallback(std::function<void()> callback)` allows specifying a custom action for connection failures.
- **Access to Wi-Fi client**:
  - `getClient()` provides a reference to the `WiFiClient` instance for use in other modules.

### Code Highlights
#### Connection Retry Logic
```cpp
for (int attempt = 1; attempt <= maxRetries; ++attempt) {
    if (wifiManager.autoConnect(ssid)) {
        Serial.println("Connected to WiFi");
        return true;
    } else {
        Serial.printf("Connection attempt %d failed, retrying...\n", attempt);
        delay(retryDelay);
    }
}
```
This loop attempts reconnection, providing feedback on each attempt.

---

## Main Program
The main program (**`main.cpp`**) integrates Wi-Fi and WebSocket components while coordinating robot functionalities such as movement and face display.

### Wi-Fi Manager Integration
#### Connecting to Wi-Fi
```cpp
if (!wifiManagerHelper.connectToWiFi()) {
    Serial.println("Wi-Fi connection failed");
    ESP.restart();  // Restart ESP32 if Wi-Fi connection fails
}
```
Ensures the robot is connected to Wi-Fi and restarts if the connection cannot be established.

### WebSocket Handler Integration
#### Establishing Connection
```cpp
if (!wsClient.Connect()) {
    Serial.println("Failed to connect to the server");
    ESP.restart();  // Restart the ESP32 if connection fails
}
```
Connects to the server on startup and restarts if the connection fails.

#### Receiving Commands
```cpp
if (wsClient.IsConnected()) {
    String command = wsClient.ReadData();
    setFace(command);
    handleCommand(command);
}
```
Handles incoming JSON commands, updating the robot’s face and movements based on the received instructions.

---

## Dependencies
- **WiFiManager**: Simplifies Wi-Fi connection setup.
- **ArduinoJson**: Enables parsing and serialization of JSON data.
- **Wire**: Handles I2C communication for sensors and displays.
- **ESP32Servo**: Manages servo motors for movement.

---