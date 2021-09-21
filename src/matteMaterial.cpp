#include "MatteMaterial.h"
#include "renderingUtility.h"
#include "ray.h"


MatteMaterial::MatteMaterial(Color albedo_)
{
    albedo = albedo_;
}

bool MatteMaterial::calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult& hitResult) const
{
    Vec3 scattedRayDirection = hitResult.point + hitResult.normal +  randomInUnitCircle();
    scattered = Ray(hitResult.point, scattedRayDirection - hitResult.point);
    attenuation = albedo;

    return true;
}
