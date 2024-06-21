# Code
## Front-end

### HTML

#### index.html

#### arrows.html
This document is an HTML5 file. The head section sets the character encoding to UTF-8, ensures the page is responsive, sets the page title, links to an external CSS file for styling, and includes two JavaScript files for functionality, loaded after the document is parsed.

The body section includes several elements: a top bar containing an image and a home button, a header with the main title, a container for buttons arranged in an arrow layout, a standard button for toggling a drawer that shows the robot's connection status, and a hidden drawer displaying connection information. The arrow buttons are used to control a robot, and the drawer provides real-time connection status updates. The linked CSS and JavaScript files provide the necessary styling and functionality for these elements.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the arrows.html file.
</div>

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

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the buttons.js file.
</div>


#### connect.js

#### dragging.js

#### script.js

## Back-end

### api.php
This PHP script functions as an API endpoint for handling HTTP requests. It includes send_command.php and get_connections.php to use their functions. The script sets headers to enable Cross-Origin Resource Sharing (CORS) and specifies JSON as the content type. It retrieves the HTTP request method and the action parameter from the URL. Defined functions include send($data) for sending data via sendCommand($data) and validateInput() for validating and forwarding raw POST data to send($data). The handleRequest() function switches based on the request method, handling POST requests for task actions by validating and sending data, and GET requests for connections actions by retrieving connections. It returns appropriate error messages for unsupported actions or request methods. 

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the api.php file.
</div>


### websocket.php
This PHP script listens on a specified host (0.0.0.0) and port (8080). It creates a socket and binds it to the host and port, then starts listening for incoming connections. It maintains an array of client sockets including the server socket itself. The server continuously checks for incoming data from clients and handles various operations based on the received messages, such as accepting new connections, handling disconnections, broadcasting messages to all connected clients except the sender.

The script uses socket functions to manage connections, read and write data, and handle errors. It employs JSON encoding for structured responses and error handling to manage exceptions and ensure proper socket closure upon server termination. 

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the websocket.php file.
</div>
