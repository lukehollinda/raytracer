#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "image.h"
#include "bitMapUtility.h"
using namespace std;


std::string resultFileName = "bitmapImage.bmp";

int main(int argc, char const *argv[])
{

    Image myImage(500,500); 

    for(int i = 0; i < 500; i++)
    {
        for( int k = 0; k < 500; k++)
        {
            Pixel pixel( (unsigned char)std::rand()*255, (unsigned char)std::rand()*255, (unsigned char)std::rand()*255); 
            myImage.setPixel(i,k, pixel);        
        }
    }
    std::cout << "Image filled" << std::endl;
    generateBitmapImage(myImage, resultFileName);

    std::cout << "Image Generation Complete!\n";
}

