#ifndef MAC_ADDRESS_H
#define MAC_ADDRESS_H

#include <Arduino.h>
#include <WiFi.h>

class MACAddressHelper {
public:
    // Method to get the MAC address as a string
    String getMACAddress();
};

#endif // MAC_ADDRESS_H