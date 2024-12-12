#pragma once
#include <Adafruit_SSD1306.h>


class Face {
public:
    Face();
    ~Face();

    bool Initialize(int width, int height, int address, int rstPin = -1);
    void DisplayFace(int width, int height, const unsigned char* bitmap);

private:
    Adafruit_SSD1306* _display;
    int _width, _height;
};