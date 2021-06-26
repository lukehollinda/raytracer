#pragma once
#include <vector>
#include "color.h"

class Image{

private:
    int height, width;
    std::vector<std::vector<Color>> imageData;

public: 
    Image(int w, int h);
    Color getPixel(int w, int h);
    void setPixel(int w, int h, const Color& color);
    

    std::vector<unsigned char> outputRowAsBytes(int row);

    int getHeight() { return height;}
    int getWidth()  { return width;}
    
};