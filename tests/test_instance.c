#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "SDL2/SDL.h"
#include "../src/instance.h"


int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("CENGINE_Instance test", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_W, DEFAULT_WINDOW_H, 0);
    if (!window) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
        return -1;
    }

    CENGINE_Instance* instance = CENGINE_INIT(window, renderer);
    SDL_Delay(1000);
    CENGINE_DestroyInstance(instance);

    instance = CENGINE_INIT_FULL(1000);
    CENGINE_LOOP(instance);
    CENGINE_DestroyInstance(instance);

    fprintf(stdout, "All tests passed for struct CENGINE_Instance!\n");
    return 0;
}
