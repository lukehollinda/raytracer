#pragma once
#include "vec3.h"

class Ray
{
    private:
        Vec3 origin;
        Vec3 direction; 

    public:
        Ray(const Vec3& origin_, const Vec3& direction_)
        {
            origin    = origin_;
            direction = direction_;
            direction.normalize();
        }
        
        Ray():origin(0,0,0), direction(0,0,0) {}


        void setOrigin(const Vec3& origin_){origin = origin_;}
        void setDirection(const Vec3& direction_){direction = direction_;}        
        Vec3 getOrigin() const{ return origin;}
        Vec3 getDirection() const{ return direction;}

        Vec3 pointAtTime(float t) const;

    friend std::ostream& operator<<(std::ostream& os, const Ray& ray);

};

std::ostream& operator<<(std::ostream& os, const Ray& ray);
