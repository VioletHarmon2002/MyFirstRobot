# Recommendations

## Introduction
These are some recommendations that we have for whichever team picks up this project next.
There are a few features which we could only implement partially before the end of the project. These are some features that we recommend to be implemented in the future.

## Code blocks
For the code blocks there are a couple things that could be added.
### Functionality for the emote block
Currently the emotes are bound to the animations, so when the robot sits, it smiles. You could want it to change so that you could directly tell the robot to smile or frown. The base functionality for this is already added, but there needs to be another part added which is described below
### Additional data to be sent by the api
Currently the messages sent are one dimensional, its just one message like: "forward" or "sit". This means we can have functions like "forward for 2 seconds", since we cant add the value 2. How we do this now is we read how many seconds we want to walk forward and repeat it every one of those seconds on the website. So we send every second the command 'forward' to the robot for the amount of seconds you want to walk.  

This would also need changing on the embedded side, since it doesnt interpret a whole JSON object, but just one line. The API also has a filter for messages going through, so this would also need to be changed to fit a JSON object instead of just one line.

## Sessions
Currently, no session management is implemented when the robot connects to the web server. This means that multiple users can simultaneously access and communicate with the same robot, which can lead to conflicts and unpredictable behavior of the robot. Therefore, we recommend developing a session management system so that each user is assigned a unique session upon connecting to the web server. Ensure that each session is unique and that session data is securely stored and managed.

We already have this on functionality on the website, but it has not been implemented yet. A method for this would be to attach a recipient to each message and have it only read out on the correct robot, this would not require much change, but would also not be very secure.

## Accelerometer
We tested using the MPU9250 9-axis accelerometer, gyroscope, temperature sensor and magnetometer. We are able to read data from the registers using I2C. The data is not yet converted to actual values. This is a feature that could be implemented in the future. We also haven't used the gyroscope/accelerometer values for anything. In the future, they could be used to detect orientation and change the walking animation accordingly.

## Microphone
Due to the storage limitations of the esp32 microcontroller, it's not possible to process the audio locally. So we recommend to send the received audio to a webserver for processing instead. 
Keep in mind voice recognition is a difficult and complex thing to work effectively. 
However, we came across a few projects which could be helpful for implementing voice recognition.

- [Voice recognition V3](https://github.com/elechouse/VoiceRecognitionV3)

- [DFRobot_DF2301Q](https://github.com/DFRobot/DFRobot_DF2301Q)

These projects could bring a promising start for whoever is willing to add voice recognition, be aware it will be a difficult task and time consuming.

## Security
We recommend addressing the following security vulnerabilities currently present in the project:

- Lack of Authentication and Authorization: At present, there is no authentication or authorization mechanism in place, allowing unauthorized users to access the robot and send commands.

- Unencrypted Communication: The communication between the robot and the web server currently occurs over HTTP, which is unencrypted and vulnerable to interception and manipulation.

Addressing these vulnerabilities will significantly enhance the security of the project and reduce the risks of unauthorized access and data breaches.

## PCB
We also recommend to make PCB's in the future. 

- time efficient: In the long run, this is the most time efficient and best option for the board. Especially if you need to make more robot's, we have used proto board because it was the easiest option for us, but it took a long time to make one board.

- easier to expand: because you can already connect all the pins of the esp to an output, it will be easier to expand. Now you need to manually solder wires to the pins itself and then connect it somewhere on the board to the I/O you want to use.

- Best looking: it looks much cleaner then a messy protoboard. This will also improve the "wow" factor of the robot.

## Bigger OLED - Gjalt

To the Next Project Group,

I recommend switching to a larger, square OLED screen for our robot dog's facial expressions.

The current screen is too small and not square, making it difficult to properly display the robot dog's faces. A larger, square OLED screen will provide more space and better proportions, allowing for clearer and more expressive faces.

Using a bigger screen will improve the visual appeal and functionality of our robot dog, making its expressions more lifelike and engaging. This change will enhance user interaction and overall project success.

In summary, a larger, square OLED screen will greatly benefit our robot dog by providing better facial expressions and improving user experience. I highly recommend making this upgrade for future projects.

## Rechargeable battery

To the Next Project Group,

I recommend switching from 9V alkaline batteries to rechargeable 9V batteries for our project.

Rechargeable batteries will save money over time since they can be used many times, unlike single-use alkaline batteries. They are also better for the environment, reducing waste and pollution.

Additionally, rechargeable batteries provide a more reliable power supply and have a longer lifespan. This means fewer interruptions and replacements, allowing us to work more efficiently.

Using rechargeable batteries is convenient, as we won't run out of power and face delays. This switch also demonstrates our commitment to modern technology and sustainability.

In summary, rechargeable 9V batteries are cost-effective, eco-friendly, reliable, and convenient. I highly recommend adopting them for our project.

## Power switch
The robot currently does not have a power switch. This means that the only way to turn the robot on or off is by physically connecting/disconnecting the battery. We recommend adding a power switch to the robot to allow users to easily turn the robot on or off without having to disconnect the battery.

## Database
The project currently has no accosiated database. This means that all data is stored in the memory of the ESP32. This is not ideal as the data is lost when the ESP32 is powered off. We recommend implementing a database to store data such as user settings, user profiles, and robot configurations. This will allow the data to be persistent and accessible across different sessions and devices. We recommend using a lightweight database such as SQLite or MariaDB for this purpose.