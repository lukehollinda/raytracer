#pragma once
#include "material.h"

class MetalMaterial : public Material
{
private:
    Color albedo;
    float fuzzyness;

    Vec3 reflect(const Vec3& rayDirection,const Vec3& surfaceNormal) const;

public:
    MetalMaterial(Color albedo_, float fuzzyness_);
    virtual bool calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult& hitResult) const override;

};