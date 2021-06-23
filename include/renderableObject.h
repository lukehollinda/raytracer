#pragma once
#include "ray.h"
#include <limits>

struct HitResult
{
    float t;
    Vec3 p;
    Vec3 normal;

    HitResult():t(0), p(0,0,0), normal(0,0,0){}
};


//Collision retection returning if a hit is made, fill result object with time of collision and normal 
class RenderableObject
{
    public:
        virtual bool hit(const Ray& r, HitResult result, float t_min = 0, float t_max = std::numeric_limits<float>::max() ) const = 0;
};