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

## Accelerometer

## Microphone

## Security

## PCB

## Bigger OLED

## Rechargeable battery

## Database