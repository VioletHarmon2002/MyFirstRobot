# Learning journal

## Research story: As a student, i want to research blockly so that i can look if theres a better way to program the code blocks
In order to program the robot, gerald has requested to have a full interface that works well with if statements and more complex blocks, thats why i have decided to look into blockly.

Blockly looks simple and easy to add blocks to, i first looked into the tutprial on the blockly website itself but i struggled with that. Using chatGPT i have found a better explanation. Using chatGPT has helped a lot here.

## Research story: As a student, I want to research the best way to have the robot excecute live code from a string
IN order to have the robot excecute live code, we need to send it and have it interpreted, theres 2 ways to do this from what ive found.
C++ is a very bad language for interpreting live code like this from a string, so it cant really be sent to the arduino and have it interpreted there, unless:
#### Method 1, build a code interpreter
This could be very hard but doable, you would translate every line to a command and if theres a logic line, you would translate that aswell. Like with an if statement you could make a variable, check the if statement for the contents and excecute the code in between the {}. This is very time consuming and could be way too hard, also hard to add more features.
#### Method 2, interpret in javascript
From what ive found in javascript its way easier to interpret all the code and have it excecuted live, this method does however make it so that the robot isnt really doing it autonomous. Instead the phone or laptop is still making it so that the robot moves, its sends the commands line for line and not the intire program. You do need to be connected the robot at all times.

