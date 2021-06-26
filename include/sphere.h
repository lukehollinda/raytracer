#pragma once 
#include "renderableObject.h"
#include <limits>
class Sphere : public RenderableObject
{
private: 
    Vec3 center;
    float radius;

public: 
    Sphere(float radius_, Vec3 center_, Material* material);

    virtual bool hit(const Ray& r, HitResult& result, float t_min = 0, float t_max = std::numeric_limits<float>::max() ) const override;

};