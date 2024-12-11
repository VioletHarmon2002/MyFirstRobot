#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFiManager.h>
#include <WiFiClient.h>
#include <functional>

class WiFiManagerHelper {
public:
    WiFiManagerHelper();
    
    // Method to connect to Wi-Fi
    bool connectToWiFi(const char* ssid = "ESPWifi");

    // Method to set the callback for connection failure
    void setOnConnectionFailedCallback(std::function<void()> callback);

    // Get the WiFiClient instance
    WiFiClient& getClient();

private:
    WiFiClient client;
    std::function<void()> onConnectionFailedCallback;  // Callback for connection failure
};

#endif  // WIFI_MANAGER_H
