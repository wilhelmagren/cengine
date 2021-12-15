#include <stdlib.h>
#include <stdio.h>
#include "vecs.h"


/*
 * floating point vector 3d implementation below! (Vec3d)
 *
 */
Vec3d* Vec3d_new(float x, float y, float z) {
    Vec3d* vec = (Vec3d*)malloc(sizeof(Vec3d));
    vec->x = x;
    vec->y = y;
    vec->z = z;
    return vec;
}

void Vec3d_print(Vec3d* vec) {
    char* string = "<struct Vec3d: (x: %0.2f, y: %0.2f, z: %0.2f) at %p>\n";
    printf(string, vec->x, vec->y, vec->z, vec);
}

void Vec3d_add(Vec3d* u, Vec3d* v, Vec3d* res) {
    res->x = u->x+v->x;
    res->y = u->y+v->y;
    res->z = u->z+v->z;
}

// a x b = [(a2b3 - a3b2), -(a1b3 - a3b1), (a1b2 - a2b1)]
void Vec3d_crossprod(Vec3d* u, Vec3d* v, Vec3d* res) {
    res->x = u->y*v->z - u->z*v->y;
    res->y = u->z*v->x - u->x*v->z;
    res->z = u->x*v->y - u->y*v->x;
}

float Vec3d_dotprod(Vec3d* u, Vec3d* v) {
    float x = u->x*v->x;
    float y = u->y*v->y;
    float z = u->z*v->z;
    return x + y + z;
}

/*
 * integer vector 3d implementation below! (iVec3d)
 * 
 * functions:
 *  (constructor) iVec3d_new(int, int, int) => iVec3d*
 *
 */
iVec3d* iVec3d_new(int x, int y, int z) {
    iVec3d* ivec = (iVec3d*)malloc(sizeof(iVec3d));
    ivec->x = x;
    ivec->y = y;
    ivec->z = z;
}

void iVec3d_print(iVec3d* ivec) {
    char* string = "<struct iVec3d (x: %d, y: %d, z: %d) at %p>\n";
    printf(string, ivec->x, ivec->y, ivec->z, ivec);
}

/*
int main() {
    Vec3d* vec = Vec3d_new(1.0f, 1.0f, 2.0f);
    Vec3d* v = Vec3d_new(2.0f, -2.0f, 4.0f);
    Vec3d_print(vec);
    Vec3d_print(v);
    float dot = Vec3d_dotprod(vec, v);
    printf("dot product res: %f\n", dot);
    Vec3d_add(vec, v, vec);
    free(v);
    // free(vec);
    Vec3d_print(vec);
    return 0;
}
*/
