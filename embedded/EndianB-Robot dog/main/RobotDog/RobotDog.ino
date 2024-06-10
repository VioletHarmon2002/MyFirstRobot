#include <ESP32Servo.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

// WiFi and server details
const char* server_ip = "172.20.10.5";
const uint16_t server_port = 1234;

WiFiClient client;
bool isConnected = false;

// Define the pins for the servos
#define SERVO_FL_PIN 4
#define SERVO_RL_PIN 16
#define SERVO_FR_PIN 17
#define SERVO_RR_PIN 5

#define DEFAULT_POS 90
#define WALK_OFFSET 30
#define WALK_DELAY 350

// Preset for Sitting
#define DEFAULT_FL_SIT 110
#define DEFAULT_FR_SIT 70
#define DEFAULT_RL_SIT 35
#define DEFAULT_RR_SIT 145

// Preset for lying down
#define PRESET_FL_LIE 0
#define PRESET_FR_LIE 180
#define PRESET_RL_LIE 180
#define PRESET_RR_LIE 0

// Wave preset
#define WAVE_DOWN 30
#define WAVE_UP 0

// Turning presets
#define TURN_RIGHT_FL 60
#define TURN_RIGHT_FR 120
#define TURN_RIGHT_RL 120
#define TURN_RIGHT_RR 60

#define TURN_LEFT_FL 120
#define TURN_LEFT_FR 60
#define TURN_LEFT_RL 60
#define TURN_LEFT_RR 120

// Create servo objects
Servo FL; // Front left leg
Servo FR; // Front right leg
Servo RL; // Rear left leg
Servo RR; // Rear right leg

String currentCommand = "";

void setup() {
  Serial.begin(115200);
  // Attach servos to pins
  FL.attach(SERVO_FL_PIN);
  FR.attach(SERVO_FR_PIN);
  RL.attach(SERVO_RL_PIN);
  RR.attach(SERVO_RR_PIN);
  // Move servos to initial position
  moveToStartPosition();

  // Initialize WiFiManager
  WiFiManager wifiManager;

  // Uncomment the line below if you want to reset settings
  // wifiManager.resetSettings();

  // Start WiFiManager
  // if (!wifiManager.autoConnect("Robot Dog")) {
  //   Serial.println("Failed to connect to WiFi");
  //   ESP.restart(); // Reset if WiFiManager fails to connect
  // }
  // Serial.println("Connected to WiFi");

  delay(3000);
}

void walkForward() {
  unsigned long startTime = millis();
  
  while (currentCommand == "forward" && millis() - startTime < 5000) { // 5 seconds
    RL.write(DEFAULT_POS + WALK_OFFSET);
    delay(100);
    FL.write(DEFAULT_POS - WALK_OFFSET);

    FR.write(DEFAULT_POS - WALK_OFFSET);
    delay(100);
    RR.write(DEFAULT_POS + WALK_OFFSET);

    // Delay
    delay(WALK_DELAY);

    FL.write(DEFAULT_POS + WALK_OFFSET);
    delay(100);
    RL.write(DEFAULT_POS - WALK_OFFSET);
    
    RR.write(DEFAULT_POS - WALK_OFFSET);
    delay(100);
    FR.write(DEFAULT_POS + WALK_OFFSET);

    // Delay
    delay(WALK_DELAY);
  }

  // Stop the movement
  moveToStartPosition();
}

void moveToStartPosition() {
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(50);
}

void lieDown() {
  Serial.println("Lying down");
  FL.write(PRESET_FL_LIE);    // Move front left leg to lying position
  FR.write(PRESET_FR_LIE);  // Move front right leg to lying position
  RL.write(PRESET_RL_LIE);  // Move rear left leg to lying position
  RR.write(PRESET_RR_LIE);    // Move rear right leg to lying position
}

void sit() {
  Serial.println("Sitting down");
  FL.write(DEFAULT_FL_SIT);   // Front legs stand
  FR.write(DEFAULT_FR_SIT); 
  RL.write(DEFAULT_RL_SIT);   // Rear legs sit
  RR.write(DEFAULT_RR_SIT);
}

void wave() {
  Serial.print("Hallo!");
  for (int i = 0; i < 3; i++) {
    Serial.print("Zwaai");
    FL.write(WAVE_DOWN);
    delay(500); // Add delay for a visible wave
    FL.write(WAVE_UP);
    delay(500); // Add delay for a visible wave
  }
  FL.write(DEFAULT_POS);
}

void turnRight() {
  Serial.println("Turning right");
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    // Adjust the servo positions for turning right
    FL.write(TURN_RIGHT_FL);  // Front left leg right turn
    FR.write(TURN_RIGHT_FR);  // Front right leg left turn
    RL.write(TURN_RIGHT_RL);  // Rear left leg left turn
    RR.write(TURN_RIGHT_RR);  // Rear right leg right turn
  }

  // Return to default position
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  delay(WALK_DELAY);
}

void turnLeft() {
  Serial.println("Turning left");
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    // Adjust the servo positions for turning left
    FL.write(TURN_LEFT_FL);   // Front left leg left turn
    FR.write(TURN_LEFT_FR);   // Front right leg right turn
    RL.write(TURN_LEFT_RL);   // Rear left leg right turn
    RR.write(TURN_LEFT_RR);   // Rear right leg left turn
  }

  // Return to default position
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  delay(WALK_DELAY);
}


void checkForCommand() {
  static String messageBuffer;

  if (client.connected()) {
    while (client.available()) {
      char c = client.read();
      messageBuffer += c;
    }

    if (!messageBuffer.isEmpty()) {
      // Print the received message
      Serial.println("Received message:");
      Serial.println(messageBuffer);

      // Decode the JSON message
      StaticJsonDocument<200> jsonDoc; // Adjust the size according to your message
      DeserializationError error = deserializeJson(jsonDoc, messageBuffer);

      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
      } else {
        // Extract the command from the JSON object
        const char* command = jsonDoc["command"];

        currentCommand = String(command);
      }

      messageBuffer = "";
    }
  }
}

void loop() {
  walkForward();
  // if (!isConnected) {
  //   Serial.println("Attempting to connect to server...");
  //   if (client.connect(server_ip, server_port)) {
  //     Serial.println("Connected to server");
  //     isConnected = true;
  //   } else {
  //     Serial.println("Connection to server failed, retrying in 1 second...");
  //     delay(1000); // Wait before retrying
  //   }
  // }

  // if (client.connected()) {
  //   // Check for new commands
  //   checkForCommand();

  //   // Execute commands based on the current command
  //   if (currentCommand == "forward") {
  //     walkForward();
  //   } else if (currentCommand == "start") {
  //     moveToStartPosition();
  //     currentCommand = ""; // Clear the command after execution
  //   } else if (currentCommand == "lie") {
  //     lieDown();
  //     currentCommand = ""; // Clear the command after execution
  //   } else if (currentCommand == "sit") {
  //     sit();
  //     currentCommand = ""; // Clear the command after execution
  //   } else if (currentCommand == "wave") {
  //     wave();
  //     currentCommand = ""; // Clear the command after execution
  //   } else if (currentCommand == "right") {
  //     turnRight();
  //     currentCommand = ""; // Clear the command after execution
  //   } else if (currentCommand == "left") {
  //     turnLeft();
  //     currentCommand = ""; // Clear the command after execution
  //   }
  // } else {
  //   isConnected = false;
  //   Serial.println("Disconnected from server, attempting to reconnect...");
  // }
}