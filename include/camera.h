#pragma once 
#include "vec3.h"
#include "ray.h"
#include <math.h>


#define _USE_MATH_DEFINES
#include <cmath>
    // Vec3 lowerLeftCorner(-2, -1, -1);
    // Vec3 horizontal(4,0,0);
    // Vec3 vertical(0,2,0);


class Camera 
{
    private:

        //Values describing the orientation and size of the image plane 
        Vec3 imagePlaneLowerLeft;
        Vec3 imagePlaneWidth;
        Vec3 imagePlaneHeight;

        //Position of center of projection
        Vec3 position;
        Vec3 direction;
        Vec3 upwards;

        //Length to image plane
        float focalLength;
        
        float aspectRatio;

    public: 
        Camera(Vec3 position_, Vec3 direction_, Vec3 upwards_, float verticalFieldofViewDegrees, float aspectRatio);

        Ray castRay(float screenXPercent, float screenYPercent);
      
};