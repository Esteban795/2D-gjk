#ifndef VEC2_H
#define VEC2_H

struct Vec2 {
    double x;
    double y;
};

typedef struct Vec2 vec2;

vec2 substract(vec2 a, vec2 b);

vec2 normalVector(vec2 a);

double dotProduct(vec2 a, vec2 b);

vec2 negate(vec2 a);

double lengthSquared(vec2 a);

vec2 tripleProduct(vec2 a, vec2 b, vec2 c);
#endif