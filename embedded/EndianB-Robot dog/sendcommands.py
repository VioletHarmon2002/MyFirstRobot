import socket
import json

valid_commands = ["forward", "backward", "start", "sit", "left", "right", "wave", "lay", "dance"]


def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

def main():
    # Define the host and port to listen on
    host = '172.20.10.5'  # Listen on all available interfaces
    port = 8080

    # Create a socket object
    serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        # Bind the socket to the specified host and port
        serversocket.bind((host, port))

        # Listen for incoming connections
        serversocket.listen(1)
        print(f"Waiting for connections on port {port}...")

        while True:
            # Accept incoming connections
            client_socket, client_address = serversocket.accept()
            print(f"Connection established with {client_address[0]}")

            # Read input from console and send to client
            while True:
                data = input("Enter a command ('exit' to stop, or 'q' for commands): ")
                if data == 'exit':
                    break
                if data == 'q':
                    for command in valid_commands:
                        print(command)

                # Check if input is a valid command or a number
                if data not in valid_commands and not is_number(data):
                    print("Invalid input. Please enter 'forward', 'start', 'docking', 'sit', 'left', 'right', 'wave', 'lie'")
                    continue

                # Create a JSON object based on the input
                if data in valid_commands:
                    message = {"command": data}
                else:
                    message = {"angle": int(data)}  # Convert input to integer

                # Serialize the JSON object to a string
                json_message = json.dumps(message)

                # Print original input message and its JSON-encoded format
                print("Original Input:", data)
                print("Encoded JSON Format:", json_message)

                # Send the JSON-encoded message to the client
                client_socket.sendall(json_message.encode())

            # Close the connection with the client
            client_socket.close()

    except KeyboardInterrupt:
        print("\nServer stopped.")
    finally:
        # Close the server socket
        serversocket.close()

if __name__ == "__main__":
    main()
