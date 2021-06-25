#include <iostream>

#include "image.h"
#include "bitMapUtility.h"

Image::Image(int w, int h) : height(h), width(w), imageData(height, std::vector<Color>(width, Color(0.0f, 0.0f ,0.0f)))
{
    if(w <= 0 || h <= 0)
    {
        std::cout << "Please use only positive dimensions. ";
        exit(EXIT_FAILURE);
    }
}


std::vector<unsigned char> Image::outputRowAsBytes(int row)
{
    int widthInBytes = width * BYTES_PER_PIXEL;
    
    std::vector<unsigned char> data(widthInBytes);
    for(int i = 0; i < (int)imageData.at(row).size(); i++)
    {
        Color currentPixel = imageData.at(row).at(i);
        data.at(i*3 + 0) = (unsigned char)currentPixel.b;
        data.at(i*3 + 1) = (unsigned char)currentPixel.g;
        data.at(i*3 + 2) = (unsigned char)currentPixel.r;
    }

    return data;   
}


Color Image::getPixel(int w, int h)
{
    if(h >= height || h < 0)
    {
        std::cout << "Invalid Image::get, height out of bounds. ";
        exit(EXIT_FAILURE);
    }
    if(w >= width || w < 0)
    {
        std::cout << "Invalid Image::get, width out of bounds. ";
        exit(EXIT_FAILURE);

    }
    return imageData.at(h).at(w);
}

void Image::setPixel(int w, int h, const Color& color)
{

    if(h >= height || h < 0)
    {
        std::cout << "Invalid Image::set, height out of bounds. ";
        exit(EXIT_FAILURE);
    }
    if(w >= width || w < 0)
    {
        std::cout << "Width: " << width << std::endl;
        std::cout << "w: " << w << std::endl;
        std::cout << "Height: " << height << std::endl;
        std::cout << "h: " << h << std::endl;

        
        std::cout << "Invalid Image::set, width out of bounds. ";
        exit(EXIT_FAILURE);
    }
    imageData.at(h).at(w) = color;
}