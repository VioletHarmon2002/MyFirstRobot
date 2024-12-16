# Technical Documentation of arrows HTML

### Overview

This code provides a web-based control page for the robot, allowing users to issue commands for animations, emotes and movement through buttons. These commands are sent to the server using a TCP socket.

#### HTML Structure

- Container for Buttons: Groups buttons for animations, emotes, and movement into distinct sections.

- Button Elements: Each button sends a specific command to the server when clicked.

#### Key Classes:

- `.animate-container`: Contains buttons for animations.
- `.emote-container`: Contains buttons for emotes.
- `.arrow-container`: Contains directional movement buttons.


#### Supported Commands

- **Animation commands**: `Stand`, `Sit`, `Lay`, `Wave`
- **Emote commands**: `Smile`, `Frown`, `Cry`, `Sleep`
- **Movement commands**: `Forward`, `Backward`, `Left`, `Right`