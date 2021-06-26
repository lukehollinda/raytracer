#pragma once
#include "material.h"
#include "renderableObject.h"
class Matte : public Material 
{
private:
     Color albedo;
public:
    Matte(Color albedo_);
    virtual bool calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult& hitResult) const override;
};