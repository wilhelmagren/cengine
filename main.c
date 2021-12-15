#include <stdio.h>
#include "SDL2/SDL.h"
#include "defaults.h"

typedef struct {
    float x, y, z;
} vec3d;

typedef struct {
    vec3d vecs[3];
} triangle;

typedef struct {
    triangle triangles[1024];
} mesh;

int main()
{
    triangle* tri1 = (triangle*)malloc(sizeof(triangle));
    tri1->vecs[0] = {0.0f, 0.0f, 0.0f};
    tri1->vecs[1] = {0.0f, 1.0f, 0.0f};
    tri1->vecs[2] = {1.0f, 1.0f, 0.0f};
    mesh* m;
    m->triangles[0] = tri1;
    

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *screen = SDL_CreateWindow("My application", SCREEN_START_X, SCREEN_START_Y, SCREEN_W, SCREEN_H, 0);
    if(!screen) {
        fprintf(stderr, "Could not create window\n");
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE);
    if(!renderer) {
        fprintf(stderr, "Could not create renderer\n");
        return 1;
    }
    SDL_bool done = SDL_FALSE;
    //const Uint32 startMs = SDL_GetTicks();
    //while( SDL_GetTicks() - startMs < 2000 )
    while(!done)
    {
        SDL_Event event;

        //Render something
        SDL_RenderSetLogicalSize(renderer,0,0);

        //Set colour of renderer
        SDL_SetRenderDrawColor(renderer,10,10,10,255);
        SDL_RenderClear(renderer);

        // Draw a line between p1 and p2

        //Show all the has been done behind the scenes
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = SDL_TRUE;
            }
        }
    }

    SDL_DestroyWindow(screen);
    SDL_Quit();
    return 0;
}

