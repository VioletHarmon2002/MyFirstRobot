# Code
## Front-end

### HTML

#### index.html

#### arrows.html
This document is an HTML5 file. The head section sets the character encoding to UTF-8, ensures the page is responsive, sets the page title, links to an external CSS file for styling, and includes two JavaScript files for functionality, loaded after the document is parsed.

The body section includes several elements: a top bar containing an image and a home button, a header with the main title, a container for buttons arranged in an arrow layout, a standard button for toggling a drawer that shows the robot's connection status, and a hidden drawer displaying connection information. The arrow buttons are used to control a robot, and the drawer provides real-time connection status updates. The linked CSS and JavaScript files provide the necessary styling and functionality for these elements.

#### blockly.html

#### connect.html

#### drag.html

### CSS
#### blockly.css

#### connect.css

#### dragging.css

#### index.css

#### style.css

### Javascript

#### Blockly.js

#### buttons.js
This JavaScript code sets up event listeners for arrow buttons (forwardButton, rightwardButton, leftwardButton) on the arrows webpage. When these buttons are clicked (mousedown event), the sendCommand function is triggered with the corresponding direction ('forward', 'rightward', 'leftward'). This function sends a POST request to the API endpoint (http://IP_ADDR/api.php?action=task) with the specified task. It provides visual feedback on button press and resets when the command is sent or on error. Additionally, it listens for mouseup events to send a stop command when buttons are released.

#### connect.js

#### dragging.js

#### script.js

## Back-end

### api.php

### websocket.php

