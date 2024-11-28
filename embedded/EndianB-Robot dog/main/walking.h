#ifndef WALKING_H
#define WALKING_H

#include <ESP32Servo.h>

// Define the pins for the servos
#define SERVO_FL_PIN 18  // Front left leg servo pin
#define SERVO_RL_PIN 16  // Rear left leg servo pin
#define SERVO_FR_PIN 17  // Front right leg servo pin
#define SERVO_RR_PIN 5   // Rear right leg servo pin


#define DEFAULT_POS 90  // Default position for all servos
#define WALK_OFFSET 30  // Offset for walking movement
#define WALK_DELAY 350  // Delay between walking steps

void init_servo() {
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
}

// Function definitions
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

#endif  // WALKING_H