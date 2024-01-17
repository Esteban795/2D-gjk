#include "../include/read_file.h"

polygon* readFile(char* filename,int* count) {
    FILE* f = fopen(filename,"r");
    if (f == NULL) {
        perror("Error opening file");
        return NULL;
    }
    fscanf(f,"%d\n",count);
    polygon* polygons = malloc(sizeof(polygon) * (*count));
    for (int i = 0; i < *count; i++) {
        fscanf(f,"%d\n",&polygons[i].n);
        vec2* vertices = malloc(sizeof(vec2) * polygons[i].n);
        for (int j = 0; j < polygons[i].n; j++) {
            fscanf(f,"%lf,%lf\n",&vertices[j].x,&vertices[j].y);
            vertices[j].x *= 10;
            vertices[j].y *= 10;
            vertices[j].x += WIDTH/2;
            vertices[j].y += HEIGHT/2;

        }
        polygons[i].vertices = vertices;
    }
    return polygons;
}