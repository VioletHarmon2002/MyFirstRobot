#ifndef FALL_RIGHT_H
#define FALL_RIGHT_H

#include <ESP32Servo.h>

const int fallRightPositions[4] = {0, 0, 180, 180}; // FL, FR, RL, RR

void fallRight(Servo& FL, Servo& FR, Servo& RL, Servo& RR) {
    Serial.println("Falling to the right");
    FL.write(fallRightPositions[0]);
    FR.write(fallRightPositions[1]);
    RL.write(fallRightPositions[2]);
    RR.write(fallRightPositions[3]);
}


#endif

