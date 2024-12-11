### **Using ZeroTier**
To access a Raspberry Pi web server when users are on different networks, we use ZeroTier. ZeroTier creates a virtual LAN (VLAN) that allows devices to communicate securely as if they were on the same local network. This enables you to use SSH to connect to the Raspberry Pi using its ZeroTier-assigned IP address, even when it's outside your physical network.

---

### **1. Creating a ZeroTier Account**(If only installing and joining go to step 3)
1. **Go to the ZeroTier Website:**  
   Visit [https://www.zerotier.com](https://my.zerotier.com/).
   
2. **Sign Up:**  
   Click on the "Sign Up" button and create an account using your email address or by linking your GitHub/Google account.

3. **Log In:**  
   After creating your account, log in to access the ZeroTier dashboard.

---

### **2. Create a Virtual Network**
1. **Navigate to "Networks":**  
   After logging in, go to the "Networks" tab in the ZeroTier Central dashboard.

2. **Create a New Network:**  
   Click on the **"Create A Network"** button. This generates a new virtual network with a unique 16-digit Network ID (e.g., `a1b2c3d4e5f67890`).

3. **Configure Your Network:**  
   Customize the network settings:
   - **Name:** Give your network a descriptive name.
   - **Private/Public:** Choose **Private** for more control (default). Only devices you authorize can join.
   - **IPv4 Auto-Assign:** Ensure IP addresses are automatically assigned to devices.
   - **Access Control:** Manage access permissions.

---

### **3. Installing ZeroTier on Windows**
1. **Download the Installer:**  
   Visit [ZeroTier's download page](https://www.zerotier.com/download/) and download the Windows installer.

2. **Install ZeroTier:**  
   - Run the installer and follow the prompts.
   - After installation, ZeroTier should run in the background, and you’ll see the ZeroTier icon in the system tray.

3. **Join a Network:**  
   - Right-click the ZeroTier icon in the system tray.
   - Select **"Join Network"** and enter the **Network ID** for our network.(6ab565387a12285c)
   - Click **Join**.

4. **Authorize the Device:**  
   Go back to the ZeroTier Central dashboard.
   - Find your device in the **"Members"** list.
   - Check the box to **authorize** the device.

---

### **4. Installing ZeroTier on Ubuntu**
1. **Open a Terminal:**

2. **Install ZeroTier:**  
   Run the following commands:

   ```bash
   curl -s https://install.zerotier.com | sudo bash
   ```

3. **Start the ZeroTier Service:**  
   ZeroTier should start automatically. Verify it’s running with:

   ```bash
   sudo systemctl status zerotier-one
   ```

4. **Join a Network:**  
   Enter the following command with your **Network ID**(6ab565387a12285c):

   ```bash
   sudo zerotier-cli join <Network_ID>
   ```

5. **Authorize the Device:**  
   - Return to the ZeroTier Central dashboard.
   - In the **Members** tab, authorize the Ubuntu device.

6. **Check Connection Status:**  
   To verify the connection:

   ```bash
   sudo zerotier-cli listnetworks
   ```

---

### **5. Using the Virtual Network**
Once devices are connected and authorized, they can communicate using the ZeroTier-assigned IP addresses. For example:

- **Ping Test:** Check connectivity between devices:
  ```bash
  ping <ZeroTier_IP_of_other_device>
  ```

- **File Sharing:** Set up file sharing on Windows or Ubuntu and connect using the ZeroTier IP addresses.

---

### **6. Optional Configurations**
- **Port Forwarding:** Not required! Devices communicate directly using ZeroTier.
- **DNS Settings:** Configure custom DNS in the network settings for internal services.
- **Security Rules:** Set custom rules for traffic filtering within the ZeroTier network.

---

### **7. Removing a Device from a Network**
- **Windows:** Right-click the ZeroTier icon, select the network, and choose **Leave Network**.
- **Ubuntu:** Use the command:
  ```bash
  sudo zerotier-cli leave <Network_ID>
  ```

---

## Key points

| **Feature**              | **Description**                                                                                 |
|--------------------------|-----------------------------------------------------------------------------------------------|
| **Purpose**              | Access the Raspberry Pi web server from different networks using ZeroTier.                    |
| **Technology**           | ZeroTier (Virtual LAN)                                                                        |
| **Benefit**              | Creates a secure, virtual network that functions like a local LAN, regardless of physical location. |
| **Use Case**             | Connect to the Raspberry Pi via SSH using its ZeroTier-assigned IP address.                   |
| **Network Requirement**  | Devices can be on completely different physical networks or ISPs.                             |
| **Security**             | End-to-end encryption ensures secure communication.                                           |


| **Name**                 | **Description**                                     | **IP Address**     |
|--------------------------|-----------------------------------------------------|--------------------|
| **Raspberry pi 4b**      | Raspberry pi running the webserver.                 | 172.25.75.119      |
