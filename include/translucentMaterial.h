#pragma once
#include "material.h"

class TranslucentMaterial : public Material
{
private:
     Color albedo;
     float refractiveIndex;
public:
    TranslucentMaterial(Color albedo_, float refractiveIndex_){ albedo = albedo_; refractiveIndex = refractiveIndex_;}
    virtual bool calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult& hitResult) const override;
};

bool refract(const Vec3& ray, const Vec3& normal, float refractIndexRatio, Vec3& refracted);
