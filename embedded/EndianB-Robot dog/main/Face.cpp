#include "Face.h"

Face::Face()
{
}

Face::~Face()
{
	delete _display;
}

/**
 * @brief Initializes the OLED
 *
 * @param width Width of the display
 * @param height Height of the display
 * @param address Address of the display
 * @param rstPin pin linked to the reset pin on the OLED
 */
bool Face::Initialize(int width, int height, int address, int rstPin)
{
	_width = width;
	_height = height;
	_display = new Adafruit_SSD1306(width, height, &Wire, rstPin);
	return _display->begin(SSD1306_SWITCHCAPVCC, address);
}

/**
 * @brief Display the given bitmap with the corresponding width and height
 *
 * @param width Width of the display
 * @param height Height of the display
 * @param bitmap Bitmap of the image that should be displayed
 */
void Face::DisplayFace(int width, int height, const unsigned char *bitmap)
{
	_display->clearDisplay();
	_display->drawBitmap((_width - width) / 2, (_height - height) / 2, bitmap, width, height, WHITE);
	_display->display();
}
