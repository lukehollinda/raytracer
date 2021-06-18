#include "vec3.h"
#include <iostream>
#include <iomanip>

std::ostream& operator<<(std::ostream& os, Vec3& left)
{
    os.precision(5);

    os << "x: " << left.getX()  << " y: " << left.getY() << "z: " << left.getz();
    return os;
}

Vec3& Vec3::operator+=(const Vec3& right)
{
    x += right.x;
    y += right.y;
    z += right.z;

    return *this;    
}

Vec3& Vec3::operator-=(const Vec3& right)
{
    x -= right.x;
    y -= right.y;
    z -= right.z;
    return *this;    
}

Vec3& Vec3::operator*=(const Vec3 &right)
{
    x *= right.x;
    y *= right.y;
    z *= right.z;
    return *this;
}

Vec3& Vec3::operator/=(const Vec3 &right)
{
    x /= right.x;
    y /= right.y;
    z /= right.z;
    return *this;
}

Vec3& Vec3::operator*=(const float& right)
{
    x *= right;
    y *= right;
    z *= right;    
    return *this;    
}

Vec3& Vec3::operator/=(const float& right)
{
    x /= right;
    y /= right;
    z /= right;    
    return *this;    
}

Vec3 Vec3::operator/(const float& right) const
{
    return Vec3(x/right, y/right, z/right);
}

Vec3 Vec3::operator*(const float& right) const
{
    return Vec3(x*right, y*right, z*right);
}

Vec3 unitVector(Vec3 src)
{
    return src / src.length();
}

float dot(const Vec3& left, const Vec3& right)
{
    return left.getX()*right.getX() + left.getY()*right.getY() + left.getZ()*right.getZ();
}

Vec3 cross(const Vec3& left, const Vec3& right)
{
    float x = left.getY()*right.getZ() - left.getZ()*right.getY();
    float y = left.getZ()*right.getX() - left.getX()*right.getZ();
    float z = left.getX()*right.getY() - left.getY()*right.getX();

    return Vec3(x, y, z);
}