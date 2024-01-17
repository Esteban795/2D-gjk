#include "../include/gjk.h"

bool gjk(vec2* vertices1, int count1, vec2* vertices2,int count2) {
    int index = 0;
    vec2 a,b,c,d,ao,ab,ac,simplex[3];
    vec2 initPos1 = computeCenterPoint(vertices1, count1);
    vec2 initPos2 = computeCenterPoint(vertices2, count2);
    d = substract(initPos1, initPos2);

    if (d.x == 0 && d.y == 0) { // same center
        d.x = 3.f;
    }

    a = simplex[0] = supportFunc(vertices1, count1, vertices2, count2, d);
    if (dotProduct(a,d) <= 0) {
        return false;
    }

    d = negate(a);
    while (true) {
        a = simplex[++index] = supportFunc(vertices1, count1, vertices2, count2, d);
        if (dotProduct(a,d) <= 0) {
            return false;
        }
        ao = negate(a);
        if (index < 2) {
            b = simplex[0];
            ab = substract(b,a);
            d = tripleProduct(ab, ao, ab);
            if (lengthSquared(d) == 0) {
                d = normalVector(ab);
            }
            continue;
        }
        b = simplex[1];
        c = simplex[0];
        ab = substract(b,a);
        ac = substract(c,a);

        vec2 n_ac = tripleProduct(ab, ac, ac);
        vec2 n_ab = tripleProduct(ac, ab, ab);
        if (dotProduct(n_ac, ao) >= 0) {
            d = n_ac;
        } else {
            if (dotProduct(n_ab,ao) < 0) return true;
            simplex[0] = simplex[1];
            d = n_ab;
        }
        simplex[1] = simplex[2];
        --index;
    }
    return false;
}