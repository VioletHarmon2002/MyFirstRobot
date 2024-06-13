<?php
function getActiveConnections() {
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

    // Stuur een commando om de actieve verbindingen op te vragen
    $request = "GET_CONNECTIONS";
    socket_write($socket, $request, strlen($request));

    // Lees het antwoord van de server
    $response = socket_read($socket, 1024);
    socket_close($socket);

    // Verwerk het antwoord
    $connections = json_decode($response, true);
    if ($connections === null) {
        return ["error" => "Failed to decode server response"];
    }

    return $connections;
}

// Vraag de actieve verbindingen op
$connections = getActiveConnections();

// Toon de verbindingen
if (isset($connections['error'])) {
    echo "Error: " . $connections['error'] . "\n";
} else {
    echo "Active connections:\n";
    foreach ($connections as $connection) {
        echo "Client: " . $connection['address'] . ":" . $connection['port'] . "\n";
    }
}
?>
