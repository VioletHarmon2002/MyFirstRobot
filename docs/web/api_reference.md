# API reference
This API is designed to facilitate the communication between the webserver and robot. The API is structured around four main functions, two of which serve as endpoints. These endpoints are POST endpoints for sending data to the robot. 

## command
To use this endpoint, you should make a POST request to the following URL: "http://IP_ADDR/api.php?action=command". This endpoint is designed exclusively to send commands to the robot and accepts data only in JSON format. The mandatory parameter is:

- command (required): command for the robot

When all required parameters are provided, the validateInput function is invoked. This function checks if the provided command is allowed by examining the allowedCommands list. If the command is valid, it calls the send($data) function and returns a JSON-encoded success message. If the command is invalid, it returns a JSON-encoded error message indicating the issue. In the send($data) function, the command is forwarded to a script that communicates with a WebSocket. This WebSocket script is responsible for transmitting the command to the robot.