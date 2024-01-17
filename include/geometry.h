#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "vec2.h"

vec2 computeCenterPoint(vec2* vertices, int count);

int indexFurthestPoint(vec2* vertices, int count, vec2 d);

vec2 supportFunc(vec2* vertices1, int count1, vec2* vertices2, int count2, vec2 d);

#endif