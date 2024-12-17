#include "mac_address.h"
#include <WiFi.h>
#include <Arduino.h>


String MACAddressHelper::getMACAddress() {
    return WiFi.macAddress();
}