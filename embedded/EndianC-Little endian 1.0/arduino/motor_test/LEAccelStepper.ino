//This class is provided by Bas Pijls
//This is an extention on the StepperMotor
//You need this to run the StepperMotors on the PCB of the Little Endian

#include "AccelStepper.h" 
#include "LEAccelStepper.h"


void LEAccelStepper::step(long step)
{
    switch (_interface)
    {
    case FUNCTION:
        step0(step);
        break;

    case DRIVER:
        step1(step);
        break;

    case FULL2WIRE:
        step2(step);
        break;

    case FULL3WIRE:
        step3(step);
        break;

    case FULL4WIRE:
        step4(step);
        break;

    case HALF3WIRE:
        step6(step);
        break;

    case HALF4WIRE:
        step8(step);
        break;

    case SHIFT_REGISTER:
        step8(step);
        writeRegisters();
        break;
    }
}

void LEAccelStepper::setOutputPins(uint8_t mask)
{
    uint8_t numpins = 2;
    if (_interface == FULL4WIRE || _interface == HALF4WIRE || _interface == SHIFT_REGISTER)
    numpins = 4;
    else if (_interface == FULL3WIRE || _interface == HALF3WIRE)
    numpins = 3;


    for (uint8_t iPin = 0; iPin < numpins; iPin++)
    motorWrite(_pin[iPin], (mask & (1 << iPin)) ? (HIGH ^ _pinInverted[iPin]) : (LOW ^ _pinInverted[iPin]));
}

void LEAccelStepper::enableOutputs()
{
    Serial.println('e');
    if (! _interface)
    return;

    pinMode(_pin[0], OUTPUT);
    pinMode(_pin[1], OUTPUT);
    if (_interface == FULL4WIRE || _interface == HALF4WIRE)
    {
    pinMode(_pin[2], OUTPUT);
    pinMode(_pin[3], OUTPUT);
    }
    else if (_interface == FULL3WIRE || _interface == HALF3WIRE || _interface == SHIFT_REGISTER)
    {
    pinMode(_pin[2], OUTPUT);
    }

    if (_enablePin != 0xff)
    {
    pinMode(_enablePin, OUTPUT);
    digitalWrite(_enablePin, HIGH ^ _enableInverted);
    }

}
//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void LEAccelStepper::writeRegisters() {
    digitalWrite(_rclkPin, LOW);

    for (int i = NREGPINS - 1; i >=  0; i--) {
    digitalWrite(_srclkPin, LOW);

    int val = registers[i];

    digitalWrite(_serPin, val);
    digitalWrite(_srclkPin, HIGH);

    }
    digitalWrite(_rclkPin, HIGH);
}

//set an individual pin HIGH or LOW
void LEAccelStepper::setRegisterPin(int index, int value) {
    registers[index] = value;
}

void LEAccelStepper::motorWrite(int index, int value) {
    if (_interface == SHIFT_REGISTER)
    setRegisterPin(index, value);
    else
    digitalWrite(index, value);
}
