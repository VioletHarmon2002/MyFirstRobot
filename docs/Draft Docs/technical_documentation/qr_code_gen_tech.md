# Description

This code generates a QR code from the MAC address of an ESP32 device and prints it to the Serial Monitor.
The QR code is displayed using ██ for black modules and spaces for white modules. This will turn into the QR code that end users will scan to controll the robot.

## Dependencies

- `Wifi.h`: Library for WiFi functions.
- `qrcodegen.h`: Library for generating QR codes.

## Functions

`void printQRCode(const uint8_t qrcode[])`

This function prints the QR code to the Serial Monitor.

- int size = qrcodegen_getSize(qrcode): Retrieves the size of the QR code.
- Serial.print("QR code size: "): Prints the size of the QR code.
- for (int y = 0; y < size; y++): Iterates over each row of the QR code.
- for (int x = 0; x < size; x++): Iterates over each column of the QR code.
- Serial.print(qrcodegen_getModule(qrcode, x, y) ? "██" : " "): Prints ██ for black modules and spaces for white modules.

## Example output

![Example output](/docs/Embedded/assets/ex_qr_code.png)



## Source code

```c++
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
```

```c++
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
```


## Steps to generate QR Code

#### prerequisites

1. Download the zip of the qr code generator library by nayuki at this 
[link](https://github.com/nayuki/QR-Code-generator)

2. Follow these steps for the library:
- Extract the zip file
- Copy the `c` folder
- Paste the `c` folder in the `libraries` folder of Arduino IDE, usually located at `Documents/Arduino/libraries`
- Rename the `c` folder to `QRCode`
- Remove the `qrcodegen-demo` and the `qrcodegen-test` files

#### Generate QR code

1. Upload the code to your board:
- Connect your board(e.g ESP32) to your computer
- Open the Arduino IDE
- Copy and paste the code
- Upload the code to your board
2. Open the serial monitor:
- After uploading the code, open the serial monitor
- set the baud rate to `115200`
3. Generate the QR code
- The board will display a mac adress
- it will then generate a QR code from the MAC adress and print it to the serial monitor.

