#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "mesh.h"
#include "defaults.h"
#include "mats.h"
#include "vecs.h"
#include "polygon.h"
#include "mesh.h"
#include "draw.h"

int main(int argc, char** argv) {

    Vec3d* a = Vec3d_new(0.0f, 0.0f, 0.0f);
    Vec3d* b = Vec3d_new(0.0f, 1.0f, 0.0f);
    Vec3d* c = Vec3d_new(1.0f, 1.0f, 0.0f);
    Vec3d* d = Vec3d_new(1.0f, 0.0f, 0.0f);
    Vec3d* e = Vec3d_new(0.0f, 0.0f, 1.0f);
    Vec3d* f = Vec3d_new(0.0f, 1.0f, 1.0f);
    Vec3d* g = Vec3d_new(1.0f, 1.0f, 1.0f);
    Vec3d* h = Vec3d_new(1.0f, 0.0f, 1.0f);

    Polygon* p1 = Polygon_new(a, b, c);
    Polygon* p2 = Polygon_new(a, c, d);
    Polygon* p3 = Polygon_new(d, c, g);
    Polygon* p4 = Polygon_new(d, g, h);
    Polygon* p5 = Polygon_new(h, g, f);
    Polygon* p6 = Polygon_new(h, f, e);
    Polygon* p7 = Polygon_new(e, f, b);
    Polygon* p8 = Polygon_new(e, b, a);
    Polygon* p9 = Polygon_new(b, f, g);
    Polygon* p10 = Polygon_new(b, g, c);
    Polygon* p11 = Polygon_new(e, a, d);
    Polygon* p12 = Polygon_new(e, d, h);

    Mesh* mesh = Mesh_new();
    Mesh_add(mesh, p1);
    Mesh_add(mesh, p2);
    Mesh_add(mesh, p3);
    Mesh_add(mesh, p4);
    Mesh_add(mesh, p5);
    Mesh_add(mesh, p6);
    Mesh_add(mesh, p7);
    Mesh_add(mesh, p8);
    Mesh_add(mesh, p9);
    Mesh_add(mesh, p10);
    Mesh_add(mesh, p11);
    Mesh_add(mesh, p12);

    Mesh_print(mesh);

    float zn = 1.0f, zf = 10000.0f;
    float fov = 100.0f, ratio = (float)WINDOW_H/(float)WINDOW_W;
    MatProj* proj = MatProj_new(zn, zf, fov, ratio);
    MatProj_print(proj);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("cengine", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
    if (!window) {
        fprintf(stderr, "Could not create SDL window: %s\n", SDL_GetError());
        return -2;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        fprintf(stderr, "Could not create SDL renderer: %s\n", SDL_GetError());
        return -3;
    }

    SDL_bool quit = SDL_FALSE;
    float counter = 0;
    float desired_ms = 1000.0f / (float) FPS_TARGET;
    while (!quit) {
        counter += 0.05f;
        if (counter >= 360.0f) {
            counter = 0;
        }
        uint64_t t_start = SDL_GetPerformanceCounter();
        MatRotX* rotX = MatRotX_new(counter);
        MatRotZ* rotZ = MatRotZ_new(counter);

        SDL_Event event;
        SDL_RenderSetLogicalSize(renderer, 0, 0);
        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
        SDL_RenderClear(renderer);
        Draw_mesh(renderer, mesh, proj->mat, rotX->mat, rotZ->mat, WHITE);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }
        free(rotX);
        free(rotZ);
        uint64_t t_end = SDL_GetPerformanceCounter();
        float ms_elapsed = (float)(t_end-t_start)/(float)SDL_GetPerformanceFrequency()*1000.0f;
        if (ms_elapsed <= 0.0f) {
            printf("Frame rendering time: %0.06f ms, target FPS: %d, skipping delay...",
                    ms_elapsed, FPS_TARGET);
        } else {
            printf("Frame rendering time: %0.6f ms, target FPS: %d, delaying %0.6f ms. Theta=%0.2f\n", ms_elapsed, FPS_TARGET, desired_ms-ms_elapsed, counter);
            SDL_Delay(floor(desired_ms - ms_elapsed));
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
