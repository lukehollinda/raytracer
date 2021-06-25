#pragma once
#include <vector>

struct Color
{
    float r,g,b;
    
    Color(float r_, float g_, float b_)
    {
        r = r_;
        g = g_;
        b = b_;
    }

    Color(): Color(0.0f,0.0f,0.0f){}
};


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