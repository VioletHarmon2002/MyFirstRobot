# Robot Dog Control Code Documentation

## Overview
This code controls a robot dog using an ESP32 microcontroller. The robot dog connects to a Wi-Fi network, communicates with a server to receive commands, and performs various actions such as walking, sitting, lying down, waving, and dancing. Additionally, it displays facial expressions on an OLED screen to provide visual feedback.

## Libraries Included
- `ESP32Servo.h`: Controls the servo motors.
- `WiFiManager.h`: Manages Wi-Fi connections.
- `WiFiClient.h`: Handles Wi-Fi client connections.
- `ArduinoJson.h`: Parses JSON data.
- `Wire.h`: Manages I2C communication.
- `Adafruit_GFX.h`: Provides graphics functions for the OLED display.
- `Adafruit_SSD1306.h`: Controls the OLED display.

## Constants
- **Server Details**: 
  - `server_ip` and `server_port` define the IP address and port number of the server to which the robot dog connects.
- **Servo Pins**: 
  - `SERVO_FL_PIN`, `SERVO_RL_PIN`, `SERVO_FR_PIN`, `SERVO_RR_PIN` correspond to the pins controlling the front left, rear left, front right, and rear right leg servos.
- **Default Positions and Presets**: 
  - Various constants such as `DEFAULT_POS`, `WALK_OFFSET`, and `WALK_DELAY` define the default positions and offsets for the robot's movements. 
  - Preset angles like `DEFAULT_FL_SIT`, `DEFAULT_FR_SIT`, `DEFAULT_RL_SIT`, and `DEFAULT_RR_SIT` are used for sitting. 
  - `PRESET_FL_LIE`, `PRESET_FR_LIE`, `PRESET_RL_LIE`, `PRESET_RR_LIE` are used for lying down.
- **OLED Display**: 
  - `SCREEN_WIDTH`, `SCREEN_HEIGHT`, and `OLED_RESET` define the dimensions and reset pin for the OLED display. 
  - `SSD1306_I2C_ADDRESS` specifies the I2C address of the display.

## Enums
- **Command**: An enumeration that lists possible commands (`FORWARD`, `BACKWARD`, `LEFT`, `RIGHT`, `SIT`, `LIE`, `WAVE`, `DANCE`, `START`, `UNKNOWN`).

## Objects
- **WiFiManager `Manager`**: Manages the Wi-Fi client connection.
- **Servo Objects**: `FL`, `FR`, `RL`, `RR` control the front left, front right, rear left, and rear right leg servos.
- **Adafruit_SSD1306 `display`**: Manages the OLED display.

## Variables
- **String `currentCommand`**: Stores the current command received from the server.
- **bool `isConnected`**: Tracks the connection status to the server.

## Methods

### setup()
The `setup()` method initializes the system. It sets up serial communication, connects to Wi-Fi using WiFiManager, attaches servos to their respective pins and sets them to their initial positions. It also initializes the OLED display.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L114">Click here</a>,
link to setup() method on git.
</div>

### displayEmote(const unsigned char* bitmap, int width, int height)
The `displayEmote()` method displays a bitmap image on the OLED display. It clears the display, draws the bitmap at the center, and updates the display to show the new image.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L159">Click here</a>,
link to displayEmote() method on git.
</div>

### setFace(String command)
The `setFace()` method sets the facial expression on the OLED display based on the command. Different commands display different bitmaps (`sit`, `lie`, `forward`, `backward`, `dance`, `wave`).

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L165">Click here</a>,
Link to setFace() method on git.
</div>

### dance()
The `dance()` method makes the robot perform a dance sequence. It involves moving the legs in a coordinated pattern. The method defines angles for moving the legs forward and backward and shifts the robot's weight to either side. The sequence is repeated for 10 seconds or until a new command is received. After dancing, the servos return to their default position.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L207">Click here</a>,
Link to dance() method on git.
</div>

### moveToStartPosition()
The `moveToStartPosition()` method moves the servos to the start position. It loops through angles from 0 to 180 degrees in steps of 5, pausing for 50 milliseconds between each step to ensure smooth movement.


<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L306">Click here</a>,
Link to moveToStartPosition() method on git.
</div>

### lieDown()
The `lieDown()` method moves the legs to the lying down position using preset angles (`PRESET_FL_LIE`, `PRESET_FR_LIE`, `PRESET_RL_LIE`, `PRESET_RR_LIE`). It sets each servo to the preset lying down angles.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L317">Click here</a>,
LLink to lieDown() method on git.
</div>


### sit()
The `sit()` method moves the legs to the sitting position using preset angles (`DEFAULT_FL_SIT`, `DEFAULT_FR_SIT`, `DEFAULT_RL_SIT`, `DEFAULT_RR_SIT`). It sets each servo to the preset sitting angles.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L326">Click here</a>,
Link to sit() method on git.
</div>

### wave()
The `wave()` method performs a waving motion. It lifts the front left leg to the `WAVE_UP` position and pauses for 500 milliseconds, then lowers the leg to the `WAVE_DOWN` position and pauses again. This sequence is repeated three times, and the leg returns to the default position after waving.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="hhttps://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L335">Click here</a>,
Link to wave() method on git.
</div>

### leftStep()
The `leftStep()` method moves the legs to perform a left step. It sets the angles of the servos to specific positions (`FR.write(90)`, `FL.write(60)`, `RL.write(110)`, `RR.write(120)`) and pauses between each step to ensure smooth movement.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L347">Click here</a>,
Link to leftStep() method on git.
</div>


### rightStep()
The `rightStep()` method moves the legs to perform a right step. It sets the angles of the servos to specific positions (`FL.write(90)`, `FR.write(120)`, `RR.write(70)`, `RL.write(60)`) and pauses between each step to ensure smooth movement.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L357">Click here</a>,
Link to rightStep() method on git.
</div>

### walkForward()
The `walkForward()` method makes the robot walk forward by alternating between `leftStep()` and `rightStep()` for 5 seconds. After walking, it resets all servos to the default position.


<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="hhttps://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L367">Click here</a>,
Link to walkForward() method on git.
</div>


### walkBackwards()
The `walkBackwards()` method makes the robot walk backward. It involves lifting the back legs and tilting the front legs. The method repeats this sequence for 5 seconds and then resets all servos to the default position.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L385">Click here</a>,
Link to walkBackwards() method on git.
</div>

### turnRight()
The `turnRight()` method turns the robot right. It adjusts the servo positions to specific angles for turning right (`TURN_RIGHT_FL`, `TURN_RIGHT_FR`, `TURN_RIGHT_RL`, `TURN_RIGHT_RR`). The robot moves back to the default position smoothly and repeats the sequence for 5 seconds before resetting all servos.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L417">Click here</a>,
Link to turnRight() method on git.
</div>

### turnLeft()
The `turnLeft()` method turns the robot left. It adjusts the servo positions to specific angles for turning left (`TURN_LEFT_FL`, `TURN_LEFT_FR`, `TURN_LEFT_RL`, `TURN_LEFT_RR`). The robot moves back to the default position smoothly and repeats the sequence for 5 seconds before resetting all servos.


<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L446">Click here</a>,
Link to turnLeft() method on git.
</div>

### getCommand(const String& command)
The `getCommand()` method converts a string command to a `Command` enum. It maps string commands to corresponding `Command` enum values and returns the appropriate enum value or `UNKNOWN` if the command is not recognized.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L475">Click here</a>,
Link to getCommand() method on git.
</div>

### handleCommand(String command)
The `handleCommand()` method executes the command received from the server. It calls the appropriate function based on the command (`walkForward()`, `walkBackwards()`, `turnLeft()`, `turnRight()`, `sit()`, `lieDown()`, `wave()`, `dance()`, `moveToStartPosition()`). If the command is unrecognized, it prints "Unknown command."

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L488">Click here</a>,
Link to handleCommand() method on git.
</div>

### loop()
The `loop()` method is the main loop function. It continuously checks and maintains the server connection, reads and parses incoming JSON data, extracts and executes commands, and sets the face expression on the OLED display based on the command. If the connection is lost, it attempts to reconnect. A small delay is added to avoid overwhelming the loop.


<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/dev/embedded/EndianB-Robot%20dog/main/main.ino?ref_type=heads#L523">Click here</a>,
Link to loop() method on git.
</div>

## Bitmaps
Includes bitmap header files:
- `smile_bitmap.h`: Bitmap for the smiling face.
- `frown_bitmap.h`: Bitmap for the frowning face.
- `idle_bitmap.h`: Bitmap for the idle face.

## Usage
1. Upload the code to an ESP32 microcontroller.
2. Ensure the robot dog is powered and connected to the Wi-Fi network.
3. Use a server to send commands to the robot dog.
4. Observe the robot dog's actions and facial expressions based on the received commands.

This code provides a comprehensive control system for a robot dog, utilizing Wi-Fi for remote commands and servos for movement, while also offering visual feedback through an OLED display.