#pragma once
#include <vector>

struct Color
{
    unsigned char r,g,b;

    Color(unsigned char r_,unsigned char g_,unsigned char b_)
    {
        r = r_;
        g = g_;
        b = b_;
    }

    Color(float r_, float g_, float b_)
    {
        r = (unsigned char)r_;
        g = (unsigned char)g_;
        b = (unsigned char)b_;
    }

    Color(int r_, int g_, int b_)
    {
        r = (unsigned char)r_;
        g = (unsigned char)g_;
        b = (unsigned char)b_;
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