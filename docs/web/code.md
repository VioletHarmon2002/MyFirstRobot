# Code
## Front-end
### HTML
#### index.html
This document is an HTML5 file. The head section sets the character encoding to UTF-8, ensures the page is responsive, sets the page title, links to an external CSS file for styling, and includes two JavaScript files for functionality, loaded after the document is parsed.

In the body section, the page is divided into several sections. At the top, there's a navigation bar with an image serving as a logo and a button that redirects the user to the homepage. Below this, there is a menu section with a heading "HBO-ICT: Smart Robots". The next section, the redirect-container, includes links to different pages: "Arrows", "Dragging", and "Connect".

At the bottom of the page, there's a button labeled "See connection" which, when clicked, toggles the visibility of a connection status drawer. This drawer displays the connection status of a robot, indicating whether it is connected, and if so, showing the name of the connected entity.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the index.html.html file.
</div>

#### arrows.html
This document is an HTML5 file. The head section sets the character encoding to UTF-8, ensures the page is responsive, sets the page title, links to an external CSS file for styling, and includes two JavaScript files for functionality, loaded after the document is parsed.

The body section includes several elements: a top bar containing an image and a home button, a header with the main title, a container for buttons arranged in an arrow layout, a standard button for toggling a drawer that shows the robot's connection status, and a hidden drawer displaying connection information. The arrow buttons are used to control a robot, and the drawer provides real-time connection status updates. The linked CSS and JavaScript files provide the necessary styling and functionality for these elements.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the arrows.html file.
</div>

#### blockly.html
This document is an HTML5 file. The head section sets the character encoding to UTF-8, ensures the page is responsive, sets the page title, links to an external CSS file for styling, and includes two JavaScript files for functionality, loaded after the document is parsed.

In the body section, the page is structured into several main components. At the top, there is a navigation bar containing a logo and a button to redirect the user to the homepage. Below the navigation bar, the main content area is organized in a flexible row layout. This area includes a large blockly workspace (blocklyDiv) for creating visual programming blocks, with a hidden XML toolbox containing various blocks such as move, turn, controls_if, logic_compare, and more.

Adjacent to the blockly workspace, there is a section for displaying the generated code. This section includes controls for navigating through the program (backward, play, pause, and forward) and an area to display the generated code.

At the bottom of the body, external scripts for Blockly are included, which enable the block-based programming interface. Another script (blockly.js) is included to handle Blockly-specific functionalities.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the blockly.html file.
</div>

#### connect.html
This document is an HTML5 file. The head section sets the character encoding to UTF-8, ensures the page is responsive, sets the page title, links to an external CSS file for styling, and includes two JavaScript files for functionality, loaded after the document is parsed.

In the body section, the page is structured into several components. At the top, there is a navigation bar containing a logo and a button to redirect the user to the homepage. Below this, there is a menu section with a heading "HBO-ICT: Connect to device".

The main content is wrapped in a div with the class wrapper. Within this wrapper, there is a robot-list-container-wrapper which contains a header listing active robots. This container will be populated dynamically via JavaScript. Below this, there is an input field where the user can enter the name of a robot, and a button labeled "Connect to robot" which, when clicked, triggers the connect() function.

At the bottom of the page, there is a button labeled "See connection" which toggles the visibility of a connection status drawer. This drawer displays the robot's connection status, indicating whether it is connected, and if so, showing the name of the connected entity.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the connect.html file.
</div>

#### drag.html
This document is an HTML5 file. The head section sets the character encoding to UTF-8, ensures the page is responsive, sets the page title, links to an external CSS file for styling, and includes three JavaScript files for functionality, loaded after the document is parsed. 

In the body section, the page is structured into several components. At the top, there is a navigation bar containing a logo. Below this, the main content is organized within a div with the class total-container. Inside this container, there are three main sections:
- An empty div with the ID list, which will be populated dynamically.
- A div with the ID draggable-container, to hold draggable elements.
- A div with the ID create-container, containing buttons to create different types of draggable nodes (forward, wait, turn, move, and animation). Each button triggers the createDraggableDiv function with different parameters. There is also an "upload code" button that triggers the uploadProgram function.

At the bottom of the body, there is a button labeled "See connection" to toggle the visibility of a connection status drawer. This drawer displays the robot's connection status, indicating whether it is connected, and if so, showing the name of the connected entity.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the drag.html file.
</div>

### CSS
#### blockly.css
The CSS begins by setting a consistent sans-serif font for all text within the body element, with a margin of 20 pixels around the content to provide spacing from the edges of the browser window.

