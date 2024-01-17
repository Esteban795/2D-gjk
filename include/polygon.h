#ifndef POLYGON_H
#define POLYGON_H

#include <stdio.h>
#include <stdlib.h>

#include "vec2.h"

struct Polygon {
    int n;
    vec2* vertices;
};

typedef struct Polygon polygon;

void freePolygon(polygon p);

void printPolygon(polygon p);
#endif
