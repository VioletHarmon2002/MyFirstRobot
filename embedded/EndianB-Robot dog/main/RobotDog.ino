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


// Create servo objects
Servo FL; // Front left leg
Servo FR; // Front right leg
Servo RL; // Rear left leg
Servo RR; // Rear right leg

String currentCommand = "";

void setup() {
  Serial.begin(115200);

  // Initialize WiFiManager
  WiFiManager wifiManager;

  // Uncomment the line below if you want to reset settings
  // wifiManager.resetSettings();

  // Start WiFiManager
  if (!wifiManager.autoConnect("Robot Dog")) {
    Serial.println("Failed to connect to WiFi");
    ESP.restart(); // Reset if WiFiManager fails to connect
  }
  Serial.println("Connected to WiFi");

  // Attach servos to pins
  FL.attach(SERVO_FL_PIN);
  FR.attach(SERVO_FR_PIN);
  RL.attach(SERVO_RL_PIN);
  RR.attach(SERVO_RR_PIN);

  // Move servos to initial position
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);

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
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
}

void moveToStartPosition() {
  for (int angle = 0; angle <= 180; angle += 5) {
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(50);
  }
}

void moveToDockingPosition() {
  for (int angle = 180; angle >= 0; angle -= 5) {
    FL.write(angle);
    FR.write(angle);
    RL.write(angle);
    RR.write(angle);
    delay(50);
  }
}

void sit() {
  Serial.println("Sitting down");
  FL.write(110); // Front legs stand
  FR.write(70); 
  RL.write(170);   // Rear legs sit
  RR.write(10);
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
  if (!isConnected) {
    Serial.println("Attempting to connect to server...");
    if (client.connect(server_ip, server_port)) {
      Serial.println("Connected to server");
      isConnected = true;
    } else {
      Serial.println("Connection to server failed, retrying in 1 second...");
      delay(1000); // Wait before retrying
    }
  }

  if (client.connected()) {
    // Check for new commands
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
    }
  } else {
    isConnected = false;
    Serial.println("Disconnected from server, attempting to reconnect...");
  }
}