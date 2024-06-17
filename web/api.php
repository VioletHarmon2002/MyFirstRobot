<?php
require 'send_command.php';
require 'get_connections.php';

// Allow CORS
header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

$method = $_SERVER['REQUEST_METHOD'];
$action = isset($_GET['action']) ? $_GET['action'] : '';

function send($data){
    sendCommand($data);
}

function connections(){
    getConnections();
}

function validateInput(){ 
    $data = file_get_contents('php://input');
    send($data);
}

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
                // Call function to handle submission of new data
                connections();
            } else {
                // Respond with an error message if action is unknown for POST requests
                echo json_encode(["error" => "Unknown action for get"]);
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
