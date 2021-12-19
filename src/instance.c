#include <stdlib.h>
#include "SDL2/SDL.h"
#include "instance.h"

Instance* Instance_INIT(Camera* camera, SDL_Renderer* renderer, SDL_Window* window) {
    Instance* inst = (Instance*)malloc(sizeof(Instance));
    inst->camera = camera;
    inst->renderer = renderer;
    inst->window = window;
    inst->mesh = (Mesh*)malloc(sizeof(Mesh));
    return inst;
}

Instance* Instance_FULL_INIT() {
    Instance* inst = (Instance*)malloc(sizeof(Instance));
    inst->mesh = (Mesh*)malloc(sizeof(Mesh));
    printf("FULL INIT for <struct Instance at %p>\n", inst);
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow("cengine", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_W, DEFAULT_WINDOW_H, 0);
    if (!window) {
        fprintf(stderr, "Could not create SDL window: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        fprintf(stderr, "Could not create SDL renderer: %s\n", SDL_GetError());
        return NULL;
    }

    inst->renderer = renderer;
    inst->window = window;
    inst->camera = Camera_New(0.0f, 0.0f, 0.0f,
            DEFAULT_WINDOW_W, DEFAULT_WINDOW_H, DEFAULT_FOV, 0.1f, 1000.0f);

    return inst;
}

void Instance_Mesh(Instance* instance, Mesh* mesh) {
    memcpy(instance->mesh, mesh, sizeof(mesh));
}

void Instance_RUN(Instance* instance) {
    SDL_bool quit = SDL_FALSE;
    while (!quit) {
        SDL_Event event;
        SDL_RenderSetLogicalSize(instance->renderer, 0, 0);
        SDL_SetRenderDrawColor(instance->renderer, 40, 40, 40, 255);
        SDL_RenderClear(instance->renderer);
        SDL_RenderPresent(instance->renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }
    }

    Instance_Destroy(instance);
}

void Instance_Destroy(Instance* instance) {
    printf("destroying <struct Instance at %p>\n", instance);
    SDL_DestroyRenderer(instance->renderer);
    SDL_DestroyWindow(instance->window);
    SDL_Quit();
    free(instance->camera);
    free(instance);
}
