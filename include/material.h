#pragma once
#include "ray.h"
#include "renderableObject.h"
#include "color.h"

//To deal with circular reference
struct HitResult;

class Material 
{
public:
    virtual bool calculateScatterRay(const Ray& ray,  Ray& scattered, Color& attenuation, const HitResult& hitResult) const = 0;
};