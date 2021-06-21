#pragma once
#include "ray.h"

struct HitResult
{
    float t;
    Vec3 p;
    Vec3 normal;
};

class RenderableObject
{
    public:
        virtual bool hit(const Ray& r, float t_min, float t_max, HitResult result) const = 0;
};