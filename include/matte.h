#pragma once
#include "material.h"

class Matte : public Material 
{
private:
     Color albedo;
public:
    Matte(Color albedo_);
    bool calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult hitResult) const;
};