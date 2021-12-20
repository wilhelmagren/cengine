#include <stdlib.h>
#include <stdio.h>
#include "SDL2/SDL.h"

CENGINE_Instance* CENGINE_INIT(SDL_Window* window, SDL_Renderer* renderer) {
    CENGINE_Instance* instance = (CENGINE_Instance*)malloc(sizeof(CENGINE_Instance));
    instance->window = window;
    instance->renderer = renderer;
    return instance;
}

CENGINE_Instance* CENGINE_INIT_FULL() {
    CENGINE_Instance* instance = (CENGINE_Instance*)malloc(sizeof(CENGINE_Instance));

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("cengine", SDL_WINDOWPOS_CENTERED,
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

    instance->window = window;
    instance->renderer = renderer;
    return instance;
}
