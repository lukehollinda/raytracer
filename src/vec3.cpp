#include "vec3.h"
#include <iostream>


// std::ostream& operator<<(std::ostream& os, Vec3& left)
// {
//     os << "x: " + std::format("{:11.6}", left.getX() ); + " y: " + left.getY() + "z: " + left.getz();
//     return os;
// }

Vec3& Vec3::operator+=(const Vec3& left)
{
    x += left.x;
    y += left.y;
    z += left.z;

    return *this;    
}

Vec3& Vec3::operator-=(const Vec3& left)
{
    x -= left.x;
    y -= left.y;
    z -= left.z;
    return *this;    
}

// Vec3& operator*=(const Vec3 &left)
// {

// }
// Vec3& operator/=(const Vec3 &left);

Vec3& Vec3::operator*=(const float& left)
{
    x *= left;
    y *= left;
    z *= left;    
    return *this;    
}

Vec3& Vec3::operator/=(const float& left)
{
    x /= left;
    y /= left;
    z /= left;    
    return *this;    
}