#include <stdlib.h>
#include <stdio.h>
#include "vecs.h"


Vec3* Vec3_new(float x, float y, float z) {
    Vec3* vec = (Vec3*)malloc(sizeof(Vec3));
    vec->x = x;
    vec->y = y;
    vec->z = z;
    return vec;
}

void Vec3_print(Vec3* vec) {
    char* string = "<struct Vec3: (x: %0.2f, y: %0.2f, z: %0.2f) at %p>\n";
    printf(string, vec->x, vec->y, vec->z, vec);
}

void Vec3_add(Vec3* u, Vec3* v, Vec3* res) {
    res->x = u->x+v->x;
    res->y = u->y+v->y;
    res->z = u->z+v->z;
}

void Vec3_crossprod(Vec3* u, Vec3* v, Vec3* res) {
    res->x = u->y*v->z - u->z*v->y;
    res->y = u->z*v->x - u->x*v->z;
    res->z = u->x*v->y - u->y*v->x;
}

float Vec3_dotprod(Vec3* u, Vec3* v) {
    float x = u->x*v->x;
    float y = u->y*v->y;
    float z = u->z*v->z;
    return x + y + z;
}

void Vec3_Destroy(Vec3* vec) {
    free(vec);
}

iVec3* iVec3_new(int x, int y, int z) {
    iVec3* ivec = (iVec3*)malloc(sizeof(iVec3));
    ivec->x = x;
    ivec->y = y;
    ivec->z = z;
    return ivec;
}

void iVec3_print(iVec3* ivec) {
    char* string = "<struct iVec3 (x: %d, y: %d, z: %d) at %p>\n";
    printf(string, ivec->x, ivec->y, ivec->z, ivec);
}

