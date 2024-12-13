#include "movement/movement.h"

// Constructor
Movement::Movement(int flPin, int frPin, int rlPin, int rrPin)
{
    _servoPins[0] = flPin;
    _servoPins[1] = frPin;
    _servoPins[2] = rlPin;
    _servoPins[3] = rrPin;
}

// Initialize servos
void Movement::initServos()
{
    for (int i = 0; i < 4; i++)
    {
        servos[i].attach(_servoPins[i]); // Attach each servo to its pin
        servos[i].write(DEFAULT_POS);    // Set initial position
    }
    Serial.println("Servos initialized");
}

// Stop servos
void Movement::stopServos()
{
    for (int i = 0; i < 4; i++)
    {
        servos[i].write(DEFAULT_POS);
    }
}

// Left step movement
void Movement::leftStep()
{
    FR.write(90);
    delay(100);
    FL.write(60);
    delay(300);
    RL.write(110);
    delay(100);
    RR.write(120);
}

// Right step movement
void Movement::rightStep()
{
    FL.write(90);
    delay(100);
    FR.write(120);
    delay(300);
    RR.write(70);
    delay(100);
    RL.write(60);
}

// Walk forward
void Movement::walkForward()
{
    uint32_t startTime = millis();
    uint32_t lastStepTime = 0;
    bool isLeftStep = true;

    while (millis() - startTime < WALK_DURATION)
    {
        if (millis() - lastStepTime >= STEP_INTERVAL)
        {
            if (isLeftStep)
            {
                leftStep();
            }
            else
            {
                rightStep();
            }
            isLeftStep = !isLeftStep;
            lastStepTime = millis();
        }
    }
    stopServos();
}

// Walk backward
void Movement::walkBackward()
{
    uint32_t startTime = millis();
    uint32_t lastStepTime = 0;

    while (millis() - startTime < WALK_DURATION)
    {
        if (millis() - lastStepTime >= STEP_INTERVAL)
        {
            servos[2].write(DEFAULT_POS + FRONT_OFFSET); // RL
            servos[3].write(DEFAULT_POS - FRONT_OFFSET); // RR
            servos[1].write(DEFAULT_POS - FRONT_OFFSET); // FR
            servos[0].write(DEFAULT_POS + FRONT_OFFSET); // FL
            lastStepTime = millis();
        }
    }
    Serial.println(startTime);
    stopServos();
}
