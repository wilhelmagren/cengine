#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "../src/mesh.h"
#include "../src/defaults.h"
#include "../src/matrices.h"
#include "../src/vecs.h"
#include "../src/polygon.h"
#include "../src/mesh.h"
#include "../src/draw.h"
#include "../src/colors.h"

int main(int argc, char** argv) {

    Vec3* a = Vec3_new(0.0f, 0.0f, 0.0f);
    Vec3* b = Vec3_new(0.5f, 1.0f, 0.5f);
    Vec3* c = Vec3_new(1.0f, 0.0f, 0.0f);
    Vec3* d = Vec3_new(0.0f, 0.0f, 1.0f);
    Vec3* e = Vec3_new(1.0f, 0.0f, 1.0f);

    Polygon* p1 = Polygon_new(a, b, c);
    Polygon* p2 = Polygon_new(c, b, e);
    Polygon* p3 = Polygon_new(d, b, a);
    Polygon* p4 = Polygon_new(e, b, d);
    Polygon* p5 = Polygon_new(d, a, c);
    Polygon* p6 = Polygon_new(d, c, e);
    
    Mesh* mesh = Mesh_new();
    Mesh_push(mesh, p1);
    Mesh_push(mesh, p2);
    Mesh_push(mesh, p3);
    Mesh_push(mesh, p4);
    Mesh_push(mesh, p5);
    Mesh_push(mesh, p6);

    Mesh_print(mesh);
 
    float zn = 0.1f, zf = 10000.0f;
    float fov = 70.0f, ratio = (float)WINDOW_H/(float)WINDOW_W;
    Mat4x4* proj = Mat4x4_Proj(zn, zf, fov, ratio);

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
    float theta = 0.0f, dtheta = 2.0f / (float)FPS_TARGET;
    float velX = 0.5f, velY = 0.0f, velZ = 1.0f;
    float desired_ms = 1000.0f / (float)FPS_TARGET;
    printf("target fps: %d, target frame render-time: %f ms\n", FPS_TARGET, desired_ms);
    printf("velocities: (x=%0.2f, y=%0.2f, z=%0.2f)\n", velX, velY, velZ);
    printf("frame theta update=%0.2f\n", dtheta);

    while (!quit) {
        theta += dtheta;
        if (theta >= 360.0f) {
            theta = 0.0f;
        }
        uint64_t t_start = SDL_GetPerformanceCounter();
        Mat4x4* rotX = Mat4x4_RotX(theta, velX);
        Mat4x4* rotY = Mat4x4_RotY(theta, velY);
        Mat4x4* rotZ = Mat4x4_RotZ(theta, velZ);

        SDL_Event event;
        SDL_RenderSetLogicalSize(renderer, 0, 0);
        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
        SDL_RenderClear(renderer);
        Draw_mesh(renderer, mesh, proj, rotX, rotY, rotZ, WHITE);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }

        uint64_t t_end = SDL_GetPerformanceCounter();
        float ms_elapsed = (float)(t_end-t_start)/(float)SDL_GetPerformanceFrequency()*1000.0f;
        float delay = desired_ms - ms_elapsed;
        if (delay <= 0.0f) {
            printf("no delay, current frame %0.3f ms behind target render-time...\n", delay);
        } else {
            SDL_Delay(fmax(0.0f, delay));
        }

        free(rotX);
        free(rotY);
        free(rotZ);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
