<?php
require 'send_command.php';

// Allow CORS
header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

$method = $_SERVER['REQUEST_METHOD'];
$action = isset($_GET['action']) ? $_GET['action'] : '';

function send($data) {
    $json_data = json_encode($data);
    sendCommand($json_data);
}

function validateInput() {
    // Decode the JSON input
    $data = json_decode(file_get_contents('php://input'), true);

    // Defined the allowed commands
    $allowedCommands = ['forward', 'leftward', 'rightward', 'backward', 'lay', 'start', 'wave', 'dance', 'sit'];

    // Check if the input data is an array and contains the 'command' key
    if (is_array($data) && isset($data['command'])) {
        // Get the command from the input data
        $command = $data['command'];

        // Validate the command
        if (in_array($command, $allowedCommands)) {
            send($data);
            return json_encode(['status' => 'success', 'message' => 'Valid command']);
        } else {
            return json_encode(['status' => 'error', 'message' => 'Invalid command']);
        }
    } else {
        return json_encode(['status' => 'error', 'message' => 'Invalid input']);
    }
}

// Function for sending a Json object, WORK IN PROGESS

// function sendObject(){
//     $data = json_decode(file_get_contents('php://input'), true);
//     send($data);
//     return json_encode(['status' => 'success', 'message' => 'Valid command']);
// }

function handleRequest() {
    // Retrieve global variables $method and $action
    global $method, $action;

    // Switch statement to handle different request methods
    switch ($method) {
        case 'POST':
            if ($action == 'command') {
                validateInput();
            } else if ($action == 'object'){
                sendObject();
            } 
            
            else {
                // Respond with an error message if action is unknown for POST requests
                echo json_encode(["error" => "Unknown action for POST"]);
            }
            break;

        default:
            // Respond with an error message if request method is unsupported
            echo json_encode(["error" => "Unsupported request method"]);
            break;
    }
}

handleRequest();
?>
