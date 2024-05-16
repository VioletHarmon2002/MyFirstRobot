#include <ESP32Servo.h>

// Define the pins for the servos
#define SERVO_FL_PIN 6
#define SERVO_RL_PIN 7
#define SERVO_FR_PIN 4
#define SERVO_RR_PIN 5

#define DEFAULT_POS 90
#define WALK_OFFSET 30
#define WALK_DELAY 350

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

    // Left out
    Serial.println("Left out");
    RL.write(DEFAULT_POS + WALK_OFFSET);
    delay(100);
    FL.write(DEFAULT_POS - WALK_OFFSET);

    // Right in
    Serial.println("Right in");
    FR.write(DEFAULT_POS - WALK_OFFSET);
    delay(100);
    RR.write(DEFAULT_POS + WALK_OFFSET);

    // Delay
    delay(WALK_DELAY);

    // Left in
    Serial.println("Left in");
    FL.write(DEFAULT_POS + WALK_OFFSET);
    delay(100);
    RL.write(DEFAULT_POS - WALK_OFFSET);

    // Right out
    Serial.println("Right out");
    RR.write(DEFAULT_POS - WALK_OFFSET);
    delay(100);
    FR.write(DEFAULT_POS + WALK_OFFSET);
    
    

    // Delay
    delay(WALK_DELAY);
}