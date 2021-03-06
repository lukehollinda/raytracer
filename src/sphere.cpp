#include "sphere.h"
#include "vec3.h"
#include "ray.h"
#include <iostream>
#include <limits>

Sphere::Sphere(float radius_, Vec3 center_, Material* material): RenderableObject(material)
{
    radius = radius_; 
    center = center_; 
    std::cout << "In sphere mat address: " << material << std::endl;
}

bool Sphere::hit(const Ray& ray, HitResult& result, float t_min, float t_max) const
{
    Vec3 oc = ray.getOrigin() - center;
    float a = dot(ray.getDirection(), ray.getDirection());
    float b = 2.0 * dot(oc, ray.getDirection());
    float c = dot(oc, oc) - radius*radius;

    float discriminant = b*b - 4*a*c;
    
    if(discriminant > 0)
    {
        //Check closest point within time bounds
        float timeTest = (-b - sqrt(discriminant) ) / (2.0 * a);
        if(timeTest < t_max && timeTest > t_min)
        {
            result.time = timeTest;
            result.point = ray.pointAtTime(timeTest);
            result.normal = (result.point - center) / radius;
            result.material = material;     

            return true;
        }

        //Check further point within time bound
        timeTest = (-b + sqrt(discriminant) ) / (2.0 * a);
        if(timeTest < t_max && timeTest > t_min)
        {
            result.time = timeTest;
            result.point = ray.pointAtTime(timeTest);
            result.normal = (result.point - center) / radius;
            result.material = material;     
        
            return true;
        }     
    }

    return false;
}
