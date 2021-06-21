#include <iostream>

#include "image.h"
#include "bitMapUtility.h"

Image::Image(int w, int h) : height(h), width(w), imageData(height, std::vector<Pixel>(width, Pixel(0,0,0)))
{
    if(w <= 0 || h <= 0)
    {
        std::cout << "Please use only positive dimensions. ";
        exit(EXIT_FAILURE);
    }
}


std::vector<char> Image::outputRowAsBytes(int row)
{
    int widthInBytes = width * BYTES_PER_PIXEL;
    
    std::vector<char> data(widthInBytes);
    for(int i = 0; i < (int)imageData.at(row).size(); i++)
    {
        Pixel currentPixel = imageData.at(row).at(i);
        data.at(i*3 + 0) = currentPixel.r;
        data.at(i*3 + 1) = currentPixel.g;
        data.at(i*3 + 2) = currentPixel.b;
    }

    return data;   
}


Pixel Image::getPixel(int w, int h)
{
    if(h >= height || h < 0)
    {
        throw "Invalid Image::get, height out of bounds. ";
        std::cout << "Invalid Image::get, height out of bounds. ";
        exit(EXIT_FAILURE);
    }
    if(w >= width || w < 0)
    {
        std::cout << "Invalid Image::get, height out of bounds. ";
        exit(EXIT_FAILURE);

    }
    return imageData.at(w).at(h);
}

void Image::setPixel(int w, int h, const Pixel& pixel)
{
    if(h >= height || h < 0)
    {
        std::cout << "Invalid Image::set, height out of bounds. ";
        exit(EXIT_FAILURE);
    }
    if(w >= width || w < 0)
    {
        std::cout << "Invalid Image::set, height out of bounds. ";
        exit(EXIT_FAILURE);
    }
    imageData.at(h).at(w) = pixel;
}