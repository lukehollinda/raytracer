#include "camera.h"


Camera::Camera(Vec3 position_, Vec3 direction_, Vec3 upwards_, float verticalFieldofViewDegrees, float aspectRatio)
{
    focalLength = 1;
    position = position_;    
    direction = unitVector(direction_);
    upwards = unitVector(upwards_); 

    //Parallel to camera direction and upwards direction. 
    Vec3 planeHorizontalDirection = unitVector(cross(direction, upwards));
    //Parallel to camera direction and the horizantal direction.
    Vec3 planeVirticalDirection   = unitVector(cross(planeHorizontalDirection, direction));


    // imagePlaneLowerLeft = Vec3(-2,-1,-1);
    // imagePlaneWidth = Vec3(4,0,0);
    // imagePlaneHeight = Vec3(0,2,0);

    const double PI = 3.141592653589793238463;

    //From the triangle made by our direction/focalLength and half our vertical viewing angle
    float halfHeight = tan( verticalFieldofViewDegrees * (PI / 360)); //Conversion to rad and division by two
    float halfWidth  = halfHeight * aspectRatio;

    imagePlaneWidth = planeHorizontalDirection * halfWidth * 2;
    imagePlaneHeight = planeVirticalDirection  * halfHeight * 2;
    imagePlaneLowerLeft = position + (direction * focalLength) - (imagePlaneWidth / 2) - (imagePlaneHeight / 2);

    std::cout << "ImageLowerLeft - " << imagePlaneLowerLeft << std::endl;
    std::cout << "ImagePlaceWidth - " << imagePlaneWidth << std::endl;
    std::cout << "ImagePlaceHeight - " << imagePlaneHeight << std::endl;

}

Ray Camera::castRay(float screenXPercent, float screenYPercent)
{
    Vec3 pointOnScreen = imagePlaneLowerLeft + imagePlaneWidth*screenXPercent + imagePlaneHeight*screenYPercent;

    return Ray(position, unitVector(pointOnScreen));

}