# Fall Right Module - User Documentation

## Overview

The Fall Right module provides a function to adjust the servos of the Little Endian robot when it is falling to the right. This function is intended to be used as part of a larger system that detects falls and triggers appropriate responses.

## Features

- Adjusts the servos to predefined positions to help stabilize the robot.
- Simple integration with existing servo control systems.

## How to Use

1. **Setup**: Ensure that the servos are properly connected to the robot's control board and are initialized using the `ESP32Servo` library.
2. **Function Call**: Use the `fallRight` function to adjust the servos when a right-side fall is detected.
3. **Integration**: Integrate this function into your fall detection system to automatically trigger servo adjustments.

## Troubleshooting

- **Servo Movement Issues**: If the servos do not move as expected, check the connections and ensure the servos are properly initialized.
