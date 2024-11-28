#include <ESP32Servo.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Face.h"

// WiFi and server details
const char* server_ip = "172.20.10.2";  // IP address of the server to connect to
const uint16_t server_port = 8080;      // Port number of the server to connect to

WiFiClient client;  // WiFi client object to handle the connection
bool isConnected = false;  // Boolean flag to track connection status

enum Command {
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

// Define the pins for the servos
#define SERVO_FL_PIN 18  // Front left leg servo pin
#define SERVO_RL_PIN 16  // Rear left leg servo pin
#define SERVO_FR_PIN 17  // Front right leg servo pin
#define SERVO_RR_PIN 5   // Rear right leg servo pin

#define DEFAULT_POS 90  // Default position for all servos
#define WALK_OFFSET 30  // Offset for walking movement
#define WALK_DELAY 350  // Delay between walking steps


// Preset angles for lying down position
#define PRESET_FL_LIE 0
#define PRESET_FR_LIE 180
#define PRESET_RL_LIE 180
#define PRESET_RR_LIE 0

// Preset angles for waving
#define WAVE_DOWN 30
#define WAVE_UP 0

// Turning presets
#define TURN_DELAY 600  // Delay between turn steps

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

// Create servo objects for each leg
Servo FL;  // Front left leg servo
Servo FR;  // Front right leg servo
Servo RL;  // Rear left leg servo
Servo RR;  // Rear right leg servo

String currentCommand = "";  // String to store the current command

// OLED display definitions
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// I2C address of the OLED display
#define SSD1306_I2C_ADDRESS 0x3C

// Include separate bitmap header files
#include "bitmapForFace/smile_bitmap.h"
#include "bitmapForFace/frown_bitmap.h"
#include "bitmapForFace/idle_bitmap.h"

Face face;

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud

  bool result = face.Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);
  if (!result)
      Serial.println("Failed to initialize the display");

  // Initialize WiFiManager to manage WiFi connections
  WiFiManager wifiManager;

  // Uncomment the line below if you want to reset WiFi settings
  // wifiManager.resetSettings();

  // Start WiFiManager and attempt to connect to WiFi
  if (!wifiManager.autoConnect("Robot Dog")) {
    Serial.println("Failed to connect to WiFi");
    ESP.restart();  // Restart the ESP32 if connection fails
  }
  Serial.println("Connected to WiFi");

  // Attach servos to their respective pins
  FL.attach(SERVO_FL_PIN);
  FR.attach(SERVO_FR_PIN);
  RL.attach(SERVO_RL_PIN);
  RR.attach(SERVO_RR_PIN);

  // Move servos to their initial positions
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);

  delay(3000);  // Wait for 3 seconds

  // TODO: Figure out where this 'Wire' comes from...
  Wire.begin(4, 15); // SDA on pin 4, SCL on pin 15

  // Initialize the MPU-9250 sensor
  writeToRegister(FIFO_ENABLE, 0b11111000);

  face.DisplayFace(128, 64, BM_SMILE);
}

void setFace(String command) {
  if (command == "sit" || command == "lie") {
    displayEmote(idle_bitmap, idle_width, idle_height);
  } else if (command == "forward" || command == "backward" || command == "dance" || command == "dance") {
    displayEmote(BM_SMILE, smile_width, smile_height);
  } else if (command == "wave") {
    displayEmote(frown_bitmap, frown_width, frown_height);
  }
}

/**
 * @brief Write a value to a specific register on the MPU-9250 sensor
 * 
 * @param registerAddress 
 * @param value 
 */
void writeToRegister(uint8_t registerAddress, uint8_t value) {
  Wire.beginTransmission(SENSOR_ID);
  Wire.write(registerAddress);
  Wire.write(value);
  Wire.endTransmission();
}

/**
 * @brief Read data from a specific I2C register on the MPU-9250 sensor
 * 
 * @param registerAddress address of the target register
 * @return one byte of available data, otherwise 0
 */
int readFromRegister(uint8_t registerAddress) {
  Wire.beginTransmission(SENSOR_ID);
  Wire.write(registerAddress); // Write address of target register
  Wire.endTransmission(false); // End transmission without closing connection
  Wire.requestFrom(SENSOR_ID, 1); // Request 1 byte

  if (Wire.available()) {
    return Wire.read(); // Read and return the byte
  } else {
    return 0; // Return 0 if no data is available
  }
}

