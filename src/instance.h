#ifndef INSTANCE_H
#define INSTANCE_H
#include "SDL2/SDL.h"
#include "camera.h"
#include "defaults.h"
#include "mesh.h"

typedef struct {
    Camera* camera;
    SDL_Renderer* renderer;
    SDL_Window* window;
    Mesh* mesh;
} Instance;

Instance* Instance_INIT(Camera* cam, SDL_Renderer* renderer, SDL_Window* window);
Instance* Instance_FULL_INIT();
void Instance_Mesh(Instance* instance, Mesh* mesh);
void Instance_RUN(Instance* instance);
void Instance_Destroy(Instance* instance);

#endif
