#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void _MatrixMatrixMultiply(Mat4x4* a, Mat4x4* b, Mat4x4* res) {
    for (u8 i = 0; i < 4; i++) {
        for (u8 j = 0; j < 4; j++) {
            // ROW FROM a, COLUMN FROM B, calculate the dot prod
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

void CENGINE_DestroyMat4x4(Mat4x4* matrix) {
    free(matrix);
}

