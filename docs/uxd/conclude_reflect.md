# Conclude & reflect

## Demonstration

(add photos or videos that show the final product in all angles and demonstrate the workings of the product)

## Requirements

(Reflect on the requirements, which ones were met and which ones were not met)

These are all our requirements, per requirement is described if it's met or not. The requirements with the *won't* priority are left out.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="../../home/requirements/">Click here</a>
for the full list of requirements, along with the date and who added them..
</div>

## Functional requirements
| REQ number | Description | MoSCoW | Met? | explanation |
|---|---|---|---|---|
| REQ001 | The robot must have a **wow** factor | Must | yes | According to our research, the requirements in the next row impact the wow-factor and our robot has those. |
| | The robot needs to have moving parts and should be able to do precise movements. | | | |
| REQ003 | The robot must be easy to assemble for prospective students | Must | 24-04 | Gerald |
| REQ004 | The price per robot must be as low as possible (maximum €20) | Must | No | We tried to keep the price as low as possible, but it is a bit higher than €20. |
| REQ005 | Webapp is a docker IMG that runs on a Raspberry Pi | Must | No | We have implemented a different method which can be found [here](../web/technical_documentation.md). |
| REQ006 | The robot must fit in the Smart city sub theme | Must | Yes | Our robot fits the smart home theme, because of the user interactability. |
| | (Smart mobility, Smart buildings, Public safety & security, Efficient government services, Waste management, Low-power sensors & Networks, Smart home networks, Smart supply chain and logistics management, Digital citizen, E-governance, Intelligent farming.)| | | |
| REQ009 | The webapp must be linked to a domain name that can be changed later (no hardcoding in PHP backend) | Must | No | Our web-app is not hosted anywhere, the IP-address has to be hardcoded. We have added a recommendation to the recommendations page. |
| REQ010 | There must be enough pins on the mcu to expand the amount of sensors at a later time. | Must | Yes | Our robot uses the ESP32 D0WDQ6 development board, which has enough pins left over for expansion. |
| REQ011 | The robot is able to be used as learning and teaching platform for other courses | Must | Yes | It has a few sensors and can be expanded later for different uses. |
| REQ012 | Security by design - The PHP web backend needs to be secure | Must | No | Not entirely, there is a command filter but not everything is secure. |
| REQ013 | The robot must be easy to dissamble for reuse on other open door days. | Must | Yes | A few team members have tried assembling and dissasembling, and it's not very difficult. We have also made an instruction manual for this. |
| REQ014 | The robots are selected on the webapp by scanning the QR codes printed on them | Must | No | We have decided to use a different method, not involving QR codes. |
| REQ015 | The webapp sends universal commands to the robots | Must | Yes | It sends keyword commands, for example: *forward, left, right, sit, lie*. |
| REQ016 | The robot translates the universal commands to functions | Must | Yes | The robot has a list of keyword, like the ones above that trigger certain functions. |
| REQ017 | The robot can be controlled with a virtual joystick on the webapp | Must | Yes | It's not really a joystick, but directional buttons that control the robot. |
| REQ018 | The robot can be given instructions through codeblocks on the webapp | Must | Yes | Using blockly, our website has code blocks that can be used to create a program that can control the robot. |
| REQ037 | The robot's legs do not collide whilst in operation | Must | Yes | The legs don't hit each other. However, they can hit the side of the body, where the top, bottom and side panels connect. |
| REQ038 | The robot's body is sturdy and does not break easily | Must | Yes | The body is made of 3mm acrylic. It is more than strong enough for our application. This might not be the case for some components however. |
| REQ040 | Microcontroller and components are connected through a proto-board | Must | Yes | On the robot is a protoboard. It has headers and pins for the ESP32 and other components. It also has a connector for a 9V battery. |
| REQ041 | The robot is powered by a 9V battery | Must | Yes | Connected to the protoboard is a 9V battery connector. The battery connects to a voltage regulator on the protoboard which then powers the ESP32 and the servos and other components. |


## Failures

(Describe at least 4 failures during the design and creation process. Per failure, describe:
o    what you wanted to achieve
o    what went wrong  
o    how you tried to solve it  
o    how you would approach the problem next time
ALSO ADD PHOTOS/VIDEOS)