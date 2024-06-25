# Assembly guide

This following document will take you through the assembly process of the robot dog in a step by step mannner. 

The assembly requires a philips head screwdriver and the following parts:
![robotDog legend](../assets/robotDog-lagenda.PNG)


### Step 1 - Risers
We'll first start by attaching the risers to the top plate. The risers are the 2.4x16mm risers. You'll need 3 of them. These are to mount the protoboard on later.

![step1](../assets/assembly/step1-1.png)

Use the bolt to tighten the riser to the top baseplate.

![step1](../assets/assembly/step1-2.png)

![step1](../assets/assembly/step1-3.png)

### Step 2 - Sides
Put the top baseplate aside for now. We'll now attach the sides to the bottom baseplate.

![step2](../assets/assembly/step2-1.png)

Take care, the holes for the servo's in the sides are not the same. The sqaure hole is for the servo that will be placed at the front of the robot dog. The round hole is for the servo that will be placed at the back of the robot dog. The slots in the base and top plate are for the baseplate connectors. These slots are not symmetrical. The slots which are further to the side correspond to the front of the robot dog and as such the sqaurer hole in the side plate.

The front of the robot also has an addional slit in which we will later place the face mount.

![step2](../assets/assembly/step2-2.png)

You can simply put the sides on side parts of the bottom plate.

![step2](../assets/assembly/step2-3.png)

![step2](../assets/assembly/step2-4.png)

![step2](../assets/assembly/step2-5.png)

### Step 3 - Servo's
Now we'll attach the servo's to the sides. The servo's are the SG90 Mini servo's. You'll need 4 of them.

![step3](../assets/assembly/step3-1.png)

Slot the servo's into the holes in the side plates.

They should fit snuggly.

![step3](../assets/assembly/step3-2.png)

![step3](../assets/assembly/step3-3.png)

![step3](../assets/assembly/step3-4.png)

### Step 4 - baseplate connectors
Now we'll place the baseplate connectors in the slots of the bottom plate.
These connectors are used to connect the top and bottom plate and also to hold the servo's we just placed in place.

![step4](../assets/assembly/step4-1.png)

The baseplate connectors should fit snuggly in the slots on the baseplate.

![step4](../assets/assembly/step4-2.png)

Make sure whilst placing the baseplate connectors that the servo's are still well in place.

![step4](../assets/assembly/step4-3.png)

![step4](../assets/assembly/step4-4.png)

### Step 5 - top plate
Now we'll place the top plate on the bottom plate, connectors and sides.

![step5](../assets/assembly/step5-1.png)

It's quite a tight fit and could require some wiggling to get it in place.

![step5](../assets/assembly/step5-2.png)

All the baseplate connectors should be fully inside the bottom and top plate and the sides should be in between the top and bottom plate prongs.

![step5](../assets/assembly/step5-3.png)

### Step 6 - 3.9mm bolts
Now we'll attach the top and bottom plate together using the 3.9mm bolts.
The plates shouldnt fall apart easily but these bolts will make sure they stay together.

![step6](../assets/assembly/step6-1.png)

![step6](../assets/assembly/step6-2.png)

Make sure you dont tighten the nuts too tightly as you might shatter the plexiglass. It should feel tight but dont turn them too much.

![step6](../assets/assembly/step6-3.png)

### Step 7 - Legs 
This step requires the philips head screwdriver. We'll attach the legs to the servo's. 

![step7](../assets/assembly/step7-1.png)

You can turn the robot dog upside down to make this step easier.

Slot the legs onto the servo's and screw them on tightly

![step7](../assets/assembly/step7-2.png)

When you move the leg afterwards you should be able to hear the servo turn with it.

![step7](../assets/assembly/step7-3.png)

![step7](../assets/assembly/step7-4.png)

![step7](../assets/assembly/step7-5.png)

### Step 8 - Face mount
Now we'll attach the face mount to the front of the robot dog.

![step8](../assets/assembly/step8-1.png)

The face mount should fit nicely in the slit in the front of the robot dog.

![step8](../assets/assembly/step8-2.png)

### Step 9 - Protoboard
Now we'll attach the protoboard to the risers on the top plate.
On this protoboard the ESP32 will be placed. The servo's and power supply will also be connected to this board. 

![step9](../assets/assembly/step9-1.png)

![step9](../assets/assembly/step9-2.png)

![step9](../assets/assembly/step9-3.png)

### Step 10 - Power supply
Now we'll place the power supply on the bottom plate. The power supply is a 9v battery. Place the battery in the middle slot. it should fit in tightly.

![step10](../assets/assembly/step10-1.png)

![step10](../assets/assembly/step10-2.png)

You could now connect the power to the protoboard. Keep in mind that as soon as it is connected the robot dog will be powered on.
We advise to connect the power supply last.

### Step 11 - Breadboard
The breadboard is included in this design to offer extra spots for connecting components. The breadboard is not necessary for the robot dog to function. But if you want to expand upon the robot dog's capabilities you can use the breadboard to connect extra components.

It is placed on the top plate between the face mount and the battery

![step11](../assets/assembly/step11-1.png)

You can simply stick the breadboard on the top plate. It should fit snuggly between the battery and the face mount.

Try out the placement before sticking it on.

![step11](../assets/assembly/step11-2.png)

![step11](../assets/assembly/step11-3.png)

![step11](../assets/assembly/step11-4.png)

### Step 12 - OLED display
The OLED display is placed on the face mount. The display is used to let the robot dog showcase its emotions. The display is connected to the protoboard.

![step12](../assets/assembly/step12-1.png)

The OLED is held on the face mount by two bolts and nuts. The bolts go through the holes in the face mount and the OLED display. The nuts are then screwed on the bolts to hold the OLED display in place.

![step12](../assets/assembly/step12-2.png)

### Step 13 - ESP & Wiring
Lastly we'll place the ESP32 on the protoboard and connect the servo's and power supply to the protoboard.

![step13](../assets/assembly/step13-1.png)

The ESP32 is placed in the middle of the protoboard. The servo's are connected to the pins on the ESP32. The power supply is connected to battery connector on the protoboard. And the OLED is also connected through the pins on the protoboard

![step13](../assets/assembly/step13-2.png)

You should connect the wires to the servo's on the protoboard. Make sure to connect the brown wire from the servo to the black wire on the protoboard.

If you look at the protoboard from where the mini usb comes in that would be the back. The servo's are wired to their respective sides on the protoboards. The front servo's are wired to the front of the protoboard and the back servo's are wired to the back of the protoboard.

![step13](../assets/assembly/step13-3.png)

![step13](../assets/assembly/step13-4.png)

With this final step the robot dog is fully assembled and ready to be powered on. 

