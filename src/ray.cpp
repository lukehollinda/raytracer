#include "ray.h"
#include "vec3.h"
#include <iostream>

Vec3 Ray::pointAtTime(float t) const
{
    return origin + direction * t; 
}


// std::ostream& operator<<(std::ostream& os, Ray& right)
// {
//     os << "(Origin): " << right.getOrigin() << std::endl;
//     os << "(Direction): " << right.getDirection() << std::endl;

//     return os;
// }