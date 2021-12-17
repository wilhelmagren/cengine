#ifndef MATS_H
#define MATS_H
#include "vecs.h"

typedef struct {
    float m[4][4]; 
} Mat4x4;

Mat4x4* Mat4x4_new();
Mat4x4* Mat4x4_Proj_new(float zn, float zf, float fov, float ratio);
Mat4x4* Mat4x4_RotX_new(float theta);
Mat4x4* Mat4x4_RotZ_new(float theta);
void Mat4x4_print(Mat4x4* mat, char* name);

void MatMul(Vec3d* vec, Mat4x4* mat, Vec3d* res);
#endif
