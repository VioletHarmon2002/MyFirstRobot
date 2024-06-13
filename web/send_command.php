<?php
function sendMessage($message) {
    // Define the server host and port to connect to
    $host = '145.28.188.103';
    $port = 8080;

    // Create a socket
    $clientsocket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
    if ($clientsocket === false) {
        echo json_encode(["error" => "Failed to create socket: " . socket_strerror(socket_last_error())]) . "\n";
        exit;
    }

    // Connect the socket to the specified host and port
    if (socket_connect($clientsocket, $host, $port) === false) {
        echo json_encode(["error" => "Failed to connect to server: " . socket_strerror(socket_last_error($clientsocket))]) . "\n";
        socket_close($clientsocket);
        exit;
    }

    echo json_encode(["message" => "Connected to server at $host:$port"]) . "\n";



    // Send the JSON-encoded test message to the server
    if (socket_write($clientsocket, $message, strlen($message)) === false) {
        echo json_encode(["error" => "Failed to send message: " . socket_strerror(socket_last_error($clientsocket))]) . "\n";
    } else {
        echo json_encode(["message" => "Test message sent to server: $json_message"]) . "\n";
    }

    // Close the socket connection
    socket_close($clientsocket);
}
?>