#include "wifi_manager.h"
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <Arduino.h>

WiFiManagerHelper::WiFiManagerHelper() {
}

bool WiFiManagerHelper::connectToWiFi(const char* ssid) {
    WiFiManager wifiManager;

    // Uncomment to reset Wi-Fi settings
    // wifiManager.resetSettings();

    if (!wifiManager.autoConnect(ssid)) {
        Serial.println("Failed to connect to WiFi");
        ESP.restart();  // Restart if connection fails
        return false;
    }

    Serial.println("Connected to WiFi");
    return true;
}

WiFiClient& WiFiManagerHelper::getClient() {
    return client;
}
