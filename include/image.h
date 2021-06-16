#pragma once
#include <vector>

struct Pixel
{
    unsigned char r,g,b;

    Pixel(unsigned char r_,unsigned char g_,unsigned char b_)
    {
        r = r_;
        g = g_;
        b = b_;
    }
};


class Image{

private:
    int height, width;
    std::vector<std::vector<Pixel>> imageData;

public: 
    Image(int w, int h);
    Pixel getPixel(int w, int h);
    void setPixel(int w, int h, const Pixel& pixel);
    

    std::vector<char> outputRowAsBytes(int row);

    int getHeight() { return height;}
    int getWidth()  { return width;}
    
};