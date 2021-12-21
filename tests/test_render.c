#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "SDL2/SDL.h"
#include "../src/render.h"


int main(int argc, char** argv) {

    Vec3* a = Vec3_Constructor(  0,  0,  0);
    Vec3* b = Vec3_Constructor(  0,  1,  0);
    Vec3* c = Vec3_Constructor(  1,  1,  0);

    Polygon* p1 = Polygon_Constructor(a, b, c);

    CENGINE_Instance* instance = CENGINE_INIT_FULL();

    CENGINE_RenderPolygon(instance->renderer, p1, WHITE);

    return 0;
}
