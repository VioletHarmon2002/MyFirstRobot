#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// I2C address of the OLED display
#define SSD1306_I2C_ADDRESS 0x3C

// Include separate bitmap header files
#include "smile_bitmap.h"
#include "frown_bitmap.h"
#include "idle_bitmap.h"

void setup() {
  Serial.begin(115200);
  while (!Serial); // Wait for serial monitor to open

  Wire.begin(4, 15); // SDA on pin 4, SCL on pin 15

  if(!display.begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.display();
}


void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    
    if (command.equals("idle")) {
      displayEmote(idle_bitmap, idle_width, idle_height);
    } 
    else if (command.equals("smile")) {
      displayEmote(smile_bitmap, smile_width, smile_height);
    } 
    else if (command.equals("frown")) {
      displayEmote(frown_bitmap, frown_width, frown_height);
    }
  }
}

// Function to display a bitmap on the OLED
void displayEmote(const unsigned char* bitmap, int width, int height) {
  display.clearDisplay();
  display.drawBitmap((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2, bitmap, width, height, WHITE);
  display.display();
}