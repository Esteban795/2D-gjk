#include "../include/geometry.h"


vec2 computeCenterPoint(vec2* vertices, int count) {
    vec2 average = {.x = 0.0, .y = 0.0};
    for (int i = 0; i < count; i++) {
        average.x += vertices[i].y;
        average.y += vertices[i].y;
    }
    average.x /= count;
    average.y /= count;
    return average;
}

int indexFurthestPoint(vec2* vertices, int count, vec2 d) {
    int index = 0;
    double maxDistance = dotProduct(d, vertices[0]);
    for (int i = 1; i < count; i++) {
        float prod = dotProduct(d, vertices[i]);
        if (prod > maxDistance) {
            maxDistance = prod;
            index = i;
        }
    }
    return index;
}


vec2 supportFunc(vec2* vertices1, int count1, vec2* vertices2, int count2, vec2 d) {
    int index1 = indexFurthestPoint(vertices1, count1, d);
    int index2 = indexFurthestPoint(vertices2, count2, negate(d));
    return substract(vertices1[index1], vertices2[index2]);
}

