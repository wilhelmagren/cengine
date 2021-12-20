#include <math.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "instance.h"
#include "camera.h"

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
    instance->mesh->pidx = mesh->pidx;
    memcpy(instance->mesh->polygons, mesh->polygons, sizeof(mesh->polygons));
}

void CENGINE_MeshCopy(Mesh* prev, Mesh* copy) {
    copy->pidx = prev->pidx;
    memcpy(copy->polygons, prev->polygons, sizeof(prev->polygons));
}

void CENGINE_DeepcopyMesh(Mesh* prev, Mesh* copy) {
    copy->pidx = prev->pidx;
    uint8_t i;
    for (i = 0; i < prev->pidx; i++) {
        Polygon* prevp = prev->polygons[i];
        Vec3* pu = prevp->vecs[0];
        Vec3* pv = prevp->vecs[1];
        Vec3* pw = prevp->vecs[2];
        Vec3* u = Vec3_new(pu->x, pu->y, pu->z);
        Vec3* v = Vec3_new(pv->x, pv->y, pv->z);
        Vec3* w = Vec3_new(pw->x, pw->y, pw->z);
        copy->polygons[i] = Polygon_new(u, v, w,
                prevp->angle, prevp->vx, prevp->vy,
                prevp->vz, prevp->color);
    }
}

void CENGINE_TickMesh(Mesh* mesh) {
    uint8_t i;
    for (i = 0; i < mesh->pidx; i++) {
        _TickPolygon(mesh->polygons[i]);
    }
}

void Instance_RUN(Instance* instance) {
    Mesh* meshcopy = Mesh_new();
    CENGINE_MeshCopy(instance->mesh, meshcopy);
    SDL_bool quit = SDL_FALSE;

    float ms_target = 1000.0f / (float)DEFAULT_FPS_TARGET;

    while (!quit) {
        uint64_t t_start = SDL_GetPerformanceCounter();

        Mesh* meshcopy = Mesh_new();
        CENGINE_DeepcopyMesh(instance->mesh, meshcopy);

        SDL_Event event;
        SDL_RenderSetLogicalSize(instance->renderer, 0, 0);
        SDL_SetRenderDrawColor(instance->renderer, 40, 40, 40, 255);
        SDL_RenderClear(instance->renderer);
        CENGINE_ProjectPolygons(instance->camera, meshcopy);
        //CENGINE_RotatePolygons(meshcopy);
        CENGINE_ScalePolygons(instance->camera, meshcopy);
        CENGINE_RenderMesh(instance, meshcopy);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }

        Mesh_Destroy(meshcopy);
        CENGINE_TickMesh(instance->mesh);
        
        float ms_elapsed = (float)(SDL_GetPerformanceCounter() - t_start)/(float)SDL_GetPerformanceFrequency()*1000.0f;
        float ms_delay = ms_target - ms_elapsed;
        if (ms_delay <= 0.0f) {
            printf("no delay, current frame %0.3f ms behind target render-time...\n", ms_delay);
        } else {
            SDL_Delay(fmax(0.0f, ms_delay));
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
