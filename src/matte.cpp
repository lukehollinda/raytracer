#include "matte.h"
#include "renderingUtility.h"
#include "ray.h"


Matte::Matte(Color albedo_)
{
    albedo = albedo_;
}

bool Matte::calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult hitResult) const
{
    Vec3 scattedRayDirection = hitResult.point + hitResult.normal +  randomInUnitCircle();
    scattered = Ray(hitResult.point, scattedRayDirection - hitResult.point);
    attenuation = albedo;

    return true;
}
