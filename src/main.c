#include <SDL2/SDL.h>
#include <stdio.h>

#include "../include/vec2.h"
#include "../include/geometry.h"
#include "../include/gjk.h"
#include "../include/read_file.h"
#include "../include/polygon.h"

void DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius){
   const int32_t diameter = (radius * 2);
   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);
   while (x >= y){
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);
      if (error <= 0){
        ++y;
        error += ty;
        ty += 2;
      }
      if (error > 0){
        --x;
        tx += 2;
        error += (tx - diameter);
      }
   }
}

void drawPolygon(SDL_Renderer* renderer, vec2* vertices, int count,bool collided) {
    if (collided) SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    else SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < count; i++) {
        DrawCircle(renderer,vertices[i].x,vertices[i].y,5);
    }
    for (int i = 0; i < count; i++) {
        SDL_RenderDrawLine(renderer,vertices[i].x,vertices[i].y,vertices[(i+1)%count].x,vertices[(i+1)%count].y);
    }
}

int start_SDL(SDL_Window** window,SDL_Renderer** renderer,int width,int height, const char* title){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;
    *window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
    if (*window == NULL) return 1;
    *renderer = SDL_CreateRenderer(*window,-1,SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) return 1;
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage : ./bin/gjk <path_to_file>\n");
        return 1;
    }
    int count;
    polygon* polygons = readFile(argv[1],&count);
    if (count < 1) {
        printf("Need at least two polygons.\n");
        return 1;
    }
    for (int i = 0; i < count;i++) {
        printPolygon(polygons[i]);
    }
    if (polygons == NULL) return EXIT_FAILURE;
    bool* collidedPolygons = malloc(sizeof(bool) * count); 
    SDL_Window* window;
    SDL_Renderer* renderer;
    int status = start_SDL(&window,&renderer,WIDTH,HEIGHT,"2D GJK demo, by Esteban795.");
    if (status == 1) return EXIT_FAILURE;
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    while (true) {
        for (int i = 0; i < count; i++) {
            collidedPolygons[i] = gjk(polygons[i].vertices,polygons[i].n, polygons[(i+1)%count].vertices,polygons[(i+1)%count].n);
            printf("Polygon %d and %d collided : %s\n",i,i+1,collidedPolygons[i] ? "true" : "false");
            drawPolygon(renderer,polygons[i].vertices,polygons[i].n,collidedPolygons[i]);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }
    for (int i = 0; i < count; i++) {
        freePolygon(polygons[i]);
    }
    free(polygons);
    free(collidedPolygons);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}