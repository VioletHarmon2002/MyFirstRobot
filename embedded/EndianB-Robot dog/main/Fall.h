#ifndef FALL_RIGHT_H
#define FALL_RIGHT_H

#define MAX_LEG_ROTATION 180

#include <ESP32Servo.h>

class Fall {
    public:
        Fall();
        ~Fall();

        void FallRight(Servo& FL, Servo& FR, Servo& RL, Servo& RR);
        void FallLeft(Servo& FL, Servo& FR, Servo& RL, Servo& RR);
};

#endif
