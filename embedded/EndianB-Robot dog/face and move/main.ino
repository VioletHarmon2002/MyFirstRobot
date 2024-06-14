#include <ESP32Servo.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// WiFi and server details
const char* server_ip = "172.20.10.5";  // IP address of the server to connect to
const uint16_t server_port = 8080;      // Port number of the server to connect to

WiFiClient client;  // WiFi client object to handle the connection
bool isConnected = false;  // Boolean flag to track connection status

// Define the pins for the servos
#define SERVO_FL_PIN 18  // Front left leg servo pin
#define SERVO_RL_PIN 16  // Rear left leg servo pin
#define SERVO_FR_PIN 17  // Front right leg servo pin
#define SERVO_RR_PIN 5   // Rear right leg servo pin

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

// OLED display definitions
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// I2C address of the OLED display
#define SSD1306_I2C_ADDRESS 0x3C

// Include separate bitmap header files
#include "smile_bitmap.h"
#include "frown_bitmap.h"
#include "idle_bitmap.h"

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

  // Initialize OLED display
  Wire.begin(4, 15); // SDA on pin 4, SCL on pin 15
  if (!display.begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.display();
}

void displayEmote(const unsigned char* bitmap, int width, int height) {
  display.clearDisplay();
  display.drawBitmap((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2, bitmap, width, height, WHITE);
  display.display();
}

void setFace(String command) {
  if (command == "sit" || command == "lie") {
    displayEmote(idle_bitmap, idle_width, idle_height);
  } else if (command == "forward" || command == "backward" || command == "dance") {
    displayEmote(smile_bitmap, smile_width, smile_height);
  } else if (command == "wave") {
    displayEmote(frown_bitmap, frown_width, frown_height);
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
    Serial.println("Waving");
    FL.write(WAVE_UP);
    delay(500);
    FL.write(WAVE_DOWN);
    delay(500);
  }
  FL.write(DEFAULT_POS); // Return the leg to the default position after waving
}

void moveForward() {
  // Perform forward walking motion
  Serial.println("Moving forward");
  FL.write(DEFAULT_POS + WALK_OFFSET);
  delay(WALK_DELAY);
  FL.write(DEFAULT_POS);
  RL.write(DEFAULT_POS + WALK_OFFSET);
  delay(WALK_DELAY);
  RL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS + WALK_OFFSET);
  delay(WALK_DELAY);
  FR.write(DEFAULT_POS);
  RR.write(DEFAULT_POS + WALK_OFFSET);
  delay(WALK_DELAY);
  RR.write(DEFAULT_POS);
}

void moveBackward() {
  // Perform backward walking motion
  Serial.println("Moving backward");
  FL.write(DEFAULT_POS - WALK_OFFSET);
  delay(WALK_DELAY);
  FL.write(DEFAULT_POS);
  RL.write(DEFAULT_POS - WALK_OFFSET);
  delay(WALK_DELAY);
  RL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS - WALK_OFFSET);
  delay(WALK_DELAY);
  FR.write(DEFAULT_POS);
  RR.write(DEFAULT_POS - WALK_OFFSET);
  delay(WALK_DELAY);
  RR.write(DEFAULT_POS);
}

void turnLeft() {
  // Perform left turn
  Serial.println("Turning left");
  FL.write(TURN_LEFT_FL);
  FR.write(TURN_LEFT_FR);
  RL.write(TURN_LEFT_RL);
  RR.write(TURN_LEFT_RR);
  delay(TURN_DELAY);
}

void turnRight() {
  // Perform right turn
  Serial.println("Turning right");
  FL.write(TURN_RIGHT_FL);
  FR.write(TURN_RIGHT_FR);
  RL.write(TURN_RIGHT_RL);
  RR.write(TURN_RIGHT_RR);
  delay(TURN_DELAY);
}

void handleCommand(String command) {
  if (command == "forward") {
    moveForward();
  } else if (command == "backward") {
    moveBackward();
  } else if (command == "left") {
    turnLeft();
  } else if (command == "right") {
    turnRight();
  } else if (command == "sit") {
    sit();
  } else if (command == "lie") {A
    lieDown();
  } else if (command == "wave") {
    wave();
  } else if (command == "dance") {
    dance();
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
