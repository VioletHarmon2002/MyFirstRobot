#include "wifi_manager.h"
#include <WiFiManager.h>
#include <Arduino.h>

WiFiManagerHelper::WiFiManagerHelper() {
}

bool WiFiManagerHelper::connectToWiFi(const char* ssid) {
    WiFiManager wifiManager;

    const int maxRetries = 5;    // Number of retries
    const int retryDelay = 5000; // Delay between retries in milliseconds

    for (int attempt = 1; attempt <= maxRetries; ++attempt) {
        if (wifiManager.autoConnect(ssid)) {
            Serial.println("Connected to WiFi");
            return true;
        } else {
            Serial.printf("Connection attempt %d failed, retrying...\n", attempt);
            delay(retryDelay);
        }
    }

    Serial.println("Failed to connect after maximum retries.");
    return false;
}

void WiFiManagerHelper::setOnConnectionFailedCallback(std::function<void()> callback) {
    onConnectionFailedCallback = callback;
}

WiFiClient& WiFiManagerHelper::getClient() {
    return client;
}
