#ifndef MATRICES_H
#define MATRICES_H
#include "vecs.h"

typedef struct {
    float m[4][4]; 
} Mat4x4;

Mat4x4* Mat4x4_Identity();
Mat4x4* Mat4x4_Zeros();
Mat4x4* Mat4x4_Ones();
Mat4x4* Mat4x4_Proj(float zn, float zf, float fov, float ratio);
Mat4x4* Mat4x4_RotX(float theta, float vel);
Mat4x4* Mat4x4_RotY(float theta, float vel);
Mat4x4* Mat4x4_RotZ(float theta, float vel);
void Mat4x4_print(Mat4x4* mat, char* name);

void MatMul(Vec3* vec, Mat4x4* mat, Vec3* res);
#endif
