# ESP32 Robot Dog Control Code Explanation

This code allows an ESP32-based robot dog to connect to a Wi-Fi network, receive commands from a server, and execute various movements using servo motors.

## Libraries and Global Variables

First, we include the necessary libraries and define global variables:

```cpp
#include <ESP32Servo.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
```

- **ESP32Servo.h**: Controls the servo motors.
- **WiFiManager.h**: Manages Wi-Fi connections.
- **WiFiClient.h**: Handles Wi-Fi client operations.
- **ArduinoJson.h**: Parses JSON commands from the server.

Next, we define the server details and the Wi-Fi client object:

```cpp
const char* server_ip = "172.20.10.5";
const uint16_t server_port = 1234;
WiFiClient client;
bool isConnected = false;
```

- **server_ip**: IP address of the server.
- **server_port**: Port number of the server.
- **client**: Wi-Fi client object.
- **isConnected**: Tracks connection status.

## Servo Pins and Initial Positions

Define the pins for the servos and their initial positions:

```cpp
#define SERVO_FL_PIN 18
#define SERVO_RL_PIN 16
#define SERVO_FR_PIN 17
#define SERVO_RR_PIN 5
#define DEFAULT_POS 90
#define WALK_OFFSET 30
#define WALK_DELAY 350
```

- **SERVO_FL_PIN, SERVO_RL_PIN, SERVO_FR_PIN, SERVO_RR_PIN**: Pins for the front left, rear left, front right, and rear right servos.
- **DEFAULT_POS**: Default position for all servos.
- **WALK_OFFSET, WALK_DELAY**: Parameters for walking movement.

## Preset Positions

Define preset angles for different positions:

```cpp
#define DEFAULT_FL_SIT 110
#define DEFAULT_FR_SIT 70
#define DEFAULT_RL_SIT 35
#define DEFAULT_RR_SIT 145
#define PRESET_FL_LIE 0
#define PRESET_FR_LIE 180
#define PRESET_RL_LIE 180
#define PRESET_RR_LIE 0
#define WAVE_DOWN 30
#define WAVE_UP 0
```

- **Sitting and lying down positions**: Angles for the servos to achieve sitting and lying down positions.
- **Waving angles**: Angles for the waving motion.

## Create Servo Objects

Create servo objects for each leg:

```cpp
Servo FL;
Servo FR;
Servo RL;
Servo RR;
```

- **FL, FR, RL, RR**: Servo objects for each leg.

## Setup Function

Initialize the system and connect to Wi-Fi:

```cpp
void setup() {
  Serial.begin(115200);
  WiFiManager wifiManager;
  if (!wifiManager.autoConnect("Robot Dog")) {
    Serial.println("Failed to connect to WiFi");
    ESP.restart();
  }
  Serial.println("Connected to WiFi");

  FL.attach(SERVO_FL_PIN);
  FR.attach(SERVO_FR_PIN);
  RL.attach(SERVO_RL_PIN);
  RR.attach(SERVO_RR_PIN);

  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);

  delay(3000);
}
```

- **Serial.begin(115200)**: Initializes serial communication.
- **WiFiManager wifiManager**: Manages Wi-Fi connection.
- **autoConnect**: Connects to Wi-Fi.
- **FL.attach, FR.attach, RL.attach, RR.attach**: Attach servos to pins.
- **FL.write, FR.write, RL.write, RR.write**: Move servos to default positions.

## Dance Function

Defines a dance routine:

```cpp
void dance() {
  const int forwardAngle = 40;
  const int backwardAngle = 40;
  const int sideShiftAngle = 10;
  const int stepDelay = 300;
  unsigned long startTime = millis();

  while (currentCommand == "dance" && millis() - startTime < 10000) {
    FL.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);
    FL.write(DEFAULT_POS - forwardAngle);
    RR.write(DEFAULT_POS + backwardAngle);
    delay(stepDelay);
    FL.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS);
    delay(stepDelay);
    FL.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    delay(stepDelay);
    FR.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);
    FR.write(DEFAULT_POS - forwardAngle);
    RL.write(DEFAULT_POS + backwardAngle);
    delay(stepDelay);
    FR.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS);
    delay(stepDelay);
    FR.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(stepDelay);
    FL.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);
    FL.write(DEFAULT_POS + backwardAngle);
    RR.write(DEFAULT_POS - forwardAngle);
    delay(stepDelay);
    FL.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS);
    delay(stepDelay);
    FL.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    delay(stepDelay);
    FR.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);
    FR.write(DEFAULT_POS + backwardAngle);
    RL.write(DEFAULT_POS - forwardAngle);
    delay(stepDelay);
    FR.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS);
    delay(stepDelay);
    FR.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(stepDelay);
  }

  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
}
```

- **Dance routine**: Moves the servos in a sequence to create a dance-like motion.

## Move to Start Position

Move servos to the start position:

```cpp
void moveToStartPosition() {
  for (int angle = 0; angle <= 180; angle += 5) {
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(50);
  }
}
```

- **moveToStartPosition**: Smoothly moves servos from 0 to 180 degrees.

## Lying Down Function

Move servos to lying down position:

```cpp
void lieDown() {
  Serial.println("Lying down");
  FL.write(PRESET_FL_LIE);
  FR.write(PRESET_FR_LIE);
  RL.write(PRESET_RL_LIE);
  RR.write(PRESET_RR_LIE);
}
```

