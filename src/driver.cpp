#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "image.h"
#include "bitMapUtility.h"
#include "vec3.h"
#include "ray.h"
#include "renderableObject.h"
#include "objectCollection.h"
#include "sphere.h"
using namespace std;


std::string resultFileName = "bitmapImage.bmp";

float map(float c)
{
    float r = ((c+1)/2) * 255;
    if(r < 0 || r > 255)
    {
    std::cout << c << std::endl;
        exit(EXIT_FAILURE);
    }
    else
        return r;
}



int main(int argc, char const *argv[])
{

    int width = 1000; 
    int height = 500;
    
    float aspectRatio = float(width)/float(height);
    Vec3 origin(0,0,0);

    //Scaled width+height, depth of one
    // Vec3 lowerLeftCorner(-width/200.0, -height/200.0, -1);
    // Vec3 horizontal(width/100.0,0,0);
    // Vec3 vertical(0,height/100.0,0);

    Vec3 lowerLeftCorner(-2, -1, -1);
    Vec3 horizontal(4,0,0);
    Vec3 vertical(0,2,0);

    std::cout << "LowerCorner: " << lowerLeftCorner << std::endl;
    std::cout << "Horizontal: " << horizontal << std::endl;
    std::cout << "Vertical: " << vertical << std::endl;


    Image myImage(width, height); 

    RenderableObject * worldObjects[3];

    worldObjects[0] = new Sphere(0.5, Vec3(0,0,-1)); 
    worldObjects[1] = new Sphere(100, Vec3(0,-100.5,-1)); 
    worldObjects[2] = new Sphere(0.2, Vec3(1,0,-1)); 

    ObjectCollection world(worldObjects, 3);

    for(int i = 0; i < width; i++)
    {
        for( int k = 0; k < height; k++)
        {            
            Vec3 pointOnScreen = lowerLeftCorner + horizontal*(float(i)/width) + vertical*(float(k)/height);
            Ray ray(origin, pointOnScreen);

            std::cout << "ScreenDirection: " << ray.getDirection() << std::endl;

            Color color;
            HitResult result;
            if(world.hit(ray, result))
            {
                color = Color(map(result.normal.getX()),map(result.normal.getY()),map(result.normal.getZ()));

                std::cout << "PixelHit[" << i << "," << k << "] - (t : " << result.time << " )" << std::endl; 
                std::cout << "      ->     (n : " << result.normal << " )" << std::endl; 
                std::cout << "      ->     (p : " << result.point << " )" << std::endl; 
                std::cout << "      -> MAPPED: r: " << map(result.normal.getX()) << " g: " << map(result.normal.getY()) << " b: " << map(result.normal.getZ()) << std::endl;

            }
            else
            {
                color = Color(0,255,0);
                // std::cout << "Missed[" << i << "," << k << "] - (t : " << result.time << " )" << std::endl; 
                // std::cout << "      ->     (n : " << result.normal << " )" << std::endl; 
                // std::cout << "      ->     (p : " << result.point << " )" << std::endl; 

            }

            myImage.setPixel(i,k, color);        
        }
    }

    std::cout << "Image filled" << std::endl;
    generateBitmapImage(myImage, resultFileName);

    std::cout << "Image Generation Complete!\n";


    
}
