#ifndef INSTANCE_H
#define INSTANCE_H
#include "camera.h"

typedef struct {
    Camera* cam;
    SDL_Renderer* renderer;
    SDL_Window* window;
} Instance;

Instance* Instance(uint8_t WINDOW_W, uint8_t WINDOW_H, float RATIO,
        Camera* cam, SDL_Renderer* renderer, SDL_Window* window);

#endif
