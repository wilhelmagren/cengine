#ifndef MATS_H
#define MATS_H
#include "vecs.h"

typedef struct {
    float m[4][4]; 
} Mat4x4;

Mat4x4* Mat4x4_new();
void Mat4x4_print(Mat4x4* mat);


typedef struct {
    Mat4x4* mat;
} MatProj;

MatProj* MatProj_new(float zn, float zf, float fov, float ratio);
void MatProj_print(MatProj* proj);


typedef struct {
    Mat4x4* mat;
} MatRotX;

typedef struct {
    Mat4x4* mat;
} MatRotZ;

MatRotX* MatRotX_new(float theta);
MatRotZ* MatRotZ_new(float theta);


void MatMul(Vec3d* vec, Mat4x4* mat, Vec3d* res);
#endif
