#ifndef MOVEMENT_H // MOVEMENT_MOVEMENT_H
#define MOVEMENT_H // MOVEMENT_MOVEMENT_H

#include <ESP32Servo.h>

class Movement
{
public:
   // Constants
   static constexpr int DEFAULT_POS = 90;
   static constexpr int WALK_DELAY = 350;
   static constexpr int BACK_OFFSET = 35;
   static constexpr int FRONT_OFFSET = 15;
   static constexpr int STEP_INTERVAL = 300;
   static constexpr int WALK_DURATION = 5000;

   // Constructor
   Movement(int flPin, int frPin, int rlPin, int rrPin);

   // Methods to control the robot's movement
   void initServos();
   void stopServos();
   void leftStep();
   void rightStep();
   void walkForward();
   void walkBackward();
   void sit();

private:
   Servo FL, FR, RL, RR;
   Servo servos[4];
   int _servoPins[4] = {};
};

#endif // MOVEMENT_MOVEMENT_H
