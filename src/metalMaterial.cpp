#include "metalMaterial.h"
#include "matteMaterial.h"
#include "renderingUtility.h"
#include "vec3.h"
#include "constants.h"

MetalMaterial::MetalMaterial(Color albedo_, float fuzzyness_)
{
    albedo    = albedo_;
    fuzzyness = fuzzyness_; //A radius of direcitonal influence
    
    //Fuzz generated circle of deviation from perfect reflection, cap at 1
    if(fuzzyness > 1)
    {
        std::cout << "MetalMaterial::fuzzyness_ = " << fuzzyness << " - Please have fuzzyness values between 0 and 1 " << std::endl;
        exit(EXIT_FAILURE);
    }
}

Vec3 MetalMaterial::reflect(const Vec3& rayDirection,const Vec3& surfaceNormal) const
{
    return Vec3( rayDirection - (surfaceNormal * dot(rayDirection, surfaceNormal) * 2) );
}


bool MetalMaterial::calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult& hitResult) const
{   
    scattered = Ray(hitResult.point, reflect(ray.getDirection(), hitResult.normal));
    attenuation = albedo;
    
    Vec3 fuzzOffset;    

    int sampleCount = 0;
    do
    {
        if(sampleCount >= constants::METAL_FUZZ_ATTEMPT_MAX)
        {
            fuzzOffset = Vec3(0,0,0);
            break;
        }
        sampleCount++;

        fuzzOffset = randomInUnitCircle() * fuzzyness;
    } while (dot(scattered.getDirection() + fuzzOffset, hitResult.normal) <= 0);
    
    scattered.setDirection(unitVector(scattered.getDirection() + fuzzOffset));

    return true; //May have to check if direction is correct

}