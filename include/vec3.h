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

    float getX(){ return x;}
    float getY(){ return y;}
    float getz(){ return z;}

    Vec3& operator+=(const Vec3& left);
    Vec3& operator-=(const Vec3& left);
    Vec3& operator*=(const Vec3& left);
    Vec3& operator/=(const Vec3& left);
    Vec3& operator*=(const float& left);
    Vec3& operator/=(const float& left);

    //Negation Operator
    Vec3 operator -() const { return Vec3(-x, -y, -z);}

    float length() const { return sqrt(x*x + y*y + z*z); }
    void normalize(); 
};

