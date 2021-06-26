#include "color.h"
#include <assert.h>

Color Color::operator*(float right)
{
    Color color(r * right, g * right, b * right);
    color.assertValidity();
    return color;
}

Color Color::operator/(float right)
{
    assert(right != 0);
    Color color(r / right, g / right, b / right);
    color.assertValidity();
    return color;
}

void Color::operator*=(float right)
{
    r *= right;
    g *= right;
    b *= right;
    assertValidity();
}

void Color::operator/=(float right)
{
    assert(right != 0);
    r /= right;
    g /= right;
    b /= right;
    assertValidity();
}


void Color::assertValidity()
{   
    //Assert all components are within range
    assert(r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255);
}
