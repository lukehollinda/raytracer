#pragma once
#include "ray.h"
#include "renderableObject.h"

class Material 
{
    virtual bool calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult hitResult) const = 0;
};