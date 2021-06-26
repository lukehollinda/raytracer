#include "objectCollection.h"
#include "renderableObject.h"

#include <iostream>
#include <limits>

bool ObjectCollection::hit(const Ray& r, HitResult& result, float t_min, float t_max) const
{
    HitResult closest;
    closest.time = std::numeric_limits<float>::max();

    HitResult intermediateResult;
    bool isHit;

    for(int i = 0; i < objectListSize; i++)
    {
        //std::cout <<"PollObj: " << i << std::endl;
        //Test if each object is hit by ray
        isHit = objectList[i]->hit(r, intermediateResult, t_min, t_max);
        
        if(isHit && intermediateResult.time < closest.time)
        {
            closest = intermediateResult;
        }
    }

    if(closest.time != std::numeric_limits<float>::max())
    {
        result.time   = closest.time;
        result.normal = closest.normal;
        result.point  = closest.point;
        result.material = closest.material;

        // std::cout << "hitResult.material (Being returned from world Hit): " << result.material << std::endl;
        // std::cout << "hitResult.normal (Being returned from world Hit): " << result.normal << std::endl;
        // std::cout << "hitResult.point (Being returned from world Hit): " << result.point << std::endl;
        // std::cout << "hitResult.time (Being returned from world Hit): " << result.time << std::endl;
        return true;
    }

    return false;
}
