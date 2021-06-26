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



std::string resultFileName = "output/bitmapImage.bmp";

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

Color rayToColor(const Ray& ray, const ObjectCollection& world)
{
    Color color;

    HitResult result;
    if(world.hit(ray, result))
    {
        Vec3 mapped = result.normal;
        mapped.normalize();
        mapped = (mapped + Vec3(1,1,1)) /2 * 255.99;
        color = Color(mapped.getX(), mapped.getY(), mapped.getZ());
    }
    else
    {
        color = Color(0,255,0);
    }

    return color;
}

float randomZeroToOne()
{
    return rand() / (RAND_MAX + 1.0);
}

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

    RenderableObject * worldObjects[3];

    worldObjects[0] = new Sphere(0.5, Vec3(0,0,-4)); 
    worldObjects[1] = new Sphere(100, Vec3(0,-100.5,-4)); 
    worldObjects[2] = new Sphere(3, Vec3(3,3.5,-4)); 

    ObjectCollection world(worldObjects, 3);

    Camera camera(Vec3(0,0.3,-0.5), Vec3(0,-0.3,-1), Vec3(0,0,0), 90, width/height );

    for(int i = 0; i < width; i++)
    {
        for( int k = 0; k < height; k++)
        {            

            //Perform randomized antialias sampling
            float summedRValue = 0;
            float summedGValue = 0;
            float summedBValue = 0;

            Color returnColor;

            for(int a = 0; a < samplingDepth; a++)
            {                
                float screenXPercent = (float(i)+randomZeroToOne()) / float(width);
                float screenYPercent = (float(k)+randomZeroToOne()) /float(height);
                Ray ray = camera.castRay(screenXPercent, screenYPercent);

                returnColor = rayToColor(ray, world);

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
