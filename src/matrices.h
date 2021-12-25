#ifndef MATRICES_H
#define MATRICES_H
#include <stdbool.h>
#include "utils.h"
#include "vec3.h"

typedef struct {
    f4 items[4][4];
} Mat4x4;

Mat4x4* Mat4x4_Zeros();
Mat4x4* Mat4x4_Ones();
Mat4x4* Mat4x4_Identity();
Mat4x4* Mat4x4_Create(f4 items[4][4]);
Mat4x4* Mat4x4_RotationX(f4 angle);
Mat4x4* Mat4x4_RotationY(f4 angle);
Mat4x4* Mat4x4_RotationZ(f4 angle);
Mat4x4* Mat4x4_Projection(f4 near, f4 far, f4 fov, f4 ratio);
Mat4x4* Mat4x4_Translation(f4 x, f4 y, f4 z);

void _MatrixVecMultiply(Vec3* vec, Mat4x4* matrix, Vec3* res);
void _MatrixMatrixMultiply(Mat4x4* a, Mat4x4* b, Mat4x4* res);
void _MatrixPrint(Mat4x4* matrix, bool show_matrix);

bool _MatrixAllEqual(Mat4x4* matrix, f4 value);
bool _MatrixEqualMatrix(Mat4x4* a, Mat4x4* b);

void CENGINE_DestroyMat4x4(Mat4x4* matrix);

#endif
