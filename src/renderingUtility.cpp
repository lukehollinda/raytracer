#include "renderingUtility.h"
#include "constants.h"
Color rayToColor(const Ray& ray, const ObjectCollection& world, int recursionDepth)
{

    Color color;

    HitResult hitResult;

    if(world.hit(ray, hitResult, 0.00001))
    {

        Color attenuation;
        Ray scatteredRay;

        //If we have not reached max depth, calculate scattered Ray and recurse
        if(recursionDepth < constants::RECURSION_DEPTH_MAX && hitResult.material->calculateScatterRay(ray, scatteredRay, attenuation, hitResult))
        {
            return (attenuation / 255) * rayToColor(scatteredRay, world, recursionDepth + 1);
        }
        else
        {
            return Color(0,0,0);
        }
        
    }
    else
    {    
        float mappedYVal_zeroToOne = (unitVector(ray.getDirection() ).getY() + 1) / 2;
        return Color(255,255,255) * mappedYVal_zeroToOne + Color(255,150,255) * (1 - mappedYVal_zeroToOne);
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