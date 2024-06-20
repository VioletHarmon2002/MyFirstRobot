<?php
function sendCommand($command) {
    // Define the server host and port to connect to
    $host = '172.20.10.2'; // Server IP address
    $port = 8080; // Server port number

    // Create a TCP socket
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

    // Send the command to the server
    if (socket_write($clientsocket, $command, strlen($command)) === false) {
        echo json_encode(["error" => "Failed to send command: " . socket_strerror(socket_last_error($clientsocket))]) . "\n";
    } else {
        echo json_encode(["message" => "Command sent to server: " . $command]) . "\n";
    }

    // Close the socket connection
    socket_close($clientsocket);
}
?>
