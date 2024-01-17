#ifndef GJK_H
#define GJK_H

#include <stdbool.h>
#include <stdio.h>


#include "vec2.h"
#include "geometry.h"

bool gjk(vec2* vertices1, int count1, vec2* vertices2,int count2);

#endif