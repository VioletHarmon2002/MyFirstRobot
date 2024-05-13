#include <ESP32Servo.h>

// Define the pins for the servos
#define SERVO_FL_PIN 1
#define SERVO_RL_PIN 2
#define SERVO_FR_PIN 4
#define SERVO_RR_PIN 5

#define DEFAULT_POS 90
#define WALK_OFFSET 20
#define WALK_DELAY 150

// Create servo objects
Servo FL; // Front left leg
Servo FR; // Front right leg
Servo RL; // Rear left leg
Servo RR; // Rear right leg

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Attach servos to pins
  FL.attach(SERVO_FL_PIN);
  FR.attach(SERVO_FR_PIN);
  RL.attach(SERVO_RL_PIN);
  RR.attach(SERVO_RR_PIN);

  // Move servos to initial position (optional)
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);

  delay(3000);

}

void loop() {
    FL.write(DEFAULT_POS - WALK_OFFSET);
    delay(30);
    RL.write(DEFAULT_POS + WALK_OFFSET);
    delay(WALK_DELAY);
    FR.write(DEFAULT_POS - WALK_OFFSET);
    delay(30);
    RR.write(DEFAULT_POS + WALK_OFFSET);
    delay(WALK_DELAY);
    FL.write(DEFAULT_POS + WALK_OFFSET);
    delay(30);
    RL.write(DEFAULT_POS - WALK_OFFSET);
    delay(WALK_DELAY);
    FR.write(DEFAULT_POS + WALK_OFFSET);
    delay(30);
    RR.write(DEFAULT_POS - WALK_OFFSET);
    delay(WALK_DELAY);
}