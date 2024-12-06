#ifndef ANIMATION_H  
#define ANIMATION_H

#include <ESP32Servo.h>

// Define the pins for the servos
constexpr int SERVO_FL_PIN = 18;  // Front left leg servo pin
constexpr int SERVO_RL_PIN = 16;  // Rear left leg servo pin
constexpr int SERVO_FR_PIN = 17;  // Front right leg servo pin
constexpr int SERVO_RR_PIN = 5;   // Rear right leg servo pin

// Servo object declarations
extern Servo FL;
extern Servo FR;
extern Servo RL;
extern Servo RR;

// Function declaration
void sit();

#endif  
