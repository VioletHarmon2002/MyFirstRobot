#ifndef LIEDOWN_H
#define LIEDOWN_H

#include <ESP32Servo.h>

const int lieDownPositions[4] = {0, 180, 180, 0}; // FL, FR, RL, RR

void lieDown(Servo& FL, Servo& FR, Servo& RL, Servo& RR) {
    Serial.println("Lying down");
    FL.write(lieDownPositions[0]);
    FR.write(lieDownPositions[1]);
    RL.write(lieDownPositions[2]);
    RR.write(lieDownPositions[3]);
}

#endif
