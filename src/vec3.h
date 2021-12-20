#ifndef VEC3_H
#define VEC3_H
#include "utils.h"

typedef struct {
    s16 x, y, z;
    f8 magnitude;
    u8 pointers;
} Vec3;

Vec3* Vec3_Constructor(s16 x, s16 y, s16 z);
Vec3* _CopyVec3(Vec3* u);
void _Add(Vec3* u, Vec3* v, Vec3* res);
void _Subtract(Vec3* u, Vec3* v, Vec3* res);
void _CrossProduct(Vec3* u, Vec3* v, Vec3* res);
f8 _DotProduct(Vec3* u, Vec3* v);
f8 _Magnitude(s16 x, s16 y, s16 z);

#endif
