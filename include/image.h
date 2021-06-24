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

    Color(): Color(0,0,0){}
};


class Image{

private:
    int height, width;
    std::vector<std::vector<Color>> imageData;

public: 
    Image(int w, int h);
    Color getPixel(int w, int h);
    void setPixel(int w, int h, const Color& color);
    

    std::vector<char> outputRowAsBytes(int row);

    int getHeight() { return height;}
    int getWidth()  { return width;}
    
};