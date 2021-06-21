#include "sphere.h"
#include "vec3.h"

bool Sphere::hit(const Ray& r, float t_min, float t_max, HitResult result) const
{
    Vec3 oc = r.getOrigin() - center;
    float a = dot(r.getDirection(), r.getDirection());
    float b = 2.0 * dot(oc, r.getDirection());
    float c = dot(oc, oc) - radius*radius;

    float discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}
