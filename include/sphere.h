#pragma once 
#include "renderableObject.h"

class Sphere : public RenderableObject
{
private: 
    Vec3 center;
    float radius;

public: 
    Sphere(): center(0,0,0), radius(0) {}
    Sphere(float radius_, Vec3 center_){radius = radius_; center = center_;}

    bool hit(const Ray& r, float t_min, float t_max, HitResult result) const override;

};