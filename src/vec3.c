#include <stdlib.h>
#include <math.h>
#include "vec3.h"


Vec3* Vec3_Constructor(s16 x, s16 y, s16 z) {
    Vec3* vec = (Vec3*)malloc(sizeof(Vec3));
    vec->x = x;
    vec->y = y;
    vec->z = z;
    vec->magnitude = _Magnitude(x, y, z);
    return vec;
}

void _Add(Vec3* u, Vec3* v, Vec3* res) {
    res->x = u->x + v->x;
    res->y = u->y + v->y;
    res->z = u->z + v->z;
}

void _Subtract(Vec3* u, Vec3* v, Vec3* res) {
    res->x = u->x - v->x;
    res->y = u->y - v->y;
    res->z = u->z - v->z;
}

void _CrossProduct(Vec3* u, Vec3* v, Vec3* res) {
    res->x = u->y*v->z - u->z*v->y;
    res->y = u->z*v->x - u->x*v->z;
    res->z = u->x*v->y - u->y*v->x;
}

f8 _DotProduct(Vec3* u, Vec3* v) {
    return u->x*v->x + u->y*v->y + u->z*v->z;
}

f8 _Magnitude(s16 x, s16 y, s16 z) {
    return (f8)sqrt(x*x + y*y + z*z);
}

