#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../src/vec3.h"
#include "../src/utils.h"


int main(int argc, char** argv) {

    Vec3* u = Vec3_Constructor( -1,  0,  0);
    Vec3* v = Vec3_Constructor(  2,  4, -2);
    _Add(u, v, u);

    assert(u->x ==  1);
    assert(u->y ==  4);
    assert(u->z == -2);

    _Subtract(u, v, u);

    assert(u->x == -1);
    assert(u->y ==  0);
    assert(u->z ==  0);

    f8 dotres = _DotProduct(u, v);

    assert(dotres == -2.0f);

    fprintf(stdout, "All tests passed for struct Vec3!\n");
    return 0;
}