void dance() {
  // Define dance movement parameters
  const int forwardAngle = 40;  // Angle to move the leg forward
  const int backwardAngle = 40;  // Angle to move the leg backward
  const int sideShiftAngle = 10;  // Angle to shift the robot's weight to one side
  const int stepDelay = 300;  // Delay between steps in milliseconds

  unsigned long startTime = millis();  // Record the start time of the dance

  // Dance for 10 seconds or until a new command is received
  while (currentCommand == "dance" && millis() - startTime < 10000) {
    // Step 1: Shift weight to the right
    FL.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);

    // Lift front left leg and rear right leg, and move them forward/backward respectively
    FL.write(DEFAULT_POS - forwardAngle);
    RR.write(DEFAULT_POS + backwardAngle);
    delay(stepDelay);

    // Lower the legs
    FL.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS);
    delay(stepDelay);

    // Return weight to center
    FL.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    delay(stepDelay);

    // Step 2: Shift weight to the left
    FR.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);

    // Lift front right leg and rear left leg, and move them forward/backward respectively
    FR.write(DEFAULT_POS - forwardAngle);
    RL.write(DEFAULT_POS + backwardAngle);
    delay(stepDelay);

    // Lower the legs
    FR.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS);
    delay(stepDelay);

    // Return weight to center
    FR.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(stepDelay);

    // Step 3: Shift weight to the right
    FL.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);

    // Lift front left leg and rear right leg, and move them backward/forward respectively
    FL.write(DEFAULT_POS + backwardAngle);
    RR.write(DEFAULT_POS - forwardAngle);
    delay(stepDelay);

    // Lower the legs
    FL.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS);
    delay(stepDelay);

    // Return weight to center
    FL.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    delay(stepDelay);

    // Step 4: Shift weight to the left
    FR.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);

    // Lift front right leg and rear left leg, and move them backward/forward respectively
    FR.write(DEFAULT_POS + backwardAngle);
    RL.write(DEFAULT_POS - forwardAngle);
    delay(stepDelay);

    // Lower the legs
    FR.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS);
    delay(stepDelay);

    // Return weight to center
    FR.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(stepDelay);
  }

  // Stop the movement and return all legs to the default position
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
}

void moveToStartPosition() {
  // Move servos from 0 to 180 degrees in steps of 5
  for (int angle = 0; angle <= 180; angle += 5) {
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(50);
  }
}

void lieDown() {
  Serial.println("Lying down");
  // Move legs to lying down position
  FL.write(PRESET_FL_LIE);
  FR.write(PRESET_FR_LIE);
  RL.write(PRESET_RL_LIE);
  RR.write(PRESET_RR_LIE);
}

void sit() {
  Serial.println("Sitting down");
  int sitPosition[] = {110, 70, 35, 145}
  // Move legs to sitting position
   FL.write(sitPosition[0]);
   FR.write(sitPosition[1]);
   RL.write(sitPosition[2]);
   RR.write(sitPosition[3]);
}

void wave() {
  // Perform waving motion three times
  for (int i = 0; i < 3; i++) {
    Serial.println("Waving");
    FL.write(WAVE_UP);
    delay(500);
    FL.write(WAVE_DOWN);
    delay(500);
  }
  FL.write(DEFAULT_POS); // Return the leg to the default position after waving
}

void leftStep() {
  FR.write(90);
  delay(100);
  FL.write(60);
  delay(300);
  RL.write(110);
  delay(100);
  RR.write(120);
}

void rightStep() {
  FL.write(90);
  delay(100);
  FR.write(120);
  delay(300);
  RR.write(70);
  delay(100);
  RL.write(60);
}

void walkForward() {
  unsigned long startTime = millis();  // Record start time

  // Walk forward for 5 seconds
  while (millis() - startTime < 5000) {
    leftStep();
    delay(300);
    rightStep();
    delay(300);
  }

  // Stop the movement
  FR.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  FL.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
}

void walkBackwards() {
  // Parameters for walking backwards
  const int hopAngle = 35;  // Angle to lift the back legs
  const int tiltAngle = 15;  // Angle to tilt the front legs
  const int stepDelay = 500;  // Delay between steps

  unsigned long startTime = millis();  // Record start time

  // Walk backwards for 5 seconds
  while (millis() - startTime < 5000) {
    // Lift and extend back legs, and tilt front legs
    RL.write(DEFAULT_POS + tiltAngle);
    RR.write(DEFAULT_POS - tiltAngle);
    FR.write(DEFAULT_POS - tiltAngle);
    FL.write(DEFAULT_POS + tiltAngle);
    FR.write(DEFAULT_POS - hopAngle);
    FL.write(DEFAULT_POS + hopAngle);
    delay(stepDelay);

    // Lower back legs and return front legs to default position
    FR.write(DEFAULT_POS);
    FL.write(DEFAULT_POS);
    delay(stepDelay);
  }

  // Stop the movement
  FR.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  FL.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
}

void turnRight() {
  Serial.println("Turning right");
  unsigned long startTime = millis();  // Record start time

  // Turn right for 5 seconds
  while (millis() - startTime < 5000) {
    // Adjust the servo positions for turning right
    FL.write(TURN_RIGHT_FL);
    FR.write(TURN_RIGHT_FR);
    RL.write(TURN_RIGHT_RL);
    RR.write(TURN_RIGHT_RR);
    delay(TURN_DELAY);

    // Move back to the default position smoothly
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(TURN_DELAY);
  }

  // Ensure all servos return to default position at the end of the turn
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  delay(WALK_DELAY);
}

void turnLeft() {
  Serial.println("Turning left");
  unsigned long startTime = millis();  // Record start time

  // Turn left for 5 seconds
  while (millis() - startTime < 5000) {
    // Adjust the servo positions for turning left
    FL.write(TURN_LEFT_FL);
    FR.write(TURN_LEFT_FR);
    RL.write(TURN_LEFT_RL);
    RR.write(TURN_LEFT_RR);
    delay(TURN_DELAY);

    // Move back to the default position smoothly
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(TURN_DELAY);
  }

  // Ensure all servos return to default position at the end of the turn
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  delay(WALK_DELAY);
}

Command getCommand(const String& command) {
  switch(command) {
    case "forward":
      return FORWARD;
    case "backward":
      return BACKWARD;
    case "left":
      return LEFT;
    case "right":
      return RIGHT;
    case "sit":
      return SIT;
    case "lie":
      return LIE;
    case "wave":
      return WAVE;
    case "dance":
      return DANCE;
    case "start":
      return START;
    default:
      return UNKNOWN;
  }
}

void handleCommand(String command) {
  switch (getCommand(command)) {
    case FORWARD:
      walkForward();
      break;
    case BACKWARD:
      walkBackwards();
      break;
    case LEFT:
      turnLeft();
      break;
    case RIGHT:
      turnRight();
      break;
    case SIT:
      sit();
      break;
    case LIE:
      lieDown();
      break;
    case WAVE:
      wave();
      break;
    case DANCE:
      dance();
      break;
    case START:
      moveToStartPosition();
      break;
    case UNKNOWN:
      Serial.println("Unknown command");
      break;
  }
}

void loop() {
  // Attempt to connect to the server if not already connected
  if (!isConnected) {
    Serial.print("Connecting to server...");
    if (client.connect(server_ip, server_port)) {
      Serial.println("Connected");
      isConnected = true;
      client.println("Client connected");
    } else {
      Serial.println("Connection failed");
      delay(5000);  // Retry every 5 seconds if connection fails
    }
  }

  // Check for incoming data from the server
  if (client.available()) {
    String json = client.readStringUntil('\n');  // Read the incoming JSON data
    Serial.println("Received JSON: " + json);

    // Parse the JSON data
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, json);
    if (error) {
      Serial.print("JSON deserialization failed: ");
      Serial.println(error.c_str());
      return;
    }

    // Extract the command from the JSON
    String command = doc["command"];
    Serial.println("Command: " + command);

    // Update the current command
    currentCommand = command;

    // Set the face expression based on the command
    setFace(command);

    // Execute the command
    handleCommand(command);
  }

  // Reconnect to the server if the connection is lost
  if (!client.connected()) {
    Serial.println("Disconnected from server");
    isConnected = false;
  }

  delay(10);  // Small delay to avoid overwhelming the loop
}
