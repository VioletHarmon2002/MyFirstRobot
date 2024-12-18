<?php
require 'send_command.php';

// Allow CORS
header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

// Retrieve request method and action
$method = $_SERVER['REQUEST_METHOD'];
$action = isset($_GET['action']) ? $_GET['action'] : '';

// Helper function to send JSON data via sendCommand
function send($data) {
    $json_data = json_encode($data);
    sendCommand($json_data);
}

// Function to validate and process input data
function validateInput() {
    // Decode the JSON input
    $data = json_decode(file_get_contents('php://input'), true);

    // Define allowed commands
    $allowedCommands = ['forward', 'leftward', 'rightward', 'backward', 'lay', 'start', 'wave', 'dance', 'sit'];

    // Validate the input data
    if (is_array($data) && isset($data['command'])) {
        $command = $data['command'];

        // Check if the command is allowed
        if (in_array($command, $allowedCommands)) {
            send($data);
            return ['status' => 'success', 'message' => 'Valid command'];
        } else {
            return ['status' => 'error', 'message' => 'Invalid command'];
        }
    } else {
        return ['status' => 'error', 'message' => 'Invalid input'];
    }
}

// Function to handle incoming requests
function handleRequest() {
    global $method, $action;

    switch ($method) {
        case 'POST':
            if ($action === 'command') {
                $response = validateInput();
                echo json_encode($response); // Send JSON response
            } else if ($action === 'object') {
                $response = sendObject(); // Uncomment and define sendObject if needed
                echo json_encode($response); // Send JSON response
            } else {
                echo json_encode(['status' => 'error', 'message' => 'Unknown action for POST']);
            }
            break;

        default:
            echo json_encode(['status' => 'error', 'message' => 'Unsupported request method']);
            break;
    }
}

// Entry point
handleRequest();
?>
