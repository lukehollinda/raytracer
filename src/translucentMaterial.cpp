#include "translucentMaterial.h"
#include "metalMaterial.h"
bool refract(const Vec3& ray, const Vec3& normal, float refractIndexRatio, Vec3& refracted)
{
    Vec3 unitRay = unitVector(ray);
    float dt = dot(unitRay, normal);
    float discriminant = 1.0 - refractIndexRatio*refractIndexRatio * (1-dt*dt);

    //If we have real solutions
    if(discriminant > 0)
    {
        refracted = (unitRay - normal*dt) * refractIndexRatio - normal*sqrt(discriminant);
        return true;
    }
    else //Case of total internal reflection
    {
        return false;
    }
}


bool TranslucentMaterial::calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult& hitResult) const
{
    attenuation = albedo;

    Vec3 outwardNormal; 
    
    float refractiveIndexRatio; 

    //Detirmine if we are intering the object of leaving the object
    if(dot(ray.getDirection(), hitResult.point) > 1)
    {
        outwardNormal = -hitResult.normal;
        refractiveIndexRatio = refractiveIndex;
    }
    else
    {
        outwardNormal = hitResult.normal;
        refractiveIndexRatio = 1.0 / refractiveIndex;
    }

    Vec3 refracted;
    if(refract(ray.getDirection(), outwardNormal, refractiveIndexRatio, refracted) )
    {
        scattered = Ray(hitResult.point, refracted);
    }
    else
    {
        //Reflection Case
        scattered = Ray(hitResult.point, Vec3( ray.getDirection() - (hitResult.normal * dot(ray.getDirection(), hitResult.normal) * 2) ));
    }


    return true;
    
}