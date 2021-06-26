#include "renderingUtility.h"
#include "constants.h"
Color rayToColor(const Ray& ray, const ObjectCollection& world, int recursionDepth)
{

    // std::cout << "rayToColor Called" << std::endl;
    Color color;

    HitResult hitResult;
    // std::cout << "hitResult.material (pre initialization): " << hitResult.material << std::endl;
    // std::cout << "hitResult.normal (pre initialization): " << hitResult.normal << std::endl;
    // std::cout << "hitResult.point (pre initialization): " << hitResult.point << std::endl;
    // std::cout << "hitResult.time (pre initialization): " << hitResult.time << std::endl;

    if(world.hit(ray, hitResult, 0.00001))
    {
        // std::cout << "hit Called & returned" << std::endl;

    // std::cout << "hitResult.material: " << hitResult.material << std::endl;
    // std::cout << "hitResult.normal: " << hitResult.normal << std::endl;
    // std::cout << "hitResult.point: " << hitResult.point << std::endl;
    // std::cout << "hitResult.time: " << hitResult.time << std::endl;

     
        Color attenuation;
        Ray scatteredRay;

        //If we have not reached max depth, calculate scattered Ray and recurse
        if(recursionDepth < constants::RECURSION_DEPTH_MAX && hitResult.material->calculateScatterRay(ray, scatteredRay, attenuation, hitResult))
        {
            // std::cout << "Recursing" << std::endl;
            return (attenuation / 255) * rayToColor(scatteredRay, world, recursionDepth + 1);
        }
        else
        {
            // std::cout << "Returning black end case" << std::endl;
            return Color(0,0,0);
        }
        
    }
    else
    {
        // std::cout << "Returning skybox" << std::endl;
       
        //Skybox color;
        return Color(255,255,255);
    }


}

float randomZeroToOne()
{
    return rand() / (RAND_MAX + 1.0);
}

Vec3 randomInUnitCircle()
{
    Vec3 res;
    do
    {
        res = Vec3(randomZeroToOne(), randomZeroToOne(), randomZeroToOne()) * 2 - Vec3(1,1,1);
    } while ( res.length() >= 1);
    
    return res;
}