#pragma once
#include "color.h"
#include "objectCollection.h"
#include "ray.h"

Color rayToColor(const Ray& ray, const ObjectCollection& world);

float randomZeroToOne();

Vec3 randomInUnitCircle();
