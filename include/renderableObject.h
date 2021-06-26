#pragma once
#include "ray.h"
#include "material.h"
#include <limits>

//To deal with circular reference
class Material;

struct HitResult
{
    float time;
    Vec3 point;
    Vec3 normal;
    Material* material;

    HitResult();
};


//Collision retection returning if a hit is made, fill result object with time of collision and normal 
class RenderableObject
{
protected:
    Material* material;
    RenderableObject(Material* material_){material = material_;}

public:
    virtual bool hit(const Ray& r, HitResult& result, float t_min = 0, float t_max = std::numeric_limits<float>::max() ) const = 0;
};
