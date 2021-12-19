#ifndef VECS_H
#define VECS_H

typedef struct {
    float x, y, z;
} Vec3;

Vec3* Vec3_new(float x, float y, float z);
void Vec3_print(Vec3* vec);
void Vec3_add(Vec3* u, Vec3* v, Vec3* res);
void Vec3_crossprod(Vec3* u, Vec3* v, Vec3* res);
float Vec3_dotprod(Vec3* u, Vec3* v);


typedef struct {
    int x, y, z;
} iVec3;

iVec3* iVec3_new(int x, int y, int z);
void iVec3_print(iVec3* ivec);

#endif