- **lieDown**: Moves the servos to lying down positions.

## Sitting Down Function

Move servos to sitting position:

```cpp
void sit() {
  Serial.println("Sitting down");
  FL.write(DEFAULT_FL_SIT);
  FR.write(DEFAULT_FR_SIT);
  RL.write(DEFAULT_RL_SIT);
  RR.write(DEFAULT_RR_SIT);
}
```

- **sit**: Moves the servos to sitting positions.

## Waving Function

Perform a waving motion:

```cpp
void wave() {
  for (int i = 0; i < 3; i++) {
    Serial.print("wave");
    FL.write(WAVE_DOWN);
    delay(500);
    FL.write(WAVE_UP);
    delay(500);
  }
  FL.write(DEFAULT_POS);
}
```

- **wave**: Moves the front left servo up and down to create a waving motion.

## Turning Functions

Turn right and left:

```cpp
void turnRight() {
  Serial.println("Turning right");
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    FL.write(TURN_RIGHT_FL);
    FR.write(TURN_RIGHT_FR);
    RL.write(TURN_RIGHT_RL);
    RR.write(TURN_RIGHT_RR);
    delay(TURN_DELAY);
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(TURN_DELAY);
  }
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  delay(WALK_DELAY);
}
```

- **turnRight**: Moves servos to turn right for 5 seconds.

```cpp
void turnLeft() {
  Serial.println("Turning left");
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    FL.write(TURN_LEFT_FL);
    FR.write(TURN_LEFT_FR);
    RL.write(TURN_LEFT_RL);
    RR.write(TURN_LEFT_RR);
    delay(TURN_DELAY);
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(TURN_DELAY);
  }
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  delay(WALK_DELAY);
}
```

- **turnLeft**: Moves servos to turn left for 5 seconds.

## Walking Functions

There are functions for walking forward and backwards. The forward function is split in two steps, leftStep() and rightStep().

This is the leftStep() function:

```cpp
void leftStep() {
  FR.write(90);
  delay(100);
  FL.write(60);
  delay(300);
  RL.write(110);
  delay(100);
  RR.write(120);
}
```

And this is the rightStep() function:

```cpp
void rightStep() {
  FL.write(90);
  delay(100);
  FR.write(120);
  delay(300);
  RR.write(70);
  delay(100);
  RL.write(60);
}
```

They are exact mirrors of each other, but with the servos on the opposite side. For the walking, they are called one by one in the walkForward() function:

```cpp
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
```

- **walkForward**: Moves the servos forward in a walking motion for 5 seconds.

```cpp
void walkBackwards() {
  const int hopAngle = 35;
  const int tiltAngle = 15;
  const int stepDelay = 500;
  unsigned long startTime = millis();

  while (millis() - startTime < 5000) {
    RL.write(DEFAULT_POS + tiltAngle);
    RR.write(DEFAULT_POS - tiltAngle);
    FR.write(DEFAULT_POS - tiltAngle);
    FL.write(DEFAULT_POS + tiltAngle);
    FR.write(DEFAULT_POS - hopAngle);
    FL.write(DEFAULT_POS + hopAngle);
    delay(stepDelay);
    FR.write(DEFAULT_POS);
    FL.write(DEFAULT_POS);
    delay(stepDelay);
  }
  FR.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  FL.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
}
```

- **walkBackwards**: Moves the servos backward in a walking motion for 5 seconds.

## Check for Command Function

Checks for incoming commands from the server:

```cpp
void checkForCommand() {
  static String messageBuffer;

  if (client.connected()) {
    while (client.available()) {
      char c = client.read();
      messageBuffer += c;
    }

    if (!messageBuffer.isEmpty()) {
      Serial.println("Received message:");
      Serial.println(messageBuffer);

      StaticJsonDocument<200> jsonDoc;
      DeserializationError error = deserializeJson(jsonDoc, messageBuffer);

      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
      } else {
        const char* command = jsonDoc["command"];
        currentCommand = String(command);
      }

      messageBuffer = "";
    }
  }
}
```

- **checkForCommand**: Reads incoming messages from the server, parses JSON, and extracts commands.

## Main Loop

The main loop continuously checks for commands and executes corresponding actions:
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
      isConnected = true;
    } else {
      Serial.println("Connection to server failed, retrying in 1 second...");
      delay(1000);
    }
  }

  if (client.connected()) {
    checkForCommand();

    if (currentCommand == "forward") {
      walkForward();
    } else if (currentCommand == "backward") {
      walkBackwards();
    } else if (currentCommand == "start") {
      moveToStartPosition();
      currentCommand = "";
    } else if (currentCommand == "lie") {
      lieDown();
      currentCommand = "";
    } else if (currentCommand == "sit") {
      sit();
      currentCommand = "";
    } else if (currentCommand == "wave") {
      wave();
      currentCommand = "";
    } else if (currentCommand == "right") {
      turnRight();
      currentCommand = "";
    } else if (currentCommand == "left") {
      turnLeft();
      currentCommand = "";
    } else if (currentCommand == "dance") {
      dance();
      currentCommand = "";
    }
  } else {
    isConnected = false;
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

- **Main Loop**: Manages the connection to the server and executes commands based on the received instructions.

---

This markdown document explains each part of the provided code, including its purpose and functionality.
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