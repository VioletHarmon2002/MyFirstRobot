## Motor_test

An arduino sketch to test the steppermotors and the shift registers

## Accelstepper

Copy this folder to your Arduino/libaries folder for the LEAccelStepper to work. This is the original Accelstepper library with a small change to make it possible to extend it and use shift registers.

Read the original [AccelStepper documentation](https://www.airspayce.com/mikem/arduino/AccelStepper/) for more information.

## PCB Design

The PCB contains the following components:

### 74HC595 shift register

This component is used so the WEMOS D1 Mini needs less pins to control the steppermotors. The shift register is connected to the WEMOS D1 Mini with the following pins:

| WEMOS D1 Mini | 74HC595 |
| ------------- | ------- |
| D0            | DS      |
| D4            | SCHP    |
| D5            | STCP    |

By setting these 3 pins HIGH or LOW in a specific order, you can control the 8 output pins of the shift register. 

### ULN2003A transistor array

This component is used to control the steppermotors by diverting power directly from the battery or USB to the stepper motor coils. The ULN2003A is connected to the shift register in the following way:

| 74HC595 | ULN2003A | motor          |
| ------- | -------- | -------------- |
| Q0      | IN1      | Motor 2, Pin 4 |
| Q1      | IN2      | Motor 2, Pin 3 |
| Q2      | IN3      | Motor 2, Pin 2 |
| Q3      | IN4      | Motor 2, Pin 1 |
| Q4      | IN5      | Motor 1, Pin 4 |
| Q5      | IN6      | Motor 1, Pin 3 |
| Q6      | IN7      | Motor 1, Pin 2 |
| Q7      | IN8      | Motor 1, Pin 1 |

### RGB LED

An WS2812 RGB LED is connected with its datapin to pin D4 on the WEMOS. You can use the Adafruit NeoPixel library to control the LED.

### Battery

The PCB can be powered by four AA batteries. The batteries are connected to the PCB with a JST connector. The battery power can be switched on or off using a switch between connected to `JP3`.

### External devices

The I2C (SCL and SDA) pins of the WEMOS are connected to multiple JST connectors in order to connect external peripherals. These pins (D1 and D2) can also be used as GPIO pins.