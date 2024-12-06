### **1. `wifi_manager.h` and `wifi_manager.cpp`**

#### **Purpose:**
Manages the robot's Wi-Fi connection using the ESP32's.

#### **Key Components:**
- **Class:** `WiFiManagerHelper`  
  A helper class encapsulating Wi-Fi connection logic, making the main code cleaner and easier to manage.

- **Method: `connectToWiFi`**  
  Uses the `WiFiManager` library to connect to a Wi-Fi network.  
  - If no credentials are set, it creates an access point with the default SSID `"Robot Dog"`.  
  - If the connection fails, the ESP32 restarts (`ESP.restart()`), ensuring continuous operation.

- **Method: `getClient()`**  
  Provides access to the `WiFiClient` object, enabling other components (like WebSocket handling) to use the Wi-Fi connection.

---

### **2. `websocket_handler.h` and `websocket_handler.cpp`**

#### **Purpose:**
Handles WebSocket communication with a server, enabling real-time data exchange.

#### **Key Components:**
- **Class:** `WebSocketClient`  
  Represents a WebSocket client for handling communication with a server.

- **Attributes:**
  - `server_ip` and `server_port`: Define the server's IP and port.
  - `client`: `WiFiClient` instance used for communication.

- **Methods:**
  - **`Connect()`**  
    Establishes a connection to the server. Returns `true` if successful.
  - **`Reconnect()`**  
    Attempts to reconnect if the connection is lost. Logs success or failure to the serial monitor.
  - **`IsConnected()`**  
    Returns the connection status.
  - **`ReadData()`**  
    Reads data from the server until a newline character (`\n`) is encountered.
  - **`SendData()`**  
    Sends a string message to the server if connected.
  - **`CloseConnection()`**  
    Closes the current connection, ensuring a clean disconnect.

---

### **3. `main.cpp`**

#### **Purpose:**
Controls the robot's behavior, manages Wi-Fi/WebSocket connections, and orchestrates movement based on commands.

#### **Key Components:**

- **Initialization:**
  - **`wifiManagerHelper.connectToWiFi()`**  
    Establishes a Wi-Fi connection.
  - **`wsClient.Connect()`**  
    Connects to the WebSocket server. Restarts the ESP32 if the connection fails.

- **Command Handling:**
  - Defines various commands (`FORWARD`, `BACKWARD`, etc.) to control the robot.
  - **`handleCommand(String command)`**  
    Executes appropriate functions based on the received command.

---

### **How It All Works Together:**

1. **Wi-Fi Connection:**
   - On startup, the `WiFiManagerHelper` attempts to connect to a Wi-Fi network. If no saved networks are found, it creates an access point.
   
2. **WebSocket Communication:**
   - Once Wi-Fi is connected, the `WebSocketClient` connects to the specified server (`<IP_OF_LAPTOP>` on port `8080`).
   - The WebSocket connection enables real-time communication, where commands from the server control the robot's actions.

3. **Main Loop (Implied in the Code Fragment):**
   - Continuously reads commands from the WebSocket.
   - Calls `handleCommand()` to execute actions such as moving forward or changing facial expressions based on the received command.
   
---

### **Key Takeaways:**
- **Modularity:** The code is well-structured into separate files for Wi-Fi, WebSocket handling, and main logic, improving maintainability.
- **Error Handling:** Automatic reconnection ensures reliability in both Wi-Fi and WebSocket connections.
- **Expandability:** New commands or actions can easily be added by extending the `handleCommand()` function or adding methods to the `Movement` class. 

This design ensures the robot dog remains responsive and functional even if network issues occur, while keeping the main logic clear and organized.