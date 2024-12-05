#ifndef EMBEDDED_ENDIANB_ROBOT_DOG_MAIN_FALL_H_
#define EMBEDDED_ENDIANB_ROBOT_DOG_MAIN_FALL_H_

#define MAX_LEG_ROTATION 180

#include <ESP32Servo.h>

class Fall {
 public:
    Fall();
    ~Fall();

    const void FallRight(const Servo& FL, const Servo& FR,
                        const Servo& RL, const Servo& RR);
    const void FallLeft(const Servo& FL, const Servo& FR,
                        const Servo& RL, const Servo& RR);
};

#endif  // EMBEDDED_ENDIANB_ROBOT_DOG_MAIN_FALL_H_
