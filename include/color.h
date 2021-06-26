#pragma once

struct Color
{
    
    float r,g,b;
    
    Color(float r_, float g_, float b_)
    {
        r = r_;
        g = g_;
        b = b_;
    }

    Color(): Color(0.0f,0.0f,0.0f){}

    Color operator*(float right);
    Color operator/(float right);

    void operator*=(float right);
    void operator/=(float right);

    void assertValidity();
};

