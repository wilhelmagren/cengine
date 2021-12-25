#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "vec3.h"


Vec3* Vec3_Constructor(f8 x, f8 y, f8 z, f8 w) {
    Vec3* vec = (Vec3*)malloc(sizeof(Vec3));
    vec->x = x;
    vec->y = y;
    vec->z = z;
    vec->w = w;
    vec->pointers = 0;
    return vec;
}

Vec3* _Vec3Copy(Vec3* u) {
    return Vec3_Constructor(u->x, u->y, u->z, u->w);
}

void _Vec3Add(Vec3* u, Vec3* v, Vec3* res) {
    res->x = u->x + v->x;
    res->y = u->y + v->y;
    res->z = u->z + v->z;
}

void _Vec3Subtract(Vec3* u, Vec3* v, Vec3* res) {
    res->x = u->x - v->x;
    res->y = u->y - v->y;
    res->z = u->z - v->z;
}

void _Vec3CrossProduct(Vec3* u, Vec3* v, Vec3* res) {
    res->x = u->y*v->z - u->z*v->y;
    res->y = u->z*v->x - u->x*v->z;
    res->z = u->x*v->y - u->y*v->x;
}

void _Vec3Multiply(Vec3* vec, f4 val) {
    vec->x *= val;
    vec->y *= val;
    vec->z *= val;
}

void _Vec3Divide(Vec3* vec, f4 val) {
    if (val == 0.0) return;
    vec->x /= val;
    vec->y /= val;
    vec->z /= val;
}

void _Vec3Normalize(Vec3* vec) {
    f4 magnitude = _Vec3Magnitude(vec);
    _Vec3Divide(vec, magnitude);
}

void _Vec3ScaleToWindow(Vec3* vec) {
    vec->x += (f4) 1.0;
    vec->y += (f4) 1.0;
    vec->x *= (f4) 0.5 * (f4) DEFAULT_WINDOW_W;
    vec->y *= (f4) 0.5 * (f4) DEFAULT_WINDOW_H;
}

f8 _Vec3DotProduct(Vec3* u, Vec3* v) {
    return u->x*v->x + u->y*v->y + u->z*v->z;
}

f8 _Vec3Magnitude(Vec3* vec) {
    return (f8) sqrt(vec->x*vec->x + vec->y*vec->y + vec->z*vec->z);
}

