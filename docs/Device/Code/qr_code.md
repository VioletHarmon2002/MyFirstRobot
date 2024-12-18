# Documentation for MAC Address-Based QR Code Integration

## 1. QR Code Generator
The QR code generation feature uses the device's MAC address as its unique identifier. This MAC address is retrieved, formatted, and can be embedded in a QR code for scanning purposes.

### 1.1 Python QR Code Generator
- **Purpose**: Generate a QR code using a MAC address (without colons) and save it as an image file.

#### Code:
```python
import qrcode

def create_qr_code():
    print("Welcome to the QR Code Generator!")
    user_input = input("Please enter the mac address without ':' to generate a QR code: ")
    link = "http://192.168.178.66/index.html?id=" + user_input
    # Generate QR code
    qr = qrcode.QRCode(
        version=1,  # Controls the size of the QR Code (1 is 21x21, higher is larger)
        error_correction=qrcode.constants.ERROR_CORRECT_L,  # Error correction level
        box_size=10,  # Size of each box in the QR code grid
        border=4,  # Thickness of the border (minimum is 4)
    )
    qr.add_data(link)
    qr.make(fit=True)

    # Create and save the QR code image
    img = qr.make_image(fill_color="black", back_color="white")
    file_name = input("Enter the file name to save the QR code (without extension): ") + ".png"
    img.save(file_name)

    print(f"QR code generated and saved as {file_name}")

if __name__ == "__main__":
    create_qr_code()
```

### 1.2 Embedded Code for MAC Address Retrieval
- **File**: `mac_address.cpp`
- **Purpose**: Retrieve the MAC address from the device, remove colons, and return it as a string.

#### Code:
```cpp
#include "mac_address.h"
#include <WiFi.h>
#include <Arduino.h>

String MACAddressHelper::getMACAddress() {
    String mac = WiFi.macAddress();  // Get the MAC address with colons
    mac.replace(":", "");           // Remove the colons
    return mac;                     // Return the MAC address without colons
}
```

---

## 2. Web Application Logic

### 2.1 Saving Robot ID to Local Storage
- **Purpose**: Save the scanned robot ID (from a URL or QR code) in the user's browser for persistent use.

#### Key Functions:
- `saveRobotId`: Extracts the `id` parameter from the URL and stores it in `localStorage`.
- `getSavedRobotId`: Retrieves the stored robot ID from `localStorage`.

#### Code (Extract from `script.js`):
```javascript
function saveRobotId() {
    const robotId = getQueryParam('id');
    if (robotId) {
        localStorage.setItem('robotId', robotId);
        console.log(`Robot ID saved to localStorage: ${robotId}`);
    } else {
        console.log('No robot ID found in URL.');
    }
}

function getSavedRobotId() {
    return localStorage.getItem('robotId');
}
```

---

### 2.2 Sending Commands to the Server
- **Purpose**: Send commands along with the saved robot ID to the server for processing.

#### Code (From `buttons.js`):
```javascript
const sendCommand = (command) => {
    const robotId = getSavedRobotId();
    const data = { command, robotId };

    fetch('http://192.168.178.66/api.php?action=command', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    })
    .then(response => response.json())
    .then(data => {
        console.log('API response:', data);
    })
    .catch(error => {
        console.error('Fetch operation failed:', error);
    });
};
```

---

## 3. Server-Side Logic

### 3.1 Command Handling
- **File**: `api.php`
- **Purpose**: Validate and process incoming commands.

#### Implementation:
1. Extract the JSON payload.
2. Validate the command against a predefined list.
3. Send the command to the appropriate endpoint/device.

#### Key Code:
```php
function validateInput() {
    $data = json_decode(file_get_contents('php://input'), true);
    $allowedCommands = ['forward', 'leftward', 'rightward', 'backward', 'lay', 'start', 'wave', 'dance', 'sit'];

    if (is_array($data) && isset($data['command'])) {
        $command = $data['command'];
        if (in_array($command, $allowedCommands)) {
            send($data);
            return ['status' => 'success', 'message' => 'Valid command'];
        } else {
            return ['status' => 'error', 'message' => 'Invalid command'];
        }
    } else {
        return ['status' => 'error', 'message' => 'Invalid input'];
    }
}
```

---

## 4. Embedded Device Communication

### 4.1 WebSocket Handling
- **Files**: `websocket_handler.cpp` and `websocket_handler.h`
- **Purpose**: Manage communication between the server and the embedded device.

#### Key Features:
1. Establish a connection with the server.
2. Validate commands using the MAC address.
3. Handle JSON-based communication.

#### Code Highlights:
**Command Validation**:
```cpp
String WebSocketClient::ReadData() {
    String macAddress = macAddressHelper.getMACAddress();
    if (client.available()) {
        String json = client.readStringUntil('\n');
        StaticJsonDocument<1024> doc;
        DeserializationError error = deserializeJson(doc, json);

        if (!error) {
            String command = doc["command"];
            String robotId = doc["robotId"];

            if (robotId != macAddress) {
                return ""; // Ignore invalid robot IDs
            }
            return command;
        }
    }
    return "";
}
```

**Connection Management**:
```cpp
void WebSocketClient::Reconnect() {
    if (!client.connected()) {
        if (client.connect(server_ip, server_port)) {
            is_connected = true;
        } else {
            is_connected = false;
        }
    }
}
```

---

## 5. Full Workflow
1. **Generate QR Code**:
   - Use the MAC address as the unique identifier.
   - Encode the MAC address in a QR code and share it.

2. **Save Data in Browser**:
   - User scans the QR code.
   - Save the robot ID (MAC address) locally in the browser.

3. **Send Commands**:
   - User triggers actions via the web interface.
   - Commands are sent along with the saved robot ID to the server.

4. **Server Processes Commands**:
   - Validate and forward commands to the embedded device.

5. **Embedded Device Executes Commands**:
   - Validate the MAC address and execute valid commands.

---


