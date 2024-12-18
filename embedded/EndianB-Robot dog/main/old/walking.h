#pragma once

#include <Arduino.h>
#include <ESP32Servo.h>

// Define the pins for the servos
#define SERVO_FL_PIN 18  // Front left leg servo pin
#define SERVO_RL_PIN 16  // Rear left leg servo pin
#define SERVO_FR_PIN 17  // Front right leg servo pin
#define SERVO_RR_PIN 5   // Rear right leg servo pin

// Create servo objects for each leg
Servo FL;  // Front left leg servo
Servo FR;  // Front right leg servo
Servo RL;  // Rear left leg servo
Servo RR;  // Rear right leg servo

#define DEFAULT_POS 90  // Default position for all servos
#define WALK_OFFSET 30  // Offset for walking movement
#define WALK_DELAY 350  // Delay between walking steps

const int stepInterval = 300;  // Time per step (milliseconds)
const int walkDuration = 5000; // Duration to walk forward (milliseconds)

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

void stopServos() {
  FR.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  FL.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
}

void walkForward() {
  unsigned long startTime = millis();  // Record start time
  unsigned long lastStepTime = 0;      // Track time of the last step

  // Alternate steps within the walking duration
  bool isLeftStep = true;  // Track step state

  while (millis() - startTime < walkDuration) {
    if (millis() - lastStepTime >= stepInterval) {
      if (isLeftStep) {
        leftStep();  // Perform left step
      } else {
        rightStep();  // Perform right step
      }
      isLeftStep = !isLeftStep;        // Toggle step
      lastStepTime = millis();         // Update last step time
    }
    // Add any other checks or background tasks here if needed
  }

  stopServos();  // Stop all servos after walking
}
