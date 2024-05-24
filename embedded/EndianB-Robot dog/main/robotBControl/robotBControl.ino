#include <ESP32Servo.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

const char* server_ip = "172.20.10.5";
const uint16_t server_port = 1234;

WiFiClient client;
bool isConnected = false;

// Define the pins for the servos
#define SERVO1_PIN 1
#define SERVO2_PIN 2
#define SERVO3_PIN 4
#define SERVO4_PIN 5

// Create servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  Serial.begin(115200);

  // Initialize WiFiManager
  WiFiManager wifiManager;
  
  // Uncomment the line below if you want to reset settings
  // wifiManager.resetSettings();

  // Set up custom parameters
  // wifiManager.addParameter(&custom_param);
  
  // Start WiFiManager
  wifiManager.autoConnect("Robot A");
  Serial.println("Connected to WiFi");

  // Attach servos to pins
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);

  initServoPos();
}

void loop() {
  static String messageBuffer;

  if (!isConnected && !client.connected()) {
    Serial.println("Attempting to connect to server...");
    if (client.connect(server_ip, server_port)) {
      Serial.println("Connected to server");
      isConnected = true;
    } else {
      Serial.println("Connection failed");
    }
  }

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
        // Extract the message from the JSON object
        int angle = jsonDoc["angle"];

        // Ensure angle is within valid range
        angle = constrain(angle, 0, 180);

        // Set servo positions
        servo1.write(angle);
        servo2.write(angle);
        servo3.write(angle);
        servo4.write(angle);

        Serial.print("Moving servos to ");
        Serial.print(angle);
        Serial.println(" degrees");
      }

      messageBuffer = "";
    }
  }
}

void initServoPos() {
  // Move servos to initial position (optional)
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
}

void wave() {
  servo1.write
}

