#pragma once
#include "ray.h"
#include <limits>

struct HitResult
{
    float time;
    Vec3 point;
    Vec3 normal;

    HitResult():time(0), point(0,0,0), normal(0,0,0){}
};


//Collision retection returning if a hit is made, fill result object with time of collision and normal 
class RenderableObject
{
    public:
        virtual bool hit(const Ray& r, HitResult& result, float t_min = 0, float t_max = std::numeric_limits<float>::max() ) const = 0;
};
