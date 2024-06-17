<?php
function getActiveConnections() {
    $host = '145.3.249.252';
    $port = 8080;

    $clientsocket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
    if ($clientsocket === false) {
        return ["error" => "Failed to create socket: " . socket_strerror(socket_last_error())];
    }

    if (socket_connect($clientsocket, $host, $port) === false) {
        socket_close($clientsocket);
        return ["error" => "Failed to connect to server: " . socket_strerror(socket_last_error($clientsocket))];
    }

    $request = "GET_CONNECTIONS";
    socket_write($clientsocket, $request, strlen($request));

    $response = '';
    while ($chunk = socket_read($clientsocket, 2048)) {
        $response .= $chunk;
    }
    socket_close($clientsocket);

    // Log raw server response
    error_log("Raw server response: " . $response);

    $connections = json_decode($response, true);
    if ($connections === null) {
        return ["error" => "Failed to decode server response: " . json_last_error_msg()];
    }

    // Directly output the JSON encoded result
    header('Content-Type: application/json');
    echo json_encode(getActiveConnections());
}
?>