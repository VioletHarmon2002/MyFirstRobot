<?php
// Require external scripts for sending commands and getting connections
require 'send_command.php';
require 'get_connections.php';

// Allow CORS (Cross-Origin Resource Sharing) and set the content-type header to JSON
header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

// Retrieve the HTTP request method and the action parameter from the URL (if present)
$method = $_SERVER['REQUEST_METHOD'];
$action = isset($_GET['action']) ? $_GET['action'] : '';

// Function to send data using the sendCommand function from send_command.php
function send($data){
    sendCommand($data);
}

// Function to get connections using the getConnections function from get_connections.php
function connections(){
    getConnections();
}

// Function to validate input and forward it to the send function
function validateInput(){ 
    $data = file_get_contents('php://input'); // Get raw POST data
    send($data); // Forward the retrieved data
}

// Main function to handle the incoming request
function handleRequest() {
    // Retrieve global variables $method and $action
    global $method, $action;

    // Switch statement to handle different request methods
    switch ($method) {
        case 'POST':
            // Check if the action is to submit new data
            if ($action == 'task') {
                // Call function to handle submission of new data
                validateInput();
            } else {
                // Respond with an error message if action is unknown for POST requests
                echo json_encode(["error" => "Unknown action for POST"]);
            }
            break;
        case 'GET':
            if ($action == 'connections') {
                // Call function to handle retrieval of connections
                connections();
            } else {
                // Respond with an error message if action is unknown for GET requests
                echo json_encode(["error" => "Unknown action for GET"]);
            }
            break;
        default:
            // Respond with an error message if request method is unsupported
            echo json_encode(["error" => "Unsupported request method"]);
            break;
    }
}

// Call the main function to handle the request
handleRequest();
?>

