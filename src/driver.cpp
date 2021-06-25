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

Vec3 rayToNormal(const Ray& ray, const ObjectCollection& world)
{
    Color color;

    HitResult result;
    if(world.hit(ray, result))
    {
        Vec3 mapped = result.normal;
        mapped.normalize();
        mapped = (mapped + Vec3(1,1,1)) /2 * 255.99;
        return Vec3(mapped.getX(), mapped.getY(), mapped.getZ());
        color = Color(mapped.getX(), mapped.getY(), mapped.getZ());
    }
    else
    {
        return Vec3(0,255,0);
        color = Color(0,255,0);
    }

    
}


float randomZeroToOne()
{
    return rand() / (RAND_MAX + 1.0) * 2;
}

int main(int argc, char const *argv[])
{
    int width = constants::IMAGE_WIDTH; 
    int height = constants::IMAGE_HEIGHT;
    int antiAliasDepth = constants::ANTI_ALIAS_DEPTH;

    cout << "Width: "  << width << std::endl;
    cout << "Height: " << height << std::endl;
    cout << "AntiAlias Depth: " << antiAliasDepth << std::endl;

    //float aspectRatio = float(width)/float(height);
    Vec3 origin(0,0,0);

    Vec3 lowerLeftCorner(-2, -1, -1);
    Vec3 horizontal(4,0,0);
    Vec3 vertical(0,2,0);

    Image myImage(width, height); 

    RenderableObject * worldObjects[3];

    worldObjects[0] = new Sphere(0.5, Vec3(0,0,-4)); 
    worldObjects[1] = new Sphere(3, Vec3(0,-3.5,-4)); 
    worldObjects[2] = new Sphere(3, Vec3(0,3.5,-4)); 

    ObjectCollection world(worldObjects, 3);
    for(int i = 0; i < width; i++)
    {
        for( int k = 0; k < height; k++)
        {            

            //Perform randomized antialias sampling
            float r = 0; 
            float g = 0; 
            float b = 0;
            for(int a = 0; a < antiAliasDepth; a++)
            {
                Vec3 horizontalOffset = horizontal * (float(i)+randomZeroToOne()) / float(width);
                Vec3 verticalOffset   = vertical * (float(k)+randomZeroToOne()) /float(height);

                Vec3 pointOnScreen = lowerLeftCorner + horizontalOffset + verticalOffset;
                Ray ray(origin, pointOnScreen);
                //Color rayColor = rayToColor(ray, world);

                // r += rayColor.r/antiAliasDepth;
                // g += rayColor.g/antiAliasDepth;
                // b += rayColor.b/antiAliasDepth;
                Vec3 returnCol = rayToNormal(ray, world);

                r += returnCol.getX()/antiAliasDepth;
                g += returnCol.getY()/antiAliasDepth;
                b += returnCol.getZ()/antiAliasDepth;

                //TODO Clean up all of this and change the Color struct to hold rgb values in floats until converted to bitmap
            }



            myImage.setPixel(i,k, Color(r,g,b));        
        }
    }

    std::cout << "Image filled" << std::endl;
    generateBitmapImage(myImage, resultFileName);

    std::cout << "Image Generation Complete!\n";


    
}