The #code_display_parent container is styled to visually separate and highlight programming code. It features a background color defined by a custom variable (--hva-color-light), takes up 20% of its parent container's width, and is positioned on the right side of the page. This container also includes padding for additional space and is floated to the right to maintain its position.

Inside #code_display_element, text is displayed in white, ensuring readability against its colored background.

The .program_controlls class ensures that program control elements span the full width of their container, providing a consistent and responsive layout.

Control buttons (control-btn) are styled uniformly: each button occupies 50% of its container's width, has no visible margins or borders, and features a height proportional to 5% of the viewport height (5vh). Text color is set to white, and the font size is standardized at 20 pixels for clear visibility.

Action-specific buttons receive individual styling to differentiate their functionality visually. The #play-btn is designated with a green background color that shifts to a darker shade when hovered over. Similarly, the #pause-btn button features a red background color that darkens upon hover.

Directional buttons (program-direction-button) are distinguished with a light blue background color, transitioning to deeper shades when hovered over or actively pressed (:active state).

The #blocklyDiv element, serves as the main workspace for Blockly programming, is configured to occupy 80% of its container's width while having no visible border.

Styling for Blockly's visual elements includes removing stroke widths (stroke-width: 0px) from the blocklyMainBackground, which maintains a consistent light blue color (#1b97b3). The blocklyFlyout adjusts its width dynamically (width: auto) based on its content, ensuring flexibility in display.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the blockly.css file.
</div>

#### connect.css
The .robot-list-container styles a container for displaying a list of robots. It takes up 100% width and 80% height of its parent, with a gray background and vertical scrolling when content exceeds its height.

.robot-list-container-wrapper uses flexbox to wrap its children with 10px margins between them for spacing.

.robot-name-input styles an input field for entering robot names. It has a light gray background, no border, minimal padding, black text, and a height of 10% of its parent's height with a font size of 3vh.

.btn styles buttons with a medium gray background, no border, generous padding, 10vh height, and changes background color to gray when clicked.

.robot-list-item styles list items with centered text, fixed height, and a light gray background. On hover, it darkens to a medium gray.

.robot-list-header styles the list header with centered text, vertical centering, full width, a specific height, white text on a blue background, and rounded top corners.

These styles collectively create a user-friendly interface for managing and interacting with a list of robots, ensuring clarity and intuitive design for user interaction.


<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the connect.css file.
</div>

#### dragging.css
he body element sets the font family to "Helvetica Neue" for the entire page.

The .draggable class styles the main draggable element with a light gray background and a border.

The .draggable-parent class positions the draggable element and its children in a row layout within an absolutely positioned container, adding padding for spacing.

The #create-container styles a column layout container used for creating draggable buttons, with a fixed width of 200px.

The #upload-button is styled with a light gray background, black text, and padding, suitable for an upload function.

.draggable-button elements are styled as draggable buttons with padding, a move cursor, and a rounded left border, enhancing their interactive usability.

Different block types like .forward, .wait, .move, and .turn are styled with distinct background colors for visual differentiation.

.list-item positions items on the left side with dark text color, using absolute positioning to maintain their layout.

draggable-container styles the main container for draggable blocks with a light gray background, fixed width of 500px, and height of 800px.

.create-draggable-button styles buttons for creating draggable blocks with white text, padding, and rounded corners, promoting user interaction.

.total-container positions the entire draggable block functionality area absolutely, utilizing flexbox to maintain a row layout, spanning the entire width and height of its parent element with a lower z-index for layering.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the dragging.css file.
</div>

#### index.css
The .redirect-container class arranges links in a column layout with centered content. Links have white text on a colored background and change to a darker shade on hover.

The #toggleDrawer ID styles a fixed-position button positioned at the bottom right of the screen. It initially appears with white text and padding, and changes its background color on hover. When it has the open class, it shifts upward to reveal additional content.

The .connection-display-container class styles another fixed-position container, initially positioned off-screen (bottom: -30vh). When it gets the open class, it slides up (bottom: 0px) to display its contents. Inside, there's an h1 element styled with a specific font size.

The .information-container class styles a container with a light background and padding. Inside it, the .information-span class styles spans with a lighter background and padding.

Media queries adjust the layout based on screen width:

For screens narrower than 768px, .redirect-container a adjusts its margins.
For screens 768px or wider, .redirect-container switches to a row layout instead of a column.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the index.css file.
</div>

#### style.css
The :root selector defines custom CSS variables for color scheme consistency throughout the site. It includes dark and light shades, button colors, and text colors.

