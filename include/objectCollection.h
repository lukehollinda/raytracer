#pragma once
#include "renderableObject.h"

class ObjectCollection : public RenderableObject
{
private:
    RenderableObject ** objectList;
    int objectListSize;

public:

    ObjectCollection(RenderableObject ** objects, int size){ objectList = objects; objectListSize = size;}
    bool hit(const Ray& r, HitResult& result, float t_min = 0, float t_max = std::numeric_limits<float>::max() ) const;

};