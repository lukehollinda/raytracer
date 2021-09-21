#include "camera.h"


Camera::Camera(Vec3 position_, Vec3 direction_, Vec3 upwards_, float verticalFieldofViewDegrees, float aspectRatio, float focalLength_)
{
    focalLength = focalLength_;
    position = position_;    
    direction = unitVector(direction_);
    upwards = unitVector(upwards_); 

    std::cout << "position_ - " << position_ << std::endl;
    std::cout << "direction_ - " << direction_ << std::endl;
    std::cout << "upwards_ - " << upwards_ << std::endl;
    std::cout << "position UNIT- " << position << std::endl;
    std::cout << "direction UNIT- " << direction << std::endl;
    std::cout << "upwards UNIT- " << upwards << std::endl;

    //Parallel to camera direction and upwards direction. 
    Vec3 planeHorizontalDirection = unitVector(cross(direction, upwards));
    //Parallel to camera direction and the horizantal direction.
    Vec3 planeVirticalDirection   = unitVector(cross(planeHorizontalDirection, direction));

    std::cout << "planeHorizontalDirection - " << planeHorizontalDirection << std::endl;
    std::cout << "planeVirticalDirection - " << planeVirticalDirection << std::endl;

    const double PI = 3.141592653589793238463;

    //From the triangle made by our direction/focalLength and half our vertical viewing angle
    float halfHeight = tan( verticalFieldofViewDegrees * (PI / 360)); //Conversion to rad and division by two
    float halfWidth  = halfHeight * aspectRatio;

    std::cout << "halfHeight - " << halfHeight << std::endl;
    std::cout << "halfWidth - " << halfWidth << std::endl;

    imagePlaneWidth = planeHorizontalDirection * halfWidth * 2;
    imagePlaneHeight = planeVirticalDirection  * halfHeight * 2;
    imagePlaneLowerLeft = position + (direction * focalLength) - (imagePlaneWidth / 2) - (imagePlaneHeight / 2);

    std::cout << "ImageLowerLeft - " << imagePlaneLowerLeft << std::endl;
    std::cout << "ImagePlaneWidth - " << imagePlaneWidth << std::endl;
    std::cout << "ImagePlaneHeight - " << imagePlaneHeight << std::endl;

}

Ray Camera::castRay(float screenXPercent, float screenYPercent)
{
    Vec3 pointOnScreen = imagePlaneLowerLeft + imagePlaneWidth*screenXPercent + imagePlaneHeight*screenYPercent;

    return Ray(position, unitVector(pointOnScreen));

}