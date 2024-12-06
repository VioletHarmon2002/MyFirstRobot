#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFiManager.h>
#include <WiFiClient.h>

class WiFiManagerHelper {
public:
    WiFiManagerHelper();
    bool connectToWiFi(const char* ssid = "Robot Dog");
    WiFiClient& getClient();
private:
    WiFiClient client;
};

#endif  // WIFI_MANAGER_H
