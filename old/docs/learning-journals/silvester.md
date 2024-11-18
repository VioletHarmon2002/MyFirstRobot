# Learning journal

## Learning story - As a student i want to study the little endian 1.0 so we can decide how to imrpove upon it

At the start of the project i started with this learning story to figure out how to little endian 1.0 is put together. I started with the motor test to see if the steppermotors and the shift registers worked. After that i looked at the Accelstepper library to see how the steppermotors are controlled. I also looked at the PCB design to see how the components are connected to each other. 

### Motor_test
[Link to the learning story](../research_stories/Little-endian-1.0-research.md)

An arduino sketch to test the steppermotors and the shift registers

### Potential imrpovements

- 3D printed hold for stepper motors

The stepper motors in the current design are held by tie rips. These need to be broken with scissors whenever you want to disassemble the little endian, this could be improved by making the parts that hold the motor easier to reproduce and reuse. By making a thinly 3d printed part it should fit 
- 2 separate 2AA battery holders
[Link to the requirements list](../home/requirements.md)

## Learning story - As a student, i want to research if the robot dog design can be improved. So i can iterate on our current design

The current battery holder is quite large and takes up a lot of space. 4 AA batteries are needed but by splitting them up in 2 by 2 the space on the little endian could be utilized better.
- Base in plexiglas instead of multiplex

Plexiglas is more durable and more environmentally friendly.
- Increase wheel size and lessen friction with other parts.

The current wheels have some trouble turning, this is partly to blame to the friction the front and back chestnut have with the table. This could maybe be fixed by increasing the 

### Learning story
[Link to the learning story](../research_stories/Robot-dog-improvements.md)

## Learning story - As a student, i want to research where screws could be placed in the current design so that the design is easier to assemble and dissassemble

After we decided to continue with the robot dog for the remainder of the project, i started with this learning story to research where screws could be placed in the current design so that the design is easier to assemble and dissassemble. I looked at the different options we had and decided to use screws to attach the legs to the servos.

[Link to the learning story](../research_stories/robotDog-screws.md)

## Learning story - As a student, i want to research how we can best attach the OLED screen to the base of the robot so we can make it look like our robot has a face 

After we decided to use the OLED screen for the face of the robot, i started with this learning story to figure out how to attach the OLED screen to the base of the robot. I looked at the different options we had and decided to use a lasercut part to attach the OLED screen to the base of the robot.

[Link to the learning story](../research_stories/LCD-mount.md)
