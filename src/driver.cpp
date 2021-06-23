#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "image.h"
#include "bitMapUtility.h"
#include "vec3.h"
#include "ray.h"
#include "renderableObject.h"
#include "sphere.h"
using namespace std;


std::string resultFileName = "bitmapImage.bmp";



int main(int argc, char const *argv[])
{

    int width = 1000; 
    int height = 1000;
    
    float aspectRatio = float(width)/float(height);
    Vec3 origin(0,0,0);

    //Scaled width+height, depth of one
    Vec3 lowerLeftCorner(-aspectRatio, -1, -1);
    Vec3 horizontal(aspectRatio*2,0,0);
    Vec3 vertical(0,2,0);



    Image myImage(width, height); 

    Sphere sphere(0.5, Vec3(0,0,-1)); 

    for(int i = 0; i < width; i++)
    {
        for( int k = 0; k < height; k++)
        {            
            Vec3 pointOnScreen = lowerLeftCorner + horizontal*(float(i)/width) + vertical*(float(k)/height);
            Ray ray(origin, pointOnScreen);

            Pixel pixel;
            if(sphere.hit(ray, HitResult(), 0, 0 ))
            {
                pixel = Pixel(0,0,255);
            }
            else
            {
                pixel = Pixel(0,255,0);

            }

            //Pixel pixel( (unsigned char)std::rand()*255, (unsigned char)std::rand()*255, (unsigned char)std::rand()*255); 
            // Pixel pixel( (unsigned char)dot(point, lowerLeftCorner), (unsigned char)dot(point, lowerLeftCorner), (unsigned char)dot(point, lowerLeftCorner));
            myImage.setPixel(i,k, pixel);        
        }
    }
    std::cout << "Image filled" << std::endl;
    generateBitmapImage(myImage, resultFileName);

    std::cout << "Image Generation Complete!\n";


    
}
