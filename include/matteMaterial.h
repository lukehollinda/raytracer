#pragma once
#include "material.h"
#include "renderableObject.h"
class MatteMaterial : public Material 
{
private:
     Color albedo;
public:
    MatteMaterial(Color albedo_);
    virtual bool calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult& hitResult) const override;
};