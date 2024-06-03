<?php

$host = '0.0.0.0'; // Listen on all available interfaces
$port = 8080; // Choose an available port

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
socket_bind($socket, $host, $port);
socket_listen($socket);

$clients = []; // Array to manage multiple clients

echo json_encode(['message' => "Listening for connections on $host:$port"]);

while (true) {
    $read = array_merge([$socket], $clients);
    $write = $except = null;

    // Use select to detect new connections and messages
    if (socket_select($read, $write, $except, 0, 10) < 1) {
        continue;
    }

    // New connection
    if (in_array($socket, $read)) {
        $newClient = socket_accept($socket);
        $clients[] = $newClient;

        // Handshake
        $request = socket_read($newClient, 1024);
        if (preg_match("/Sec-WebSocket-Key: (.*)\r\n/", $request, $matches)) {
            $key = $matches[1];
            $acceptKey = base64_encode(pack('H*', sha1($key . '258EAFA5-E914-47DA-95CA-C5AB0DC85B11')));
            $upgradeResponse = "HTTP/1.1 101 Switching Protocols\r\n" .
                "Upgrade: websocket\r\n" .
                "Connection: Upgrade\r\n" .
                "Sec-WebSocket-Accept: $acceptKey\r\n\r\n";
            socket_write($newClient, $upgradeResponse, strlen($upgradeResponse));
            echo json_encode(['message' => "Connected to a new client"]);
        }
    }

    // Existing connection
    foreach ($clients as $index => $client) {
        if (in_array($client, $read)) {
            $data = @socket_read($client, 1024, PHP_BINARY_READ);
            if ($data === false || $data === '') {
                unset($clients[$index]);
                socket_close($client);
                echo json_encode(['message' => "Client disconnected"]);
                continue;
            }
            $decodedData = unmask($data);
            echo json_encode(['message' => "Received: $decodedData"]);

            // Send to all other clients
            foreach ($clients as $sendClient) {
                if ($sendClient !== $client) {
                    socket_write($sendClient, encode($decodedData));
                }
            }
        }
    }
}

socket_close($socket);

// Function to decode WebSocket data
function unmask($payload) {
    $length = ord($payload[1]) & 127;

    if ($length == 126) {
        $masks = substr($payload, 4, 4);
        $data = substr($payload, 8);
    } elseif ($length == 127) {
        $masks = substr($payload, 10, 4);
        $data = substr($payload, 14);
    } else {
        $masks = substr($payload, 2, 4);
        $data = substr($payload, 6);
    }

    $text = '';
    for ($i = 0; $i < strlen($data); ++$i) {
        $text .= $data[$i] ^ $masks[$i % 4];
    }
    return $text;
}

// Function to encode WebSocket data
function encode($text) {
    $b1 = 0x80 | (0x1 & 0x0f); // FIN + opcode
    $length = strlen($text);

    if ($length <= 125) {
        $header = pack('CC', $b1, $length);
    } elseif ($length > 125 && $length < 65536) {
        $header = pack('CCn', $b1, 126, $length);
    } else {
        $header = pack('CCNN', $b1, 127, $length);
    }

    return $header . $text;
}
?>
