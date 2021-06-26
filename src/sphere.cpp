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
    // std::cout << "hitResult.material (IN HIT BEFORE CHANGE): " << result.material << std::endl;
    // std::cout << "hitResult.normal (IN HIT BEFORE CHANGE): " << result.normal << std::endl;
    // std::cout << "hitResult.point (IN HIT BEFORE CHANGE): " << result.point << std::endl;
    // std::cout << "hitResult.time (IN HIT BEFORE CHANGE): " << result.time << std::endl;

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
            // std::cout << "Applying add: " << material << " into res.mat." << std::endl;
            result.material = material;     
            // std::cout << "Res.mat now: " << result.material << std::endl; 

            return true;
        }

        //Check further point within time bound
        timeTest = (-b + sqrt(discriminant) ) / (2.0 * a);
        if(timeTest < t_max && timeTest > t_min)
        {
            result.time = timeTest;
            result.point = ray.pointAtTime(timeTest);
            result.normal = (result.point - center) / radius;
            // std::cout << "Applying add: " << material << " into res.mat." << std::endl;
            result.material = material;     
            // std::cout << "Res.mat now: " << result.material << std::endl;    
            return true;
        }     
    }

    return false;
}
