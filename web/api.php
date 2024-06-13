<?php
require 'send_command.php';
require 'get_connections.php';

// Allow CORS
header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

$method = $_SERVER['REQUEST_METHOD'];
$action = isset($_GET['action']) ? $_GET['action'] : '';

function sendDirectly($message){
    sendMessage($message);
    echo json_encode(['status' => 'Message sent', 'data' => $message]);
}

function connections(){
    getConnections();
}

function forward($data) {
    sendMessage($data);
    echo json_encode(['status' => 'Message sent']);
    sendMessage($json_data);
}

function leftward() {
    $data = array(
        'task' => 'leftward'
    );

    $json_data = json_encode($data);

    sendMessage($json_data);
    echo json_encode(['status' => 'Message sent']);
    
}

function rightward() {
    $data = array(
        'task' => 'rightward'
    );

    $json_data = json_encode($data);

    sendMessage($json_data);
    echo json_encode(['status' => 'Message sent']);
    
}

function task(){ 
    $data = json_decode(file_get_contents('php://input'), true);

    if (isset($data['task'])) {
       // switch ($data['task']) {
            //     case 'forward':
            //         forward($data);
            //         break;
            //     case 'leftward':
            //         leftward();
            //         break;
            //     case 'rightward':
            //         rightward();
            //         break;
            //     default:
            //         echo json_encode(["error" => "Unknown task"]);
            //         break;
            // }
        sendDirectly($data);
    } else {
        echo json_encode(["error" => "No task provided"]); 
    }

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
                task();
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
