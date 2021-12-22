#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../src/vec3.h"
#include "../src/utils.h"


int main(int argc, char** argv) {

    Vec3* u = Vec3_Constructor( -1,  0,  0);
    Vec3* v = Vec3_Constructor(  2,  4, -2);
    _Vec3Add(u, v, u);

    assert(u->x ==  1);
    assert(u->y ==  4);
    assert(u->z == -2);

    _Vec3Subtract(u, v, u);

    assert(u->x == -1);
    assert(u->y ==  0);
    assert(u->z ==  0);

    f8 dotprod = _Vec3DotProduct(u, v);

    assert(dotprod == -2.0);

    f8 magnitude_u = u->magnitude;
    f8 magnitude_v = v->magnitude;

    assert(magnitude_u ==  1.0);
    assert(magnitude_v == sqrt(24.0));

    Vec3* cross = Vec3_Constructor(  0,  0,  0);
    _Vec3CrossProduct(u, v, cross);

    assert(cross->x ==  0.0);
    assert(cross->y == -2.0);
    assert(cross->z == -4.0);

    fprintf(stdout, "All tests passed for struct Vec3!\n");
    return 0;
}
