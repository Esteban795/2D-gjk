#include "../include/vec2.h"


vec2 substract(vec2 a, vec2 b) {
    vec2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

vec2 normalVector(vec2 a) {
    vec2 result;
    result.x = a.y;
    result.y = -a.x;
    return result;
}

float dotProduct(vec2 a, vec2 b) {
    return a.x * b.x + a.y * b.y;
}

vec2 negate(vec2 a) {
    vec2 result;
    result.x = -a.x;
    result.y = -a.y;
    return result;
}

float lengthSquared(vec2 a) {
    return a.x * a.x + a.y * a.y;
}

vec2 tripleProduct(vec2 a, vec2 b, vec2 c) {
    vec2 result;
    float ac = dotProduct(a, c);
    float bc = dotProduct(b, c);
    result.x = b.x * ac - a.x * bc;
    result.y = b.y * ac - a.y * bc;
    return result;
}