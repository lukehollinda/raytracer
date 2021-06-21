#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "image.h"
#include "bitMapUtility.h"
#include "vec3.h"
#include "ray.h"

using namespace std;


std::string resultFileName = "bitmapImage.bmp";



int main(int argc, char const *argv[])
{

    int width = 1000; 
    int height = 700;
    
    float aspectRatio = float(width)/float(height);
    Vec3 origin(0,0,0);

    //Scaled width+height, depth of one
    Vec3 lowerLeftCorner(-aspectRatio, -1, -1);
    Vec3 horizontal(aspectRatio*2,0,0);
    Vec3 vertical(0,2,0);



    Image myImage(width, height); 

    for(int i = 0; i < width; i++)
    {
        for( int k = 0; k < height; k++)
        {            
            Vec3 point = lowerLeftCorner + horizontal*(i/width) + vertical*(i/height);
            Pixel pixel( (unsigned char)std::rand()*255, (unsigned char)std::rand()*255, (unsigned char)std::rand()*255); 
            // Pixel pixel( (unsigned char)dot(point, lowerLeftCorner), (unsigned char)dot(point, lowerLeftCorner), (unsigned char)dot(point, lowerLeftCorner));
            myImage.setPixel(i,k, pixel);        
        }
    }
    std::cout << "Image filled" << std::endl;
    generateBitmapImage(myImage, resultFileName);

    std::cout << "Image Generation Complete!\n";


    
}
