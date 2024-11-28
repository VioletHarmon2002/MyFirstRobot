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
#define WALK_DELAY 350  // Delay between walking steps
#define BACK_OFFSET 35  // Angle to lift the back legs
#define FRONT_OFFSET 15 // Angle to lift the front legs

const int stepInterval = 300;  // Time per step (milliseconds)
const int walkDuration = 5000; // Duration to walk backwards (milliseconds)

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

void walkBackward() {
  unsigned long startTime = millis();  // Record start time
  unsigned long lastStepTime = 0;      // Track time of the last step

  while (millis() - startTime < walkDuration) {
    if (millis() - lastStepTime >= stepInterval) {
      RL.write(DEFAULT_POS + FRONT_OFFSET);
      RR.write(DEFAULT_POS - FRONT_OFFSET);
      FR.write(DEFAULT_POS - FRONT_OFFSET);
      FL.write(DEFAULT_POS + FRONT_OFFSET);
      FR.write(DEFAULT_POS - BACK_OFFSET);
      FL.write(DEFAULT_POS + BACK_OFFSET);
      lastStepTime = millis();         // Update last step time
    }
    // Add any other checks or background tasks here if needed
  }

  stopServos();  // Stop all servos after walking
}