The body element sets the overall background color and removes default margins and padding.

Various classes (flex-row, .top-bar, .menu, .container, .arrow-container, .left-right-container, .spacer, .btn, .arrow-btn) and IDs (#toggleDrawer) define specific styles for layout, navigation bars, buttons, and arrows.

Media queries adjust styles based on screen width, ensuring responsiveness. For screens narrower than 768px, adjustments include the logo margin and link margins in .redirect-container. For wider screens (768px and above), .redirect-container switches to a row layout to optimize space.

The .redirect-container, .connection-display-container, .information-container, and .information-span classes define styles for various content containers, ensuring consistent padding, background colors, and transitions.

Hover effects (:hover) on buttons (btn, #toggleDrawer) and links (redirect-container a) provide visual feedback to users.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the style.css file.
</div>

### Javascript

#### Blockly.js
This JavaScript code defines several constants and functions. It starts by setting color constants (HVA_DARK_COLOR, HVA_LIGHT_COLOR, forward_color, turn_color) and initializes variables (running, code, formattedCode) used throughout the program.

Two main buttons (play_button and pause_button) are identified from the DOM and immediately hides the play button while showing the pause button (pause() function is called initially).

Key functions include:
readCode(): Attempts to execute the provided code asynchronously using eval(), catching and logging any errors.
play(): Sets up the UI to indicate the program is running by hiding the play button and displaying the pause button.
pause(): Switches the UI state back to paused by hiding the pause button and displaying the play button.
The sleep(seconds) function creates a promise that delays program execution for a specified number of seconds. formatCode() formats the JavaScript code for display purposes by adding line breaks after {}, ;, and returning the formatted code.

Interaction with external APIs is handled by sendCommand(command, value), which constructs and sends a JSON message to a specified API endpoint, logging responses or errors.

The Blockly setup (Blockly.Themes.Halloween, workspace) integrates a custom theme named 'Halloween' and initializes a Blockly workspace (workspace) with predefined blocks (move, print, turn, play_animation, wait). Each block type is associated with a JavaScript code generator (javascriptGenerator.forBlock[type]) that converts block configurations into executable JavaScript code.

Additional functionality includes showCodeOutside(), which generates JavaScript code from the Blockly workspace, formats it, displays it in a designated HTML element (code_display_element), and triggers execution (readCode()).

DOM manipulation (closeFlyout(), openFlyout()) controls the visibility of the Blockly flyout interface, enhancing user interaction.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="">Click here</a>,
to see the code for the blockly.js file.
</div>

#### buttons.js
This JavaScript code sets up event listeners for arrow buttons (forwardButton, rightwardButton, leftwardButton) on the arrows webpage. When these buttons are clicked (mousedown event), the sendCommand function is triggered with the corresponding direction ('forward', 'rightward', 'leftward'). This function sends a POST request to the API endpoint (http://IP_ADDR/api.php?action=task) with the specified task. It provides visual feedback on button press and resets when the command is sent or on error. Additionally, it listens for mouseup events to send a stop command when buttons are released.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/7c909de3468cd1538b87c47c34351c33431865ac/web/static/javascript/buttons.js">Click here</a>,
to see the code for the buttons.js file.
</div>


#### connect.js
This JavaScript code sets up functionality to manage a list of robot names. It initializes an array names_array with several names and defines various constants and DOM elements used throughout the script.

The addRobotNames() function dynamically creates list items (<li>) for each name in names_array and adds them to a designated container (list_container). Each list item gets an event listener so that when clicked, it resets the list's appearance, highlights the clicked item, updates current_name, and logs this name to the console.

The resetList() function resets the background color of all list items to a predefined color (LIST_ITEM_BACKGROUND_COLOR).

The setRobotNameActive(element) function changes the background color of a specified list item to white, updates an input field (INPUT_NAME_ELEMENT) with the clicked item's text, and logs the input's HTML content to the console.

The connect() function retrieves user input from an input field with a specific class (robot-name-input). It logs a connection message and alerts the same message to the user.

The script concludes by invoking addRobotNames() to populate the robot names list when the page loads or the script runs.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/7c909de3468cd1538b87c47c34351c33431865ac/web/static/javascript/connect.js">Click here</a>,
to see the code for the connect.js file.
</div>

#### dragging.js
This JavaScript code sets up a draggable container (#draggable-container) with specified dimensions (CANVAS_WIDTH and CANVAS_HEIGHT). It also defines constants for draggable boundaries (DRAGGABLE_BORDER_X_MIN, DRAGGABLE_BORDER_X_MAX, DRAGGABLE_BORDER_Y_MIN, DRAGGABLE_BORDER_Y_MAX) and a scale (scale).

It initializes arrays to store draggable buttons (create_draggable_buttons, draggable_objects) and a commands_array to manage commands associated with draggable elements.

Functions in the script include:
- addListNumbers(n): Generates numbered list items (<p>) within #list based on a specified count (n), adjusting their positions vertically based on NODE_HEIGHT.
- clampToNearestScale(number): Rounds a number to the nearest multiple of scale.
- loadDraggables(): Attaches draggable functionality to elements with the class .draggable-parent.
- loadCreateDraggables(): Sets up creation functionality for draggable <div> elements using buttons with the class .create-draggable-button.
- createDraggableDiv(id, topPosition, type): Dynamically creates draggable <div> elements with different types (forward, wait, turn, move, animation), each containing specific UI elements like inputs or select dropdowns.
- uploadProgram(): Logs and alerts the commands_array, likely for uploading or exporting purposes.
- setNodeInArray(index, type, value): Updates commands_array with a specified command (type) and its associated value (value).
- findIndexInList(elmnt): Determines the index of a draggable block based on its position relative to NODE_HEIGHT.
- dragElement(elmnt): Enables drag functionality for draggable elements (elmnt) within the specified draggable container, snapping positions to the nearest scale increment.

The script concludes by loading initial draggable elements (loadDraggables()) and setting up creation functionalities (loadCreateDraggables()).

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/7c909de3468cd1538b87c47c34351c33431865ac/web/static/javascript/dragging.js">Click here</a>,
to see the code for the dragging.js file.
</div>

#### script.js
This JavaScript code has seberal variables and constants set up to manage connection information and interact with elements in an HTML document.

connected, connected_to, and connection_speed store data related to the current connection status and details.

Constants like connected_to_name_element, connected_element, and connected_speed_value_element are used to reference specific HTML elements on the page using document.getElementById.

An event listener is attached to an element with ID toggleDrawer. When this element is clicked, it toggles the open class on another element (drawer) and on itself (toggleDrawer), allowing a drawer to open and close on user interaction.

The updatePage() function is called every second (setInterval(updatePage(), 1000)). It dynamically updates the display of elements based on the connected variable. If connected is true, it hides the not_connected_element and shows connected_element and connected_speed. It also updates the content of connected_to_name_element and connected_speed_value_element with the values of connected_to and connection_speed, respectively. If connected is false, it shows not_connected_element and hides connected_element and connected_speed.

The sendCommand(jsonData) function sends a JSON message to an API endpoint (http://172.16.34.136/api.php?action=command) using the fetch API. It sends the JSON data (jsonData) as the body of a POST request with the Content-Type set to application/json. It handles the response from the API, logging the JSON response data to the console if the request is successful, or catching and logging errors if the request fails.


<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/7c909de3468cd1538b87c47c34351c33431865ac/web/static/javascript/script.js">Click here</a>,
to see the code for the script.js file.
</div>

## Back-end

### api.php
This PHP script functions as an API endpoint for handling HTTP requests. It includes send_command.php and get_connections.php to use their functions. The script sets headers to enable Cross-Origin Resource Sharing (CORS) and specifies JSON as the content type. It retrieves the HTTP request method and the action parameter from the URL. Defined functions include send($data) for sending data via sendCommand($data) and validateInput() for validating and forwarding raw POST data to send($data). The handleRequest() function switches based on the request method, handling POST requests for task actions by validating and sending data, and GET requests for connections actions by retrieving connections. It returns appropriate error messages for unsupported actions or request methods. 

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/56918f47ce7e85a0646a3886ccbdeb6bf17fdb3c/web/api.php">Click here</a>,
to see the code for the api.php file.
</div>


### websocket.php
This PHP script listens on a specified host (0.0.0.0) and port (8080). It creates a socket and binds it to the host and port, then starts listening for incoming connections. It maintains an array of client sockets including the server socket itself. The server continuously checks for incoming data from clients and handles various operations based on the received messages, such as accepting new connections, handling disconnections, broadcasting messages to all connected clients except the sender.

The script uses socket functions to manage connections, read and write data, and handle errors. It employs JSON encoding for structured responses and error handling to manage exceptions and ensure proper socket closure upon server termination. 

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/56918f47ce7e85a0646a3886ccbdeb6bf17fdb3c/web/websocket.php">Click here</a>,
to see the code for the websocket.php file.
</div>
