import socket

def main():
    # Definieer de host en poort van de server
    host = '145.28.162.219'  # IP-adres van de server
    port = 8080

    # Maak een socket-object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        # Verbind met de server
        client_socket.connect((host, port))
        print(f"Verbonden met server op poort {port}")

        # Ontvang berichten van de server
        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            print(f"Ontvangen bericht van de server: {data.decode()}")

    except ConnectionRefusedError:
        print("Verbinding met de server geweigerd.")
    finally:
        # Sluit de socket
        client_socket.close()

if __name__ == "__main__":
    main()