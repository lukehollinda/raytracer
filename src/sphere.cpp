#include "sphere.h"
#include "vec3.h"
#include "ray.h"
#include <iostream>

bool Sphere::hit(const Ray& r, HitResult result, float t_min, float t_max) const
{

    //std::cout << "r: " << r << std::endl;


    Vec3 oc = r.getOrigin() - center;
    float a = dot(r.getDirection(), r.getDirection());
    float b = 2.0 * dot(oc, r.getDirection());
    float c = dot(oc, oc) - radius*radius;

    float discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}
