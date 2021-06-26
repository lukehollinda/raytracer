#include "renderingUtility.h"

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

Vec3 randomInUnitCircle()
{
    Vec3 res;
    do
    {
        res = Vec3(randomZeroToOne(), randomZeroToOne(), randomZeroToOne()) * 2 - Vec3(1,1,1);
    } while ( res.length() >= 1);
    
    return res;
}