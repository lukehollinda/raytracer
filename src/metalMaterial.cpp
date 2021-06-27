#include "metalMaterial.h"
#include "matteMaterial.h"
#include "renderingUtility.h"

MetalMaterial::MetalMaterial(Color albedo_, float reflectiveness_)
{
    albedo         = albedo_;
    reflectiveness = reflectiveness_;
}

Vec3 MetalMaterial::reflect(const Vec3& rayDirection,const Vec3& surfaceNormal) const
{
    return Vec3( rayDirection - (surfaceNormal * dot(rayDirection, surfaceNormal) * 2) );
}


bool MetalMaterial::calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult& hitResult) const
{   
    float probability = randomZeroToOne();
    bool willReflect = (probability <= reflectiveness);

    if(willReflect)
    {
        scattered = Ray(hitResult.point, reflect(ray.getDirection(), hitResult.normal));
        attenuation = albedo;
        
        return true; //May have to check if direction is correct
    }
    else
    {
        MatteMaterial matteMaterial(albedo);
        return matteMaterial.calculateScatterRay(ray, scattered, attenuation, hitResult);
    }


    
}