# Requirements
## Functional requirements
| REQ number | Description | MoSCoW | Date added | Team member | Epic | Worked on sprint |
|---|---|---|---|---|---|---|
| REQ001 | The robot must have a **wow** factor | Must | 24-04 | Gerald | |  1 | 
| | The robot needs to have moving parts and should be able to do precise movements. | | | |
| ~~REQ002~~ | ~~The robot must have moving parts~~ | Wont | 24-04 | Gerald |
| REQ003 | The robot must be easy to assemble for prospective students | Must | 24-04 | Gerald | [#76](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/76) |  1/2 |
| REQ004 | The price per robot must be as low as possible (maximum €20) | Must | 24-04 | Gerald |
| REQ005 | Webapp is a docker IMG that runs on a Raspberry Pi | Must | 24-04 | Gerald |
| REQ006 | The robot must fit in the Smart city sub theme | Must | 24-04 | Gerald |
| | (Smart mobility, Smart buildings, Public safety & security, Efficient government services, Waste management, Low-power sensors & Networks, Smart home networks, Smart supply chain and logistics management, Digital citizen, E-governance, Intelligent farming.)| | | 
| ~~REQ007~~ | ~~There must be a souvenir for family members to take home~~ | Wont | 24-04 |  |
| ~~REQ008~~ | ~~The robot is not faster than 2km an hour~~ | Wont | 24-04 | Floris |
| REQ009 | The webapp must be linked to a domain name that can be changed later (no hardcoding in PHP backend) | Must | 24-04 | Gerald |
| REQ010 | There must be enough pins on the mcu to expand the amount of sensors at a later time. | Must | 24-04 | Gerald |
| REQ011 | The robot is able to be used as learning and teaching platform for other courses | Must | 24-04 | Gerald |
| REQ012 | Security by design - The PHP web backend needs to be secure | Must | 24-04 | Gerald |
| REQ013 | The robot must be easy to dissamble for reuse on other open door days. | Must | 24-04 | Gerald | [#76](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/76) |  1/2 |
| REQ014 | The robots are selected on the webapp by scanning the QR codes printed on them | Must | 24-04 | Silvester |
| REQ015 | The webapp sends universal commands to the robots | Must | 24-04 | Ilias | [#121](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/121) |  2 |
| REQ016 | The robot translates the universal commands to functions | Must | 24-04 | Gjalt | [#121](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/121) |  2 |
| REQ017 | The robot can be controlled with a virtual joystick on the webapp | Must | 24-04 | Floris |
| REQ018 | The robot can be given instructions through codeblocks on the webapp | Must | 24-04 | Gerald | [#121](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/121) |  2 |
| REQ037 | The robot's legs do not collide whilst in operation | Must | 29-05 | Silvester | # | - |
| REQ038 | The robot's body is sturdy and does not break easily | Must | 29-05 | Silvester | # | - |
| REQ039 | ~~Microcontroller has a V-in pin for external power supply~~ | Wont | 29-05 | Silvester | # | - |
| REQ040 | Microcontroller and components are connected through a proto-board | Must | 29-05 | Silvester | # | - |
| REQ041 | The robot is powered by a 9V battery | Must | 05-06 | Gerald | # | - |


## Robot functionalities
| REQ number | Description | MoSCoW | Date added | Team member | Epic | Worked on sprint |
|---|---|---|---|---|---|---|
| REQ019 | The robot can walk forward | Must | 24-05 | Gerald | [#194](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/194) | 2 |
| REQ020 | The robot can run forward | Must | 24-05 | Gerald | n.a | |
| REQ021 | The robot can walk backward | Must | 24-05 | Gerald | n.a |  |
| REQ022 | The robot can turn left | Must | 24-05 | Gerald | [#194](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/194) [#199](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/119)| 2 |
| REQ023 | The robot can turn right | Must | 24-05 | Gerald | [#204](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/204) [#120](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/120)| 2 | 
| REQ024 | The robot can lie down | Must | 24-05 | Gerald | [#211](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/211) | 2 |
| REQ025 | The robot can stand up from lying down | Must | 24-05 | Gerald | [#211](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/211) | 2 |
| REQ026 | The robot can sit down | Must | 24-05 | Gerald | [#211](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/211) | 2 |
| REQ027 | The robot can stand up from sitting down | Must | 24-05 | Gerald | [#211](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/211) | 2 |
| REQ028 | The robot can fall to the left | Must | 24-05 | Gerald | [#211](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/211) |  |
| REQ029 | The robot can stand up from falling to the left | Must | 24-05 | Gerald | [#211](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/211) |  |
| REQ030 | The robot can fall to the right | Must | 24-05 | Gerald | [#211](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/211) |  |
| REQ031 | The robot can stand up from falling to the right | Must | 24-05 | Gerald | [#211](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/issues/211) |  |
| REQ032 | The robot can follow another bot | Could | 24-05 | Gerald | | |
| REQ033 | The robot can follow a line | Could | 24-05 | Gerald | | |
| REQ034 | The robot can wag its tail | Could | 24-05 | Gerald | | |
| REQ035 | The robot can detect objects and avoidance objects | Could | 24-05 | Gerald | | |
| REQ036 | The robot can react to voice commands | Could | 24-05 | Gerald | | |




## Non functional requirements
| REQ number | Description | Date added | Team member |
|---|---|---|---|
| NFR001 | The process of every part of the project must to be well-documented. | 24-04 | Gerald |
| NFR002 | At the end of the sprint 1 there must be three prototypes. | 24-04 | Gerald |
| NFR003 | At the end of sprint 1, a single prototype will be chosen to develop further | 24-04 | Gerald |
| NFR004 | The database is made with MariaDB | 24-04 | Ilias |
| NFR005 | The backend of the webapp is programmed in PHP | 24-04 | Gerald |
| NFR006 | The certification is done with LetsEncrypt | 24-04 | Gerald |
| NFR007 | All code should follow the IoT code conventions, as defined in the individual project | 17-05 | Silvester |
| NFR008 | The web app should follow the HvA style/identity | 17-05 | Gerald |
| NFR009 | The code blocks are made with the **blockly** library | 29-05 | Silvester |
| NFR010 | The robot has a 'face' | 04-06 | Gerald |

# Definition of Done

| DoD number | Description |
|---|---|
| DOD001 | User documentation has been updated with the work that is been done. |
| DOD002 | Code documentation has been updated with the work that is been done. |
| DOD003 | Client documentation (presentation) has been updated with the work that has been done. |
| DOD004 | Webapp documentation has been updated with the work that has been done. |
| DOD005 | Technical documentation has been updated with the work that has been done |
| DOD006 | Design documentation has been updated with the work that has been done. |
| DOD007 | Parts and materials have been added to the BOM. |
| DOD008 | Code conventions have been checked by a teammate who did not code the work. |
| DOD009 | Documentation has been checked by a teammate for mistakes. |
