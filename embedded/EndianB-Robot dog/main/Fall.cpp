#include "Fall.h"

void Fall::FallRight(Servo& FL, Servo& FR, Servo& RL, Servo& RR) {
    FL.write(0);
    FR.write(0);
    RL.write(MAX_LEG_ROTATION);
    RR.write(MAX_LEG_ROTATION);
}

void Fall::FallLeft(Servo& FL, Servo& FR, Servo& RL, Servo& RR) {
    FL.write(MAX_LEG_ROTATION);
    FR.write(MAX_LEG_ROTATION);
    RL.write(0);
    RR.write(0);
}
