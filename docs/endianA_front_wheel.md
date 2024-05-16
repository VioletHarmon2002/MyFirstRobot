# Endian A front wheel research 

What is the best way to turn the front wheel of endian A.

## The Motor

For the motor we have 2 main options, We have the **servo** and we have a **steppermotor**.

### Servo

- Pro: Easy to control and program.
- Pro: Can provide precise control over the rotation angle.
- Pro: Can provide high torque at low speeds.
- Pro: Can be less expensive compared to a stepper motor.
- Pro: Is faster then a stepper motor.
- Con: Cannot hold position without power.
- Con: Limited range of motion.
- Con: Can produce less torque compared to a stepper motor.

### Stepper Motor

- Pro: Precise control over the rotation angle and position.
- Pro: Can hold position without power.
- Pro: Can provide high torque at low speeds.
- Con: Can be more expensive than a servo motor.
- Con: Can be more complex to control and program.
- Con: Can produce more noise and vibration compared to a servo motor.
- Con: Cheap stepper motors are very slow.


### Conclusion

Based on these pro's and con's we decided to use a servo motor, because the servo is cheap, fast and easy to prgram. 

## Design

with the design of [remrc](https://www.thingiverse.com/thing:5887157/files). I have chosen to copy his design for the wheels. The files talked about are [here](../3D-Design/STLS/EndianA/wheels/). We are going to 3d print these disigns and test if they are usable for our project.
