#include "../include/polygon.h"

void freePolygon(polygon p) {
    free(p.vertices);
}

void printPolygon(polygon p){
    printf("Polygon with %d vertices:\n",p.n);
    for (int i = 0; i < p.n; i++) {
        printf("Vertex %d: (%lf,%lf)\n",i,p.vertices[i].x,p.vertices[i].y);
    }
}