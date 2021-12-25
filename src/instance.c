#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "instance.h"

Instance* CENGINE_INIT(SDL_Window* window, SDL_Renderer* renderer) {
    Instance* instance = (Instance*)malloc(sizeof(Instance));
    instance->window = window;
    instance->renderer = renderer;
    return instance;
}

Instance* CENGINE_INIT_FULL(f4 delay) {
    Instance* instance = (Instance*)malloc(sizeof(Instance));

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow("cengine", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_W, DEFAULT_WINDOW_H, 0);
    if (!window) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
        return NULL;
    }

    instance->window = window;
    instance->renderer = renderer;

    SDL_Delay(fmax(0.0, delay));

    return instance;
}

void CENGINE_LOOP(Instance* instance) {
    SDL_bool quit = SDL_FALSE;
    while (!quit) {

        SDL_Event event;
        SDL_RenderSetLogicalSize(instance->renderer, 0, 0);
        SDL_SetRenderDrawColor(instance->renderer, GRAY[0], GRAY[1], GRAY[2], 255);
        SDL_RenderClear(instance->renderer);
        SDL_RenderPresent(instance->renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }
    }
}

