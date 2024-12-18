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
