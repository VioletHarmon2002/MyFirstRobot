<?php
function sendMessage($message) {
    $host = '172.16.34.136';
    $port = 8080;

    // Maak een TCP/IP socket
    $socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);

    if ($socket === false) {
        $error = "Kon geen socket maken: " . socket_strerror(socket_last_error());
        echo json_encode(['error' => $error]);
        return false;
    }

    // Maak verbinding met de server
    $result = socket_connect($socket, $host, $port);

    if ($result === false) {
        $error = "Kon geen verbinding maken: " . socket_strerror(socket_last_error($socket));
        echo json_encode(['error' => $error]);
        socket_close($socket);
        return false;
    }

    // Stuur het bericht naar de server
    socket_write($socket, $message, strlen($message));

    // Ontvang de reactie van de server (optioneel)
    $response = socket_read($socket, 2048);

    // Sluit de socket
    socket_close($socket);

    // Als er geen fout is opgetreden, retourneer dan een standaardrespons
    if ($response === false) {
        return json_encode(['status' => 'Success']); // Of een andere standaardrespons die je wilt retourneren
    }

    // Encodeer de reactie als JSON
    return $response;
}


// Stuur JSON header
header('Content-Type: application/json');

// Verkrijg het bericht uit de POST-gegevens
$message = file_get_contents('php://input');
$decoded_message = json_decode($message, true);

if ($decoded_message && isset($decoded_message['task'])) {
    $response = sendMessage($decoded_message['task']);
    echo json_encode(['response' => $response]);
} else {
    echo json_encode(['error' => 'Ongeldig bericht']);
}
?>