#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../src/CENGINE.h"


int main(int argc, char** argv) {

    Vec3* a = Vec3_Constructor(  0,  0,  0,  0);
    Vec3* b = Vec3_Constructor(  0,  1,  0,  0);
    Vec3* c = Vec3_Constructor(  1,  1,  0,  0);
    Vec3* d = Vec3_Constructor(  1,  0, -0,  0);

    Polygon* p1 = Polygon_Constructor(a, b, c);
    Polygon* p2 = Polygon_Constructor(a, c, d);

    assert(a->pointers == 2);
    assert(d->pointers == 1);

    CENGINE_DestroyPolygon(p1);

    assert(a->pointers == 1);
    assert(b->pointers == 1);
    assert(c->pointers == 1);

    CENGINE_DestroyPolygon(p2);

    fprintf(stdout, "All test passed for struct Polygon!\n");

    return 0;
}
