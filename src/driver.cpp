#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>

#include "image.h"
#include "bitMapUtility.h"
#include "vec3.h"
#include "ray.h"
#include "renderableObject.h"
#include "objectCollection.h"
#include "sphere.h"
#include "constants.h"
#include "camera.h"
#include "renderingUtility.h"
#include "matte.h"


std::string resultFileName = "output/bitmapImage.bmp";


int main(int argc, char const *argv[])
{
    int width = constants::IMAGE_WIDTH; 
    int height = constants::IMAGE_HEIGHT;
    int samplingDepth = constants::SAMPLING_DEPTH;

    std::cout << "Width: "  << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Sampling Depth: " << samplingDepth << std::endl;

    Vec3 origin(0,0,0);

    Vec3 lowerLeftCorner(-2, -1, -1);
    Vec3 horizontal(4,0,0);
    Vec3 vertical(0,2,0);

    Image myImage(width, height); 

    RenderableObject * worldObjects[2];
    
    Material* mat1 = new Matte( Color(255/2, 255/2, 255/2));
    Material* mat2 = new Matte( Color(255/2, 255/2, 255/2));

    std::cout << "Mem location mat1: " << mat1 << std::endl;
    std::cout << "Mem location mat2: " << mat2 << std::endl;

    worldObjects[0] = new Sphere(0.5, Vec3(0,0,-4), mat1 ); 
    worldObjects[1] = new Sphere(100, Vec3(0,-100.5,-4), mat2); 
    //worldObjects[2] = new Sphere(3, Vec3(3,3.5,-4)); 

    ObjectCollection world(worldObjects, 2);

   std::cout << "Before camera initialization\n";// << samplingDepth << std::endl;
   Camera camera;
    try
    {
            camera = Camera(Vec3(0,0.3,-0.5), Vec3(0,-0.3,-1), Vec3(0,1,0), 90.0, (float)width/height, 1 );

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
    
    std::cout << "After camera initialization\n";// << samplingDepth << std::endl;

    for(int i = 0; i < width; i++)
    {
        for( int k = 0; k < height; k++)
        {            

            //Perform randomized antialias sampling
            float summedRValue = 0;
            float summedGValue = 0;
            float summedBValue = 0;

            Color returnColor;

            std::cout << "Begining Search on pixle[" << i << "," << k << "]" << std::endl;

            for(int a = 0; a < samplingDepth; a++)
            {                
                float screenXPercent = (float(i)+randomZeroToOne()) / float(width);
                float screenYPercent = (float(k)+randomZeroToOne()) /float(height);
                 Ray ray = camera.castRay(screenXPercent, screenYPercent);
                returnColor = rayToColor(ray, world, 0);

                summedRValue += returnColor.r;
                summedGValue += returnColor.g;
                summedBValue += returnColor.b;
            }

            summedRValue /= samplingDepth;
            summedGValue /= samplingDepth;
            summedBValue /= samplingDepth;

            myImage.setPixel(i,k, Color(summedRValue, summedGValue, summedBValue));        
        }
    }

    std::cout << "Image filled" << std::endl;
    generateBitmapImage(myImage, resultFileName);

    std::cout << "Image Generation Complete!\n";


    
}
