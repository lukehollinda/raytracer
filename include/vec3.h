#include <math.h>


class Vec3 
{
private: 
    float x, y, z;

public: 
    Vec3(float x_, float y_, float z_){ x = x_; y = y_; z = z_;}

    void setX(float x_){x = x_;}
    void setY(float y_){y = y_;}
    void setZ(float z_){z = z_;}

    float getX() const{ return x;}
    float getY() const{ return y;}
    float getZ() const{ return z;}

    Vec3& operator+=(const Vec3& right);
    Vec3& operator-=(const Vec3& right);
    Vec3& operator*=(const Vec3& right);
    Vec3& operator/=(const Vec3& right);
    Vec3& operator*=(const float& right);
    Vec3& operator/=(const float& right);

    //Negation Operator
    Vec3 operator -() const { return Vec3(-x, -y, -z);}
    Vec3 operator/(const float& right) const;
    Vec3 operator*(const float& right) const;

    float length() const { return sqrt(x*x + y*y + z*z); }
    void normalize(); 
};

