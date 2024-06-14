#include <ESP32Servo.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

// WiFi and server details
const char* server_ip = "172.20.10.2";  // IP address of the server to connect to
const uint16_t server_port = 8080;      // Port number of the server to connect to

WiFiClient client;  // WiFi client object to handle the connection
bool isConnected = false;  // Boolean flag to track connection status

// Define the pins for the servos
#define SERVO_FL_PIN 18  // Front left leg servo pin
#define SERVO_RL_PIN 16  // Rear left leg servo pin
#define SERVO_FR_PIN 17  // Front right leg servo pin
#define SERVO_RR_PIN 5   // Rear right leg servo pin

// I2C pins
#define I2C_SDA 0
#define I2C_SCL 4

#define SENSOR_ID (0x68)  // I2C address of the MPU9250 sensor

// Register addresses
#define FIFO_ENABLE (0x23)
#define TEMP_OUT_H (0x41)
#define TEMP_OUT_L (0x42)

#define DEFAULT_POS 90  // Default position for all servos
#define WALK_OFFSET 30  // Offset for walking movement
#define WALK_DELAY 350  // Delay between walking steps

// Preset angles for sitting position
#define DEFAULT_FL_SIT 110
#define DEFAULT_FR_SIT 70
#define DEFAULT_RL_SIT 35
#define DEFAULT_RR_SIT 145

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

// Create servo objects for each leg
Servo FL;  // Front left leg servo
Servo FR;  // Front right leg servo
Servo RL;  // Rear left leg servo
Servo RR;  // Rear right leg servo

String currentCommand = "";  // String to store the current command

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud

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

  // Initialize I2C communication
  Wire.begin(I2C_SDA, I2C_SCL);
  writeToRegister(FIFO_ENABLE, 0b11111000);

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
  // Move legs to sitting position
  FL.write(DEFAULT_FL_SIT);
  FR.write(DEFAULT_FR_SIT);
  RL.write(DEFAULT_RL_SIT);
  RR.write(DEFAULT_RR_SIT);
}

void wave() {
  // Perform waving motion three times
  for (int i = 0; i < 3; i++) {
    Serial.print("wave");
    FL.write(WAVE_DOWN);
    delay(500);  // Delay for a visible wave
    FL.write(WAVE_UP);
    delay(500);  // Delay for a visible wave
  }
  FL.write(DEFAULT_POS);  // Return to default position
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
  // Parameters for walking forward
  // const int hopAngle = 35;  // Angle to lift the back legs
  // const int tiltAngle = 15;  // Angle to tilt the front legs
  // const int stepDelay = 500;  // Delay between steps

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

void checkForCommand() {
  static String messageBuffer;  // Buffer to store incoming messages

  // Check if the client is connected
  if (client.connected()) {
    // Read available data from the client
    while (client.available()) {
      char c = client.read();
      messageBuffer += c;
    }

    // Process the message if buffer is not empty
    if (!messageBuffer.isEmpty()) {
      Serial.println("Received message:");
      Serial.println(messageBuffer);

      // Decode the JSON message
      StaticJsonDocument<200> jsonDoc;  // JSON document to store the parsed message
      DeserializationError error = deserializeJson(jsonDoc, messageBuffer);

      // Check for JSON parsing errors
      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
      } else {
        // Extract the command from the JSON object
        const char* command = jsonDoc["command"];
        currentCommand = String(command);
      }

      messageBuffer = "";  // Clear the message buffer
    }
  }
}

void loop() {
  // Attempt to connect to the server if not connected
  if (!isConnected) {
    Serial.println("Attempting to connect to server...");
    if (client.connect(server_ip, server_port)) {
      Serial.println("Connected to server");
      isConnected = true;
    } else {
      Serial.println("Connection to server failed, retrying in 1 second...");
      delay(1000);  // Wait before retrying
    }
  }

  // If connected, check for and execute commands
  if (client.connected()) {
    checkForCommand();  // Check for new commands

    // Execute commands based on the current command
    if (currentCommand == "forward") {
      walkForward();
    } else if (currentCommand == "backward") {
      walkBackwards();
    } else if (currentCommand == "start") {
      moveToStartPosition();
      currentCommand = "";  // Clear the command after execution
    } else if (currentCommand == "lie") {
      lieDown();
      currentCommand = "";  // Clear the command after execution
    } else if (currentCommand == "sit") {
      sit();
      currentCommand = "";  // Clear the command after execution
    } else if (currentCommand == "wave") {
      wave();
      currentCommand = "";  // Clear the command after execution
    } else if (currentCommand == "right") {
      turnRight();
      currentCommand = "";  // Clear the command after execution
    } else if (currentCommand == "left") {
      turnLeft();
      currentCommand = "";  // Clear the command after execution
    } else if (currentCommand == "dance") {
      dance();
      currentCommand = "";  // Clear the command after execution
    } else if (currentCommand == "lie") {
      lieDown();
      currentCommand = ""; // Clear the command after execution
    }
  } else {
    isConnected = false;  // Update connection status
    Serial.println("Disconnected from server, attempting to reconnect...");
  }
}
