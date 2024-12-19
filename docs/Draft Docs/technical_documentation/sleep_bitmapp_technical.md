# Sleep Bitmap Documentation

## Technical Documentation

### Bitmap Data
The `sleep_bitmap` array contains the pixel data for the sleep emote. Each byte represents 8 vertical pixels, with '1' being an illuminated pixel and '0' being an off pixel. The array is stored in `PROGMEM` to save RAM on the microcontroller.

### Integration in the Project
The sleep bitmap is integrated into the main project as follows:

1. **Including the Header File**  
In the main `face.ino` file, the sleep bitmap header is included using:
    ```cpp
    #include "sleep_bitmap.h"
    ```

2. **Using the Bitmap**  
The bitmap is used in the `displayEmote` function, which is called when the "sleep" command is received:
    ```cpp
    else if (command.equals("sleep")) {
      displayEmote(sleep_bitmap, sleep_width, sleep_height);
    }
    ```

3. **Display Function**  
The `displayEmote` function uses the Adafruit GFX library's `drawBitmap` function to render the sleep bitmap on the OLED display:
    ```cpp
    void displayEmote(const unsigned char* bitmap, int width, int height) {
      display.clearDisplay();
      display.drawBitmap((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2, bitmap, width, height, WHITE);
      display.display();
    }
    ``

### Memory Considerations
The sleep bitmap, being 128x64 pixels, requires 1024 bytes of program memory. This is stored in `PROGMEM` to avoid using precious RAM on the microcontroller. 
- `PROGMEM` is a macro in Arduino that tells the compiler to store data in flash memory (program memory) instead of RAM.


### Compatibility
This bitmap is designed for a 128x64 OLED display.

### Modifying the Bitmap
To modify the sleep bitmap:

1. Use an image editor to create a 128x64 pixel black and white image.
2. Convert the image to a bitmap array using a tool like LCD Assistant or ImageConverter.
3. Replace the existing bitmap data in `sleep_bitmap.h` with the new data.





