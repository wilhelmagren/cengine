#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "mesh.h"
#include "defaults.h"


int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("cengine", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
    if (!window) {
        fprintf(stderr, "Could not create SDL window\n");
        return -2;
    }

    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!rend) {
        fprintf(stderr, "Could not create renderer\n");
        return -3;
    }

    SDL_bool quit = SDL_FALSE;
    while (!quit) {
        SDL_Event event;
        SDL_RenderSetLogicalSize(rend, 0, 0);
        SDL_SetRenderDrawColor(rend, 40, 40, 40, 255);
        SDL_RenderClear(rend);
        SDL_RenderPresent(rend);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
