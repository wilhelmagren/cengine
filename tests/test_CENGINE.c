#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "SDL2/SDL.h"
#include "../src/CENGINE.h"


int main(int argc, char** argv) {
    Vec3* a = Vec3_Constructor(  0,  0,  0,  1);
    Vec3* b = Vec3_Constructor(  0,  1,  0,  1);
    Vec3* c = Vec3_Constructor(  1,  1,  0,  1);
    Vec3* d = Vec3_Constructor(  1,  0,  0,  1);
    Vec3* e = Vec3_Constructor(  0,  0,  1,  1);
    Vec3* f = Vec3_Constructor(  0,  1,  1,  1);
    Vec3* g = Vec3_Constructor(  1,  1,  1,  1);
    Vec3* h = Vec3_Constructor(  1,  0,  1,  1);

    Polygon* p1 = Polygon_Constructor(a, b, c,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p2 = Polygon_Constructor(a, c, d,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p3 = Polygon_Constructor(b, f, g,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p4 = Polygon_Constructor(b, g, c,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p5 = Polygon_Constructor(d, c, g,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p6 = Polygon_Constructor(d, g, h,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p7 = Polygon_Constructor(h, g, f,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p8 = Polygon_Constructor(h, f, e,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p9 = Polygon_Constructor(e, f, b,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p10 = Polygon_Constructor(e, b, a,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p11 = Polygon_Constructor(e, a, d,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);
    Polygon* p12 = Polygon_Constructor(e, d, h,
            0.0, 0.0, 0.0, 0.02, 0.01, 0.08, GREEN);

    Mesh* mesh = Mesh_Constructor();
    _MeshPush(mesh, p1);
    _MeshPush(mesh, p2);
    _MeshPush(mesh, p3);
    _MeshPush(mesh, p4);
    _MeshPush(mesh, p5);
    _MeshPush(mesh, p6);
    _MeshPush(mesh, p7);
    _MeshPush(mesh, p8);
    _MeshPush(mesh, p9);
    _MeshPush(mesh, p10);
    _MeshPush(mesh, p11);
    _MeshPush(mesh, p12);

    Instance* instance = CENGINE_INIT_FULL(200);
    Mat4x4* proj = Mat4x4_Projection(0.1, 1000.0, 90.0,
            (f4) DEFAULT_WINDOW_H / (f4) DEFAULT_WINDOW_W);
    f4 t_desired = 1000.0 / (f4) TARGET_FPS;

    SDL_bool quit = SDL_FALSE;
    while (!quit) {
        uint64_t t_start = SDL_GetPerformanceCounter();
        SDL_Event event;
        Mesh* copy = _MeshCopy(mesh);

        _MeshRotate(copy, copy);
        _MeshTranslate(copy, 0.0, 0.0, 10.0, copy);
        _MeshProject(copy, proj, copy);

        SDL_RenderSetLogicalSize(instance->renderer, 0, 0);
        SDL_SetRenderDrawColor(instance->renderer, GRAY[0], GRAY[1], GRAY[2], 255);
        SDL_RenderClear(instance->renderer);
        CENGINE_DrawMesh(instance->renderer, copy);
        SDL_RenderPresent(instance->renderer);

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }

        CENGINE_TickMesh(mesh);
        CENGINE_DestroyMesh(copy);

        f4 t_elapsed = (f4) SDL_GetPerformanceCounter() / (f4) t_start;
        f4 delay = t_desired - t_elapsed;
        if (delay < 0.0) fprintf(stdout, "no delay, current frame %0.3f ms behind target render-time...\n", delay);
        SDL_Delay(fmax(delay, 0.0));
    }
    
    CENGINE_DestroyMatrix(proj);
    CENGINE_DestroyMesh(mesh);
    CENGINE_DestroyInstance(instance);
    fprintf(stdout, "All tests passing for CENGINE pipeline!\n");

    return 0;
}
