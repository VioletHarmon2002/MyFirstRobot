#include <ESP32Servo.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

// WiFi and server details
const char* server_ip = "172.20.10.5"; // IP address of the server
const uint16_t server_port = 1234; // Port number of the server

WiFiClient client; // WiFi client for connecting to the server
bool isConnected = false; // Connection status flag

// Define the pins for the servos
#define SERVO_FL_PIN 4 // Front left servo pin
#define SERVO_RL_PIN 16 // Rear left servo pin
#define SERVO_FR_PIN 17 // Front right servo pin
#define SERVO_RR_PIN 5 // Rear right servo pin

#define DEFAULT_POS 90 // Default servo position (middle)
#define WALK_OFFSET 30 // Offset for walking motion
#define WALK_DELAY 350 // Delay between steps

// Create servo objects
Servo FL; // Front left leg servo
Servo FR; // Front right leg servo
Servo RL; // Rear left leg servo
Servo RR; // Rear right leg servo

String currentCommand = ""; // Current command from the server

void setup() {
  Serial.begin(115200); // Start serial communication at 115200 baud rate

  // Initialize WiFiManager
  WiFiManager wifiManager;

  // Uncomment the line below if you want to reset WiFi settings
  // wifiManager.resetSettings();

  // Start WiFiManager and connect to WiFi
  if (!wifiManager.autoConnect("Robot Dog")) {
    Serial.println("Failed to connect to WiFi");
    ESP.restart(); // Restart the board if WiFi connection fails
  }
  Serial.println("Connected to WiFi");

  // Attach servos to pins
  FL.attach(SERVO_FL_PIN);
  FR.attach(SERVO_FR_PIN);
  RL.attach(SERVO_RL_PIN);
  RR.attach(SERVO_RR_PIN);

  // Move servos to the default position
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);

  delay(3000); // Wait for 3 seconds
}

// Function to make the robot walk forward
void walkForward() {
  unsigned long startTime = millis(); // Record the start time

  while (currentCommand == "forward" && millis() - startTime < 5000) { // Continue for 5 seconds
    RL.write(DEFAULT_POS + WALK_OFFSET); // Move rear left leg
    delay(100); // Short delay
    FL.write(DEFAULT_POS - WALK_OFFSET); // Move front left leg

    FR.write(DEFAULT_POS - WALK_OFFSET); // Move front right leg
    delay(100); // Short delay
    RR.write(DEFAULT_POS + WALK_OFFSET); // Move rear right leg

    delay(WALK_DELAY); // Delay for the step

    FL.write(DEFAULT_POS + WALK_OFFSET); // Move front left leg back
    delay(100); // Short delay
    RL.write(DEFAULT_POS - WALK_OFFSET); // Move rear left leg back

    RR.write(DEFAULT_POS - WALK_OFFSET); // Move rear right leg back
    delay(100); // Short delay
    FR.write(DEFAULT_POS + WALK_OFFSET); // Move front right leg back

    delay(WALK_DELAY); // Delay for the step
  }

  // Stop the movement by resetting servo positions
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
}

// Function to move servos to the start position
void moveToStartPosition() {
  for (int angle = 0; angle <= 180; angle += 5) {
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(50); // Short delay for smooth movement
  }
}

// Function to move servos to the docking position
void moveToDockingPosition() {
  for (int angle = 180; angle >= 0; angle -= 5) {
    FL.write(angle);
    FR.write(angle);
    RL.write(angle);
    RR.write(angle);
    delay(50); // Short delay for smooth movement
  }
}

// Function to make the robot sit
void sit() {
  Serial.println("Sitting down");
  FL.write(110); // Move front left leg to standing position
  FR.write(70);  // Move front right leg to standing position
  RL.write(170); // Move rear left leg to sitting position
  RR.write(10);  // Move rear right leg to sitting position
}

void lieDown() {
  Serial.println("Lying down");
  FL.write(0); // Move front left leg to lying position
  FR.write(180); // Move front right leg to lying position
  RL.write(180); // Move rear left leg to lying position
  RR.write(0); // Move rear right leg to lying position
}

// Function to check for new commands from the server
void checkForCommand() {
  static String messageBuffer; // Buffer to store the incoming message

  if (client.connected()) {
    while (client.available()) {
      char c = client.read(); // Read each character from the server
      messageBuffer += c; // Add character to the message buffer
    }

    if (!messageBuffer.isEmpty()) {
      // Print the received message
      Serial.println("Received message:");
      Serial.println(messageBuffer);

      // Decode the JSON message
      StaticJsonDocument<200> jsonDoc; // JSON document to hold the decoded message
      DeserializationError error = deserializeJson(jsonDoc, messageBuffer);

      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
      } else {
        // Extract the command from the JSON object
        const char* command = jsonDoc["command"];

        currentCommand = String(command); // Update the current command
      }

      messageBuffer = ""; // Clear the message buffer
    }
  }
}

// Main loop function
void loop() {
  if (!isConnected) {
    Serial.println("Attempting to connect to server...");
    if (client.connect(server_ip, server_port)) {
      Serial.println("Connected to server");
      isConnected = true; // Update connection status
    } else {
      Serial.println("Connection to server failed, retrying in 1 second...");
      delay(1000); // Wait before retrying
    }
  }

  if (client.connected()) {
    // Check for new commands from the server
    checkForCommand();

    // Execute commands based on the current command
    if (currentCommand == "forward") {
      walkForward();
    } else if (currentCommand == "start") {
      moveToStartPosition();
      currentCommand = ""; // Clear the command after execution
    } else if (currentCommand == "docking") {
      moveToDockingPosition();
      currentCommand = ""; // Clear the command after execution
    } else if (currentCommand == "sit") {
      sit();
      currentCommand = ""; // Clear the command after execution
    } else if (currentCommand == "lie") {
      lieDown();
      currentCommand = ""; // Clear the command after execution
    }
  } else {
    isConnected = false; // Update connection status
    Serial.println("Disconnected from server, attempting to reconnect...");
  }
}
