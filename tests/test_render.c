#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "SDL2/SDL.h"
#include "../src/matrices.h"
#include "../src/render.h"


int main(int argc, char** argv) {

    Vec3* a = Vec3_Constructor(  0,  0,  3,  1);
    Vec3* b = Vec3_Constructor(  0,  1,  3,  1);
    Vec3* c = Vec3_Constructor(  1,  1,  3,  1);

    Polygon* p1 = Polygon_Constructor(a, b, c);
    Polygon* p2 = _PolygonCopy(p1);
    Mat4x4* proj = Mat4x4_Projection(0.1, 1000.0, 90.0,
            (f4) DEFAULT_WINDOW_H / (f4) DEFAULT_WINDOW_W);

    CENGINE_Instance* instance = CENGINE_INIT_FULL(1000);

    _PolygonProject(p1, proj, p2);

    SDL_RenderSetLogicalSize(instance->renderer, 0, 0);
    SDL_SetRenderDrawColor(instance->renderer, GRAY[0], GRAY[1], GRAY[2], 255);
    SDL_RenderClear(instance->renderer);
    CENGINE_RenderPolygon(instance->renderer, p2, WHITE);
    SDL_RenderPresent(instance->renderer);

    SDL_Delay(5000);

    CENGINE_DestroyInstance(instance);
    CENGINE_DestroyPolygon(p1);
    free(proj);

    return 0;
}
