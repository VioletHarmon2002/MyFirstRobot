# Robot Dog Code Documentation

## Includes and Definitions

```cpp
#include <ESP32Servo.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
```
- **ESP32Servo.h**: Library to control servo motors.
- **WiFiManager.h**: Library to manage WiFi connections.
- **WiFiClient.h**: Library to manage WiFi client connections.
- **ArduinoJson.h**: Library to handle JSON data.

### Server Details

```cpp
const char* server_ip = "172.20.10.5";
const uint16_t server_port = 1234;
```
- **server_ip**: IP address of the server.
- **server_port**: Port number of the server.

### WiFi Client

```cpp
WiFiClient client;
bool isConnected = false;
```
- **client**: WiFi client object for server connection.
- **isConnected**: Flag to track connection status.

### Servo Pins

```cpp
#define SERVO_FL_PIN 4
#define SERVO_RL_PIN 16
#define SERVO_FR_PIN 17
#define SERVO_RR_PIN 5
```
- **SERVO_FL_PIN**: Pin for front left servo.
- **SERVO_RL_PIN**: Pin for rear left servo.
- **SERVO_FR_PIN**: Pin for front right servo.
- **SERVO_RR_PIN**: Pin for rear right servo.

### Constants

```cpp
#define DEFAULT_POS 90
#define WALK_OFFSET 30
#define WALK_DELAY 350
```
- **DEFAULT_POS**: Default position for servos (middle).
- **WALK_OFFSET**: Offset angle for walking motion.
- **WALK_DELAY**: Delay between walking steps.

### Servo Objects

```cpp
Servo FL; // Front left leg
Servo FR; // Front right leg
Servo RL; // Rear left leg
Servo RR; // Rear right leg
```
- Creating servo objects for each leg.

### Current Command

```cpp
String currentCommand = "";
```
- **currentCommand**: Stores the current command from the server.

## Setup Function

```cpp
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
```
- **Serial.begin(115200)**: Starts serial communication for debugging.
- **WiFiManager wifiManager**: Creates a WiFiManager object.
- **wifiManager.autoConnect("Robot Dog")**: Connects to WiFi, restarting the board if it fails.
- **FL.attach(SERVO_FL_PIN)**: Attaches front left servo to its pin.
- **FL.write(DEFAULT_POS)**: Sets front left servo to the default position.
- Similar lines for other servos.
- **delay(3000)**: Waits for 3 seconds to let the servos stabilize.

## walkForward Function

```cpp
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
```
- **startTime = millis()**: Records the current time.
- **while loop**: Runs the walking sequence for 5 seconds or until the command changes.
- **Servo.write(angle)**: Moves each servo to a specific angle.
- **delay(ms)**: Short pauses to create smooth motion.
- **Resets servo positions** after the walk.

## moveToStartPosition Function

```cpp
void moveToStartPosition() {
  for (int angle = 0; angle <= 180; angle += 5) {
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(50); // Short delay for smooth movement
  }
}
```
- **for loop**: Gradually moves servos from 0 to 180 degrees.
- **Servo.write(DEFAULT_POS)**: Sets each servo to the default position.
- **delay(50)**: Short pauses for smooth movement.

## moveToDockingPosition Function

```cpp
void moveToDockingPosition() {
  for (int angle = 180; angle >= 0; angle -= 5) {
    FL.write(angle);
    FR.write(angle);
    RL.write(angle);
    RR.write(angle);
    delay(50); // Short delay for smooth movement
  }
}
```
- **for loop**: Gradually moves servos from 180 to 0 degrees.
- **Servo.write(angle)**: Sets each servo to the current angle.
- **delay(50)**: Short pauses for smooth movement.

## sit Function

```cpp
void sit() {
  Serial.println("Sitting down");
  FL.write(110); // Move front left leg to standing position
  FR.write(70);  // Move front right leg to standing position
  RL.write(170); // Move rear left leg to sitting position
  RR.write(10);  // Move rear right leg to sitting position
}
```
- **Serial.println("Sitting down")**: Prints a message to the serial monitor.
- **Servo.write(angle)**: Sets each servo to the specified angle for sitting position.

## Lying down Function

```cpp
void lieDown() {
  Serial.println("Lying down");
  FL.write(0); // Move front left leg to lying position
  FR.write(0); // Move front right leg to lying position
  RL.write(180); // Move rear left leg to lying position
  RR.write(180); // Move rear right leg to lying position
}
```
- **Serial.println("Lying down")**: Prints a message to the serial monitor.
- **Servo.write(angle)**: Sets each servo to the specified angle for sitting position.


## checkForCommand Function

```cpp
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
```
- **messageBuffer**: Stores incoming messages from the server.
- **client.connected()**: Checks if the client is connected to the server.
- **client.read()**: Reads each character from the server.
- **messageBuffer += c**: Adds the character to the message buffer.
- **Serial.println**: Prints messages to the serial monitor.
- **deserializeJson(jsonDoc, messageBuffer)**: Parses the JSON message.
- **jsonDoc["command"]**: Extracts the command from the JSON document.
- **currentCommand = String(command)**: Updates the current command.
- **messageBuffer = ""**: Clears the message buffer.

## loop Function

```cpp
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
      move

ToStartPosition();
      currentCommand = ""; // Clear the command after execution
    } else if (currentCommand == "docking") {
      moveToDockingPosition();
      currentCommand = ""; // Clear the command after execution
    } else if (currentCommand == "sit") {
      sit();
      currentCommand = ""; // Clear the command after execution
    }
  } else {
    isConnected = false; // Update connection status
    Serial.println("Disconnected from server, attempting to reconnect...");
  }
}
```
- **if (!isConnected)**: Checks if the client is not connected to the server.
- **client.connect(server_ip, server_port)**: Attempts to connect to the server.
- **isConnected = true**: Updates the connection status if successful.
- **delay(1000)**: Waits for 1 second before retrying.
- **client.connected()**: Checks if the client is connected to the server.
- **checkForCommand()**: Checks for new commands from the server.
- **if (currentCommand == "forward")**: Executes the `walkForward` function if the command is "forward".
- **moveToStartPosition()**: Moves servos to the start position if the command is "start".
- **moveToDockingPosition()**: Moves servos to the docking position if the command is "docking".
- **sit()**: Executes the `sit` function if the command is "sit".
- **isConnected = false**: Updates the connection status if disconnected.
- **Serial.println**: Prints messages to the serial monitor.

This documentation provides a detailed explanation of each part of the code in simple language, making it easier to understand the functionality of the robot dog.