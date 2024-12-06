#include "animation/animation.h"
#include <Arduino.h>

// Define servo objects
Servo FL;
Servo FR;
Servo RL;
Servo RR;

// sit() function implementation
void sit() {
    int sitPosition[] = {110, 70, 35, 145};

    FL.attach(SERVO_FL_PIN);
    FR.attach(SERVO_FR_PIN);
    RL.attach(SERVO_RL_PIN);
    RR.attach(SERVO_RR_PIN);

    FL.write(sitPosition[0]);  // FL
    FR.write(sitPosition[1]);  // FR
    RL.write(sitPosition[2]);  // RL
    RR.write(sitPosition[3]);  // RR
}
