//This class is provided by Bas Pijls
//This is an extention on the StepperMotor
//You need this to run the StepperMotors on the PCB of the Little Endian

#ifndef _LEACCELSTEPPER_H
#define _LEACCELSTEPPER_H

#include "AccelStepper.h" //Library we use to control the StepperMotors

#define NREGPINS 8

class LEAccelStepper : public AccelStepper {

  public:

    typedef enum
    {
      FUNCTION  = 0, ///< Use the functional interface, implementing your own driver functions (internal use only)
      DRIVER    = 1, ///< Stepper Driver, 2 driver pins required
      FULL2WIRE = 2, ///< 2 wire stepper, 2 motor pins required
      FULL3WIRE = 3, ///< 3 wire stepper, such as HDD spindle, 3 motor pins required
      FULL4WIRE = 4, ///< 4 wire full stepper, 4 motor pins required
      HALF3WIRE = 6, ///< 3 wire half stepper, such as HDD spindle, 3 motor pins required
      HALF4WIRE = 8,  ///< 4 wire half stepper, 4 motor pins required
      SHIFT_REGISTER = 9
    } MotorInterfaceType;

    LEAccelStepper(uint8_t interface = LEAccelStepper::FULL4WIRE, uint8_t pin1 = 2, uint8_t pin2 = 3, uint8_t pin3 = 4, uint8_t pin4 = 5, bool enable = true):
    AccelStepper(interface, pin1, pin2, pin3, pin4, enable){
    
    if (enable)
    enableOutputs();

    // Convert pins to shiftregister pins and select pins (0-3 or 4-7) to control woth shift register
    if (_interface == SHIFT_REGISTER) {
        _serPin = _pin[0];
        _rclkPin = _pin[1];
        _srclkPin = _pin[2];
        _selectPins = _pin[3];


        _pin[0] = 0;
        _pin[1] = 2;
        _pin[2] = 1;
        _pin[3] = 3;

        for (int iPin = 0; iPin < 4; iPin++) {
            _pin[iPin] += _selectPins;
        }
    }
}

    // Subclasses can override
    void step(long step);
    

    void setOutputPins(uint8_t mask);


    void enableOutputs();

  private:
    bool registers[8];

    uint8_t _serPin;
    uint8_t _rclkPin;
    uint8_t _srclkPin;
    uint8_t _selectPins;


    //Set and display registers
    //Only call AFTER all values are set how you would like (slow otherwise)
    void writeRegisters();
    //set an individual pin HIGH or LOW
    void setRegisterPin(int index, int value);
    void motorWrite(int index, int value);

};

#endif
