# `fall_right.h` Technical Documentation

## Overview  
The `fall_right.h` file defines a function to initiate a controlled fall of the robot to its right side using servo motors. The ESP32Servo library is used for servo control, ensuring precise positioning of the robot.

---

## Dependencies  
- **Library**: `ESP32Servo.h`  
  Required for controlling servo motors on ESP32 devices.

---

## Constants


const int fallRightPositions[4] = {0, 0, 180, 180};


- Defines the servo positions for a controlled right-side fall.
- The order of servo positions:
  1. **FL** - Front Left (0°)
  2. **FR** - Front Right (0°)
  3. **RL** - Rear Left (180°)
  4. **RR** - Rear Right (180°)

---

## Functions

### `void fallRight(Servo& FL, Servo& FR, Servo& RL, Servo& RR)`  
Initiates the robot's fall to the right by setting the servo motors.

#### Parameters:
- **`FL`**: Front Left servo motor
- **`FR`**: Front Right servo motor
- **`RL`**: Rear Left servo motor
- **`RR`**: Rear Right servo motor

#### Behavior:
1. **Prints**: "Falling to the right" to the serial monitor for debugging.

---

## Example Usage

#include <ESP32Servo.h>
#include "fall_right.h"

// Servo Initialization
Servo frontLeft;
Servo frontRight;
Servo rearLeft;
Servo rearRight;

void setup() {
    Serial.begin(9600);
    
    // Attach servos to appropriate pins
    frontLeft.attach(2);  // Example 
    frontRight.attach(4); // Example 
    rearLeft.attach(5);   // Example 
    rearRight.attach(18); // Example 
}

void loop() {
    // Trigger the controlled fall
    fallRight(frontLeft, frontRight, rearLeft, rearRight);
    delay(5000);  // Delay for demonstration
}
```

---
