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

int main(int argc, char const *argv[])
{

    int width = constants::IMAGE_WIDTH; 
    int height = constants::IMAGE_HEIGHT;
    int antiAliasDepth = constants::ANTI_ALIAS_DEPTH;

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
            Color combinedColour(0,0,0);
            for(int a = 0; a < antiAliasDepth; a++)
            {
                Vec3 pointOnScreen = lowerLeftCorner + horizontal*(float(i)/float(width)) + vertical*(float(k)/float(height));
                Ray ray(origin, pointOnScreen);
                Color rayColor = rayToColor(ray, world);

                combinedColour.r = combinedColour.r + rayColor.r/antiAliasDepth;
                combinedColour.g = combinedColour.g + rayColor.g/antiAliasDepth;
                combinedColour.b = combinedColour.b + rayColor.b/antiAliasDepth;


            }



            myImage.setPixel(i,k, combinedColour);        
        }
    }

    std::cout << "Image filled" << std::endl;
    generateBitmapImage(myImage, resultFileName);

    std::cout << "Image Generation Complete!\n";


    
}
