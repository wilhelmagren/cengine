#ifndef VECS_H
#define VECS_H

/*
 * floating point Vec3d struct declarations below
 */
typedef struct {
    float x, y, z;
} Vec3d;

Vec3d* Vec3d_new(float x, float y, float z);
void Vec3d_print(Vec3d* vec);
void Vec3d_add(Vec3d* u, Vec3d* v, Vec3d* res);
void Vec3d_crossprod(Vec3d* u, Vec3d* v, Vec3d* res);
float Vec3d_dotprod(Vec3d* u, Vec3d* v);


/*
 * integer Vec3d struct declarations below
 */
typedef struct {
    int x, y, z;
} iVec3d;

iVec3d* iVec3d_new(int x, int y, int z);
void iVec3d_print(iVec3d* ivec);

#endif
