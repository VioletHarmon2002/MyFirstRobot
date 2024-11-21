#include "Network.h"
#include <Arduino.h>

#define SERVER_PORT 80

#define CONNECTION_NAME "RoboDog"
#define CONNECTION_PW "RoboDog"

/// @brief Initializes the networking class
void Network::Initialize() {
    _wifiManager.resetSettings();
    _wifiManager.setClass("invert");
    _wifiManager.setScanDispPerc(true);
    Serial.println("Setting up the AutoConnect on IP: " + GetLocalIP());
    _wifiManager.autoConnect(CONNECTION_NAME, CONNECTION_PW);

    _server = new ESP8266WebServer(SERVER_PORT);

    _server->on("/action", HTTP_GET, [&](AsyncWebServerRequest* request)
        {
            String command = request->getParam("command")->value();
            _commandCallback(command);
            _server->send(200, "text/plain", "action '" + command + "' executed!");
        }
    );

    _server->begin();
}

/// @brief Listens to incoming messages
void Network::Listen() {
    _server->handleClient();
}

