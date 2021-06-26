#pragma once 
#include "vec3.h"
#include "ray.h"
#include <math.h>

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
        Camera(Vec3 position_, Vec3 direction_, Vec3 upwards_, float verticalFieldofViewDegrees, float aspectRatio, float focalLength_);
        Camera() {}

        Ray castRay(float screenXPercent, float screenYPercent);
      
};