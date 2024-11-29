#pragma once

#include <Arduino.h>
#include <ESP32Servo.h>

// Define the pins for the servos
#define SERVO_FL_PIN 18  // Front left leg servo pin
#define SERVO_RL_PIN 16  // Rear left leg servo pin
#define SERVO_FR_PIN 17  // Front right leg servo pin
#define SERVO_RR_PIN 5   // Rear right leg servo pin

#define DEFAULT_POS 90  // Default position for all servos
#define WALK_DELAY 350  // Delay between walking steps
#define BACK_OFFSET 35  // Angle to lift the back legs
#define FRONT_OFFSET 15 // Angle to lift the front legs

// Array of Servo objects
Servo servos[4];

const int stepInterval = 300;  // Time per step (milliseconds)
const int walkDuration = 5000; // Duration to walk backward (milliseconds)
const int servoPins[4] = {SERVO_FL_PIN, SERVO_FR_PIN, SERVO_RL_PIN, SERVO_RR_PIN}; // Array of pins for the servos

void init_servo() {
    for (int i = 0; i < 4; i++) {
        servos[i].attach(servoPins[i]);  // Attach each servo to its pin
        servos[i].write(DEFAULT_POS);   // Set initial position
    }
}

void stopServos() {
    for (int i = 0; i < 4; i++) {
        servos[i].write(DEFAULT_POS);
    }
}

void walkBackward() {
    unsigned long startTime = millis();  // Record start time
    unsigned long lastStepTime = 0;      // Track time of the last step

    while (millis() - startTime < walkDuration) {
        if (millis() - lastStepTime >= stepInterval) {
            // Adjust positions of servos in pairs for walking movement
            servos[2].write(DEFAULT_POS + FRONT_OFFSET);  // RL
            servos[3].write(DEFAULT_POS - FRONT_OFFSET);  // RR
            servos[1].write(DEFAULT_POS - FRONT_OFFSET);  // FR
            servos[0].write(DEFAULT_POS + FRONT_OFFSET);  // FL
            servos[1].write(DEFAULT_POS - BACK_OFFSET);   // FR
            servos[0].write(DEFAULT_POS + BACK_OFFSET);   // FL
            lastStepTime = millis();                      // Update last step time
        }
        // Add any other checks or background tasks here if needed
    }

    stopServos();  // Stop all servos after walking
}