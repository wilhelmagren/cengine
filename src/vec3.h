#ifndef VEC3_H
#define VEC3_H
#include "utils.h"

typedef struct {
    f8 x, y, z;
    f8 magnitude;
    u8 pointers;
} Vec3;

Vec3* Vec3_Constructor(f8 x, f8 y, f8 z);
Vec3* _CopyVec3(Vec3* u);
void _Add(Vec3* u, Vec3* v, Vec3* res);
void _Subtract(Vec3* u, Vec3* v, Vec3* res);
void _CrossProduct(Vec3* u, Vec3* v, Vec3* res);
f8 _DotProduct(Vec3* u, Vec3* v);
f8 _Magnitude(f8 x, f8 y, f8 z);

#endif
