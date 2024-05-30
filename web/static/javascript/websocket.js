let websocket;

function initWebSocket() {
    websocket = new WebSocket('ws://<your_arduino_ip>:81');
    
    websocket.onopen = function() {
    console.log('WebSocket connection opened');
    };

    websocket.onclose = function() {
    console.log('WebSocket connection closed');
    };

    websocket.onerror = function(error) {
    console.error('WebSocket error:', error);
    };

    websocket.onmessage = function(event) {
    console.log('Received from Arduino:', event.data);
    };
}

function sendCommand(command) {
    if (websocket && websocket.readyState === WebSocket.OPEN) {
    websocket.send(command);
    console.log('Code sent:', command);
    } else {
    console.error('WebSocket is not open');
    }
}

window.onload = initWebSocket;