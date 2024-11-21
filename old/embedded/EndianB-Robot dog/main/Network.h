#include <FS.h>                // For file system access (same for ESP32)
#include <WiFi.h>              // WiFi library for ESP32
#include <WebServer.h>         // Web server for ESP32 (replaces ESP8266WebServer)
#include <HTTPClient.h>        // HTTP client for ESP32 (replaces ESP8266HTTPClient)
#include <DNSServer.h>         // DNS server (same for ESP32)
#include <WiFiManager.h>       // WiFiManager (make sure you have the ESP32-compatible version)
#include <ArduinoJson.h>       // JSON parsing (same for ESP32)
#include <functional>          // Standard C++ function support

typedef std::function<void(String)> CommandCallback;

/// @brief Networking class responsible for establishing an internet connection, sending requests and listening for messages.
class Network {
public:
    void Initialize();
    void Listen();
    String GetNetworkName() { return _wifiManager.getWiFiSSID(); }
    String GetLocalIP() { return WiFi.localIP().toString(); }

    void SetCommandCallback(CommandCallback callback) { _commandCallback = callback; };

private:
    CommandCallback _commandCallback;
    WiFiManager _wifiManager;
    ESP8266WebServer* _server;
};