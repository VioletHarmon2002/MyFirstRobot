#include "mac_address.h"
#include <WiFi.h>
#include <Arduino.h>


String MACAddressHelper::getMACAddress() {
    String mac = WiFi.macAddress();  // Get the MAC address with colons
    mac.replace(":", "");           // Remove the colons
    return mac;                     // Return the MAC address without colons
}