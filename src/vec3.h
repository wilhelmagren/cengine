#ifndef VEC3_H
#define VEC3_H
#include "utils.h"

typedef struct {
    f8 x, y, z, w;
    u8 pointers;
} Vec3;

Vec3* Vec3_Constructor(f8 x, f8 y, f8 z, f8 w);
Vec3* _Vec3Copy(Vec3* u);
void _Vec3Add(Vec3* u, Vec3* v, Vec3* res);
void _Vec3Subtract(Vec3* u, Vec3* v, Vec3* res);
void _Vec3CrossProduct(Vec3* u, Vec3* v, Vec3* res);
void _Vec3Multiply(Vec3* vec, f4 val);
void _Vec3Divide(Vec3* vec, f4 val);
void _Vec3Normalize(Vec3* vec);
void _Vec3ScaleToWindow(Vec3* vec);
f8 _Vec3DotProduct(Vec3* u, Vec3* v);
f8 _Vec3Magnitude(Vec3* vec);

#endif
