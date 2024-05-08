#include <ESP32Servo.h>

// Define the pin for the servo
#define SERVO1_PIN 1
#define SERVO2_PIN 2
#define SERVO3_PIN 4
#define SERVO4_PIN 5

// Create a servo object
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Attach the servo to the pin
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);

  // Move the servo to its initial position (optional)
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
}

void loop() {
 if (Serial.available() > 0) {
  int angle = Serial.parseInt(); // Read the angle value
  Serial.print("Moving servo to ");
  Serial.print(angle);
  Serial.println(" degrees");

  servo1.write(angle);
  servo2.write(angle);
  servo3.write(angle);
  servo4.write(angle);

  delay(1000);

 } else {
  delay(500);
 }
}