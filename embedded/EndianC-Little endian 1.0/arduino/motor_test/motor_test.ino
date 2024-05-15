// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: MultiStepper.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include "LEAccelStepper.h"
#define PIN0_3 0
#define PIN4_7 4

// Define some steppers and the pins the will use
LEAccelStepper stepper1(LEAccelStepper::SHIFT_REGISTER, D5, D0, D4, PIN4_7); // LEAccelStepper is used to control the steppermotors on the PCB
LEAccelStepper stepper2(LEAccelStepper::SHIFT_REGISTER, D5, D0, D4, PIN0_3); // LEAccelStepper is used to control the steppermotors on the PCB

void setup()
{
  stepper1.setMaxSpeed(500.0);
  stepper1.setAcceleration(100.0);
  stepper1.moveTo(1000000);

  stepper2.setMaxSpeed(500.0);
  stepper2.setAcceleration(100.0);
  stepper2.moveTo(1000000);

}

void loop()
{
  stepper1.run();
  stepper2.run();
}
