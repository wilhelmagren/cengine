#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "matrices.h"

Mat4x4* Mat4x4_Identity() {
    Mat4x4* mat = (Mat4x4*)malloc(sizeof(Mat4x4));
    mat->m[0][0] = 1.0f;
    mat->m[1][1] = 1.0f;
    mat->m[2][2] = 1.0f;
    mat->m[3][3] = 1.0f;
    return mat;
}

Mat4x4* Mat4x4_Zeros() {
    Mat4x4* mat = (Mat4x4*)malloc(sizeof(Mat4x4));
    memset(mat->m, 0.0f, sizeof(mat->m));
    return mat;
};

Mat4x4* Mat4x4_Ones() {
    Mat4x4* mat = (Mat4x4*)malloc(sizeof(Mat4x4));
    memset(mat->m, 1.0f, sizeof(mat->m));
    return mat;
};

Mat4x4* Mat4x4_Proj(float zn, float zf, float fov, float ratio) {
    // Convert the fov from degrees to radians and calculate
    // scaling in z-direction based on zn & zf
    Mat4x4* proj = Mat4x4_Zeros();
    proj->m[0][0] = (float) ratio * 1.0f / tan(fov * 0.5f / 180.f * 3.141592f);
    proj->m[1][1] = (float) 1.0f / tan(fov * 0.5f / 180.f * 3.141592f);
    proj->m[2][2] = (float) zf / (zf-zn);
    proj->m[3][2] = (float) -zn*zf / (zf-zn);
    proj->m[2][3] = 1.0f;
    return proj;
}

Mat4x4* Mat4x4_RotX(float theta, float vel) {
    /*
     * Rotate a 3d vector around the x-axis, also called 'roll'
     * Based on the 3x3 matrix found at: https://en.wikipedia.org/wiki/Rotation_matrix
     * but modified to deal with our added bias to the position Vec3 vector.
     */
    Mat4x4* rot = Mat4x4_Identity();
    if (vel != 0.0f) {
        rot->m[1][1] = cos(theta * vel);
        rot->m[1][2] = -sin(theta * vel);
        rot->m[2][1] = sin(theta * vel);
        rot->m[2][2] = cos(theta * vel);
    }
    return rot;
}

Mat4x4* Mat4x4_RotY(float theta, float vel) {
    /*
     * Rotate a 3d vector around the y-axis, also called 'pitch'
     * See Mat4x4_RotX_new function for reference on linear algebra theory.
     */
    Mat4x4* rot = Mat4x4_Identity();
    if (vel != 0.0f) {
        rot->m[0][0] = cos(theta * vel);
        rot->m[0][2] = sin(theta * vel);
        rot->m[2][0] = -sin(theta * vel);
        rot->m[2][2] = cos(theta * vel);
    }
    return rot;
}

Mat4x4* Mat4x4_RotZ(float theta, float vel) {
    /*
     * Rotate a 3d vector around the z-axis, also called 'yaw'
     * See Mat4x4_RotX_new function for source on linear algebra theory.
     */
    Mat4x4* rot = Mat4x4_Identity();
    if (vel != 0.0f) {
        rot->m[0][0] = cos(theta * vel);
        rot->m[0][1] = -sin(theta * vel);
        rot->m[1][0] = sin(theta * vel);
        rot->m[1][1] = cos(theta * vel);
    }
    return rot;
}

void MatMul(Vec3* vec, Mat4x4* mat, Vec3* res) {
    float x = vec->x, y = vec->y, z = vec->z;
    res->x = x*mat->m[0][0] + y*mat->m[1][0] + z*mat->m[2][0] + mat->m[3][0];
    res->y = x*mat->m[0][1] + y*mat->m[1][1] + z*mat->m[2][1] + mat->m[3][1];
    res->z = x*mat->m[0][2] + y*mat->m[1][2] + z*mat->m[2][2] + mat->m[3][2];
    float w = x*mat->m[0][3] + y*mat->m[1][3] + z*mat->m[2][3] + mat->m[3][3];

    if (w != 0.0f) {
        res->x /= w;
        res->y /= w;
        res->z /= w;
    }
}

void Mat4x4_print(Mat4x4* mat, char* name) {
    char* string = "<struct %s at %p>\n";
    printf(string, name, mat);
    int i;
    for (i = 0; i < 4; i++) {
        char* values = "| %0.3f %0.3f %0.3f %0.3f |\n";
        printf(values,
                mat->m[i][0], mat->m[i][1],
                mat->m[i][2], mat->m[i][3]);
    }
}

