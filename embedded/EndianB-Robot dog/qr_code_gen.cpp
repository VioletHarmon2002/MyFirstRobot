#include <WiFi.h>
#include "qrcodegen.h"

void setup() {
  Serial.begin(115200);

  delay(1000);

  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin();

  delay(100);

  String macAddress = WiFi.macAddress();

  Serial.println("MAC Address: " + macAddress);

  
  const int bufferSize = qrcodegen_BUFFER_LEN_FOR_VERSION(3);
  uint8_t qrcode[bufferSize];
  uint8_t tempBuffer[bufferSize];

  Serial.println("Generating QR code...");
  bool success = qrcodegen_encodeText(macAddress.c_str(), tempBuffer, qrcode, qrcodegen_Ecc_LOW,
                                      qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);

  if (success) {
    Serial.println("QR code generated successfully.");
    printQRCode(qrcode);
  } else {
    Serial.println("Failed to generate QR code.");
  }
}

void loop() {
}

void printQRCode(const uint8_t qrcode[]) {
  int size = qrcodegen_getSize(qrcode);
  Serial.print("QR code size: ");
  Serial.println(size);
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      Serial.print(qrcodegen_getModule(qrcode, x, y) ? "██" : "  ");
    }
    Serial.println();
  }
}