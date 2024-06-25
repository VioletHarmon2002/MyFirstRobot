# Recommendations

## Introduction
These are some recommendations that we have for whichever team picks up this project next.
There are a few features which we could only implement partially before the end of the project. These are some features that we recommend to be implemented in the future.

## Code blocks - Floris

## Sessions
Currently, no session management is implemented when the robot connects to the web server. This means that multiple users can simultaneously access and communicate with the same robot, which can lead to conflicts and unpredictable behavior of the robot. Therefore, we recommend developing a session management system so that each user is assigned a unique session upon connecting to the web server. Ensure that each session is unique and that session data is securely stored and managed

## Accelerometer
We tested using the MPU9250 9-axis accelerometer, gyroscope, temperature sensor and magnetometer. We are able to read data from the registers using I2C. The data is not yet converted to actual values. This is a feature that could be implemented in the future. We also haven't used the gyroscope/accelerometer values for anything. In the future, they could be used to detect orientation and change the walking animation accordingly.

## Microphone - Timo

## Security
We recommend addressing the following security vulnerabilities currently present in the project:

- Lack of Authentication and Authorization: At present, there is no authentication or authorization mechanism in place, allowing unauthorized users to access the robot and send commands.

- Unencrypted Communication: The communication between the robot and the web server currently occurs over HTTP, which is unencrypted and vulnerable to interception and manipulation.

Addressing these vulnerabilities will significantly enhance the security of the project and reduce the risks of unauthorized access and data breaches.
## PCB - Luc

## Bigger OLED - Gjalt

## Rechargeable battery - Gjalt

## Database - Silvester