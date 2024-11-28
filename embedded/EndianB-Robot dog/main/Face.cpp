#include "Face.h"

Face::Face()
{
}

Face::~Face()
{
	delete _display;
}

bool Face::Initialize(int width, int height, int rstPin, int address)
{
	_width = width;
	_height = height;
	_display = new Adafruit_SSD1306(width, height, &Wire, rstPin);
	return _display.begin(SSD1306_SWITCHCAPVCC, address);
}

void Face::DisplayFace(int width, int height, const unsigned char* bitmap)
{
	_display.clearDisplay();
	_display.drawBitmap((_width - width) / 2, (_height - height) / 2, bitmap, width, height, WHITE);
	_display.display();
}
