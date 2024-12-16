#include "movement/movement.h"

// Constructor
Movement::Movement(int flPin, int rlPin, int frPin, int rrPin)
{
    _servoPins[0] = flPin;
    _servoPins[1] = rlPin;
    _servoPins[2] = frPin;
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
    int leftStep[] = {90, 110, 60, 120};
    for (int i = 0; i < 4; i++)
    {
        servos[i].write(leftStep[i]);
        delay(250);
    }
}

// Right step movement
void Movement::rightStep()
{
    int leftStep[] = {90, 60, 120, 70};
    for (int i = 0; i < 4; i++)
    {
        servos[i].write(leftStep[i]);
        delay(250);
    }
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

// Sit movement
void Movement::sit()
{
    int sitPosition[] = {110, 40, 70, 145};

    for (int i = 0; i < 4; i++)
    {
        servos[i].write(sitPosition[i]);
    }
}
