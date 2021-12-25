#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "matrices.h"

Mat4x4* Mat4x4_Zeros() {
    Mat4x4* matrix = (Mat4x4*)malloc(sizeof(Mat4x4));
    for (u8 i = 0; i < 4; i++) {
        for (u8 j = 0; j < 4; j++) { matrix->items[i][j] = (f4) 0.0; }
    }
    return matrix;
}

Mat4x4* Mat4x4_Ones() {
    Mat4x4* matrix = (Mat4x4*)malloc(sizeof(Mat4x4));
    for (u8 i = 0; i < 4; i++) {
        for (u8 j = 0; j < 4; j++) { matrix->items[i][j] = (f4) 1.0; }
    }
    return matrix;
}

Mat4x4* Mat4x4_Identity() {
    Mat4x4* matrix = (Mat4x4*)malloc(sizeof(Mat4x4));
    memset(matrix->items, (f4) 0.0, sizeof(matrix->items));
    for (u8 i = 0; i < 4; i++) { matrix->items[i][i] = (f4) 1.0; }

    return matrix;
}

Mat4x4* Mat4x4_Create(f4 items[4][4]) {
    Mat4x4* matrix = (Mat4x4*)malloc(sizeof(Mat4x4));
    memcpy(matrix->items, items, 16*sizeof(f4));
    return matrix;
}

Mat4x4* Mat4x4_RotationX(f4 angle) {
    Mat4x4* rot = Mat4x4_Identity();
    if (angle != 0.0) {
        rot->items[1][1] =  cos(angle);
        rot->items[1][2] = -sin(angle);
        rot->items[2][1] =  sin(angle);
        rot->items[2][2] =  cos(angle);
    }
    return rot;
}

Mat4x4* Mat4x4_RotationY(f4 angle) {
    Mat4x4* rot = Mat4x4_Identity();
    rot->items[0][0] =  cos(angle);
    rot->items[0][2] =  sin(angle);
    rot->items[2][0] = -sin(angle);
    rot->items[2][2] =  cos(angle);
    return rot;
}

Mat4x4* Mat4x4_RotationZ(f4 angle) {
    Mat4x4* rot = Mat4x4_Identity();
    rot->items[0][0] =  cos(angle);
    rot->items[0][1] = -sin(angle);
    rot->items[1][0] =  sin(angle);
    rot->items[1][1] =  cos(angle);
    return rot;
}

Mat4x4* Mat4x4_Projection(f4 near, f4 far, f4 fov, f4 ratio) {
    Mat4x4* matrix = Mat4x4_Zeros();
    f4 rfov = (f4) 1.0 / tan(fov * 0.5 / (180.0 * 3.141592));
    f4 zdiv = (f4) far / (far - near);
    matrix->items[0][0] = ratio*rfov;
    matrix->items[1][1] = rfov;
    matrix->items[2][2] = zdiv;
    matrix->items[3][2] = -near * zdiv;
    matrix->items[2][3] = (f4) 1.0;

    return matrix;
}

void _MatrixVecMultiply(Vec3* vec, Mat4x4* matrix, Vec3* res) {
    f4 x = vec->x, y = vec->y, z = vec->z, w = vec->w;
    res->x = x*matrix->items[0][0] + y*matrix->items[1][0] + z*matrix->items[2][0] + w*matrix->items[3][0];
    res->y = x*matrix->items[0][1] + y*matrix->items[1][1] + z*matrix->items[2][1] + w*matrix->items[3][1];
    res->z = x*matrix->items[0][2] + y*matrix->items[1][2] + z*matrix->items[2][2] + w*matrix->items[3][2];
    res->w = x*matrix->items[0][3] + y*matrix->items[1][3] + z*matrix->items[2][3] + w*matrix->items[3][3];
}

void _MatrixMatrixMultiply(Mat4x4* a, Mat4x4* b, Mat4x4* res) {
    for (u8 i = 0; i < 4; i++) {
        for (u8 j = 0; j < 4; j++) {
            for (u8 k = 0; k < 4; k++) {
                res->items[i][j] += a->items[i][k] * b->items[k][j];
            }
        }
    }
}

void _MatrixPrint(Mat4x4* matrix, bool show_matrix) {
    fprintf(stdout, "<struct Mat4x4 at %p>\n", matrix);
    if (show_matrix) {
        for (u8 i = 0; i < 4; i++) {
            fprintf(stdout, " %0.3f %0.3f %0.3f %0.3f\n",
                    matrix->items[i][0],matrix->items[i][1],
                    matrix->items[i][2],matrix->items[i][3]);
        }
    }
}

bool _MatrixAllEqual(Mat4x4* matrix, f4 value) {
    for (u8 i = 0; i < 4; i++) {
        for (u8 j = 0; j < 4; j++) { if (!_f4Equality(matrix->items[i][j], value)) return false; }
    }
    return true;
}

bool _MatrixEqualMatrix(Mat4x4* a, Mat4x4* b) {
    for (u8 i = 0; i < 4; i++) {
        for (u8 j = 0; j < 4; j++) { if (!_f4Equality(a->items[i][j], b->items[i][j])) return false; }
    }
    return true;
}
