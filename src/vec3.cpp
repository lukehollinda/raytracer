#include <iostream>
#include <iomanip>
#include <assert.h>
#include "vec3.h"


std::ostream& operator<<(std::ostream& os, const Vec3& vec)
{
    os.precision(5);

    os << "x: " << vec.getX()  << " y: " << vec.getY() << " z: " << vec.getZ();
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
    assert(right.x != 0 && right.y != 0 && right.z != 0);
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
    assert(right != 0);
    x /= right;
    y /= right;
    z /= right;    
    return *this;    
}

Vec3 Vec3::operator/(const float& right) const
{
    assert(right != 0);
    return Vec3(x/right, y/right, z/right);
}

Vec3 Vec3::operator*(const float& right) const
{
    return Vec3(x*right, y*right, z*right);
}

Vec3 Vec3::operator+(const Vec3& right) const
{
    return Vec3(x+right.getX(), y+right.getY(), z+right.getZ());
}

Vec3 Vec3::operator-(const Vec3& right) const
{
    return Vec3(x-right.getX(), y-right.getY(), z-right.getZ());
}
void Vec3::normalize()
{
    x /= length();
    y /= length();
    z /= length();

}

Vec3 unitVector(Vec3 src)
{
    assert(src.length() != 0);
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