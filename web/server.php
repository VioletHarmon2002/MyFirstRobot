<?php
// Define the host and port to listen on
$host = '0.0.0.0'; // Listen on all available interfaces
$port = 8080;

// Create a socket
$serversocket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($serversocket === false) {
    echo json_encode(["error" => "Failed to create socket: " . socket_strerror(socket_last_error())]);
    exit;
}

// Bind the socket to the specified host and port
if (socket_bind($serversocket, $host, $port) === false) {
    echo json_encode(["error" => "Failed to bind socket: " . socket_strerror(socket_last_error($serversocket))]);
    exit;
}

// Listen for incoming connections
if (socket_listen($serversocket, 5) === false) { // Allow up to 5 pending connections
    echo json_encode(["error" => "Failed to listen on socket: " . socket_strerror(socket_last_error($serversocket))]);
    exit;
}

echo json_encode(["message" => "Waiting for connections on port $port..."]) . "\n";

// Array to hold client sockets
$clients = [$serversocket];

function is_valid_string($s) {
    return !is_numeric($s) && !empty($s);
}

try {
    while (true) {
        // Create a copy of the clients array for use with socket_select
        $read_sockets = $clients;
        $write = NULL;
        $except = NULL;

        // Get the list of sockets that are ready for reading
        if (socket_select($read_sockets, $write, $except, NULL) < 1) {
            continue;
        }

        // Check if there is a new connection
        if (in_array($serversocket, $read_sockets)) {
            $new_client = socket_accept($serversocket);
            if ($new_client === false) {
                echo json_encode(["error" => "Failed to accept connection: " . socket_strerror(socket_last_error($serversocket))]);
            } else {
                $clients[] = $new_client;
                socket_getpeername($new_client, $client_address, $client_port);
                echo json_encode(["message" => "New client connected: $client_address"]) . "\n";
            }
            unset($read_sockets[array_search($serversocket, $read_sockets)]);
        }

        // Check each client socket for incoming data
        foreach ($read_sockets as $socket) {
            $data = @socket_read($socket, 1024, PHP_BINARY_READ);
            if ($data === false || $data === "") {
                // Client disconnected, remove from clients array
                socket_getpeername($socket, $client_address, $client_port);
                echo json_encode(["message" => "Client disconnected: $client_address"]) . "\n";
                unset($clients[array_search($socket, $clients)]);
                socket_close($socket);
                continue;
            }

            $data = trim($data);
            if (!is_valid_string($data)) {
                echo json_encode(["error" => "Invalid input from client. Please enter a valid string."]) . "\n";
                continue;
            }

            // Broadcast the message to all other clients
            foreach ($clients as $client_socket) {
                if ($client_socket !== $serversocket && $client_socket !== $socket) {
                    socket_write($client_socket, $data, strlen($data));
                }
            }
        }
    }
} catch (Exception $e) {
    echo json_encode(["error" => "Server stopped: " . $e->getMessage()]) . "\n";
} finally {
    // Close all client sockets
    foreach ($clients as $socket) {
        socket_close($socket);
    }
    // Close the server socket
    socket_close($serversocket);
}
?>

