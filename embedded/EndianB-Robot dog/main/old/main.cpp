#include <Arduino.h>
#include <ESP32Servo.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

#include "Face.h"
#include "movement/movement.h"
#include "wifimanager/wifi_manager.h"
#include "websocket/websocket_handler.h"

// WiFi and server details
const char *server_ip = "145.92.189.164"; // IP address of the server to connect to
const uint16_t server_port = 8080;        // Port number of the server to connect to

Movement movement(18, 16, 17, 5); // Initialize the movement object

Face Face; // Initialize the face object

WiFiManagerHelper wifiManagerHelper;              // Initialize the Wi-Fi manager helper object
bool isConnected = false;                         // Boolean flag to track connection status
WebSocketClient wsClient(server_ip, server_port); // Initialize the WebSocket client object

enum Command
{
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  SIT,
  LIE,
  WAVE,
  DANCE,
  START,
  UNKNOWN
};

// Preset angles for lying down position
#define PRESET_FL_LIE 0
#define PRESET_FR_LIE 180
#define PRESET_RL_LIE 180
#define PRESET_RR_LIE 0

// Preset angles for waving
#define WAVE_DOWN 30
#define WAVE_UP 0

// Turning presets
#define TURN_DELAY 600 // Delay between turn steps

#define TURN_RIGHT_FL 60
#define TURN_RIGHT_FR 120
#define TURN_RIGHT_RL 120
#define TURN_RIGHT_RR 60

#define TURN_LEFT_FL 120
#define TURN_LEFT_FR 60
#define TURN_LEFT_RL 60
#define TURN_LEFT_RR 120

// I2C-address of the MPU-9250 sensor
#define SENSOR_ID (0x68)

// Address of the configuraton register of the sensor
#define FIFO_ENABLE (0x23)

// Addresses of the data registers to read
#define TEMP_OUT_H (0x41)
#define TEMP_OUT_L (0x42)

#define ACCEL_XOUT_H (0x3B)
#define ACCEL_XOUT_L (0x3C)
#define ACCEL_YOUT_H (0x3D)
#define ACCEL_YOUT_L (0x3E)
#define ACCEL_ZOUT_H (0x3F)
#define ACCEL_ZOUT_L (0x40)

#define GYRO_XOUT_H (0x43)
#define GYRO_XOUT_L (0x44)
#define GYRO_YOUT_H (0x45)
#define GYRO_YOUT_L (0x46)
#define GYRO_ZOUT_H (0x47)
#define GYRO_ZOUT_L (0x48)

String currentCommand = ""; // String to store the current command

// OLED display definitions
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// I2C address of the OLED display
#define SSD1306_I2C_ADDRESS 0x3C

// Include separate bitmap header files
#include "bitmapForFace/smile_bitmap.h"
#include "bitmapForFace/frown_bitmap.h"
#include "bitmapForFace/idle_bitmap.h"

/**
 * @brief Write a value to a specific register on the MPU-9250 sensor
 *
 * @param registerAddress
 * @param value
 */
void writeToRegister(uint8_t registerAddress, uint8_t value)
{
  Wire.beginTransmission(SENSOR_ID);
  Wire.write(registerAddress);
  Wire.write(value);
  Wire.endTransmission();
}

void setup()
{
  Serial.begin(115200); // Initialize serial communication at 115200 baud

  bool face_result = face.Initialize(SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_I2C_ADDRESS);

  // Connect to Wi-Fi
  if (!wifiManagerHelper.connectToWiFi())
  {
    Serial.println("Wi-Fi connection failed");
    ESP.restart(); // Restart ESP32 if Wi-Fi connection fails
  }

  // Connect to the server
  if (!wsClient.Connect())
  {
    Serial.println("Failed to connect to the server");
    ESP.restart(); // Restart the ESP32 if connection fails
  }

  // Initialize the servos
  movement.initServos();

  delay(3000); // Wait for 3 seconds

  // TODO: Figure out where this 'Wire' comes from...
  Wire.begin(4, 15); // SDA on pin 4, SCL on pin 15

  // Initialize the MPU-9250 sensor
  writeToRegister(FIFO_ENABLE, 0b11111000);

  Face.DisplayFace(128, 64, BM_IDLE);
}

void setFace(String command)
{
  if (command == "sit" || command == "lie")
  {
    Face.DisplayFace(128, 64, BM_FROWN);
  }
  else if (command == "forward" || command == "backward" || command == "dance" || command == "dance")
  {
    Face.DisplayFace(128, 64, BM_SMILE);
  }
  else if (command == "wave")
  {
    Face.DisplayFace(128, 64, BM_IDLE);
  }
}

/**
 * @brief Read data from a specific I2C register on the MPU-9250 sensor
 *
 * @param registerAddress address of the target register
 * @return one byte of available data, otherwise 0
 */
int readFromRegister(uint8_t registerAddress)
{
  Wire.beginTransmission(SENSOR_ID);
  Wire.write(registerAddress);    // Write address of target register
  Wire.endTransmission(false);    // End transmission without closing connection
  Wire.requestFrom(SENSOR_ID, 1); // Request 1 byte

  if (Wire.available())
  {
    return Wire.read(); // Read and return the byte
  }
  else
  {
    return 0; // Return 0 if no data is available
  }
}

Command getCommand(const String &command)
{
  if (command == "forward")
    return FORWARD;
  if (command == "backward")
    return BACKWARD;
  if (command == "left")
    return LEFT;
  if (command == "right")
    return RIGHT;
  if (command == "sit")
    return SIT;
  if (command == "lie")
    return LIE;
  if (command == "wave")
    return WAVE;
  if (command == "dance")
    return DANCE;
  if (command == "start")
    return START;
  return UNKNOWN;
}

void handleCommand(String command)
{
  switch (getCommand(command))
  {
  case FORWARD:
    movement.walkForward();
    break;
  case BACKWARD:
    movement.walkBackward();
    break;
  case UNKNOWN:
    Serial.println("Unknown command");
    break;
  }
}

void loop()
{

  // Read data from the server
  if (!wsClient.IsConnected())
  {
    wsClient.Reconnect();
  }

  if (wsClient.IsConnected())
  {
    String command = wsClient.ReadData();
    setFace(command);
    handleCommand(command);
  }

  delay(10); // Small delay to avoid overwhelming the loop
}
