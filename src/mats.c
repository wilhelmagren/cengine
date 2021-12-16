#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mats.h"

Mat4x4* Mat4x4_new() {
    Mat4x4* mat = (Mat4x4*)malloc(sizeof(Mat4x4));
    float tmp[4][4] = {
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f}
    };
    memcpy(mat->m, tmp, sizeof(tmp));
    return mat;
}

void Mat4x4_print(Mat4x4* mat) {
    char* string = "<struct Mat4x4 at %p>\n";
    printf(string, mat);
    int i;
    for (i = 0; i < 4; i++) {
        char* values = "| %0.3f %0.3f %0.3f %0.3f |\n";
        printf(values,
                mat->m[i][0], mat->m[i][1],
                mat->m[i][2], mat->m[i][3]);
    }
}


MatProj* MatProj_new(float zn, float zf, float fov, float ratio) {
    // Convert the fov from degrees to radians and calculate
    // scaling in z-direction based on zn & zf
    float fov_rad = (float) 1.0f / tan(fov * .5f / 180.f * 3.141592f);
    float z_scale = (float) zf / (zf-zn);
    Mat4x4* mat = (Mat4x4*)malloc(sizeof(Mat4x4));
    MatProj* proj = (MatProj*)malloc(sizeof(MatProj));
    float x_scale = ratio*fov_rad;
    float tmp[4][4] = {
        {x_scale,  0.0f,        0.0f,  0.0f},
        {0.0f,  fov_rad,        0.0f,  0.0f},
        {0.0f,     0.0f,     z_scale,  1.0f},
        {0.0f,     0.0f, -zn*z_scale,  0.0f}
    };
    memcpy(mat->m, tmp, sizeof(tmp));
    proj->mat = mat;
    return proj;
}

void MatProj_print(MatProj* proj) {
    char* string = "<struct MatProj at %p>\n";
    printf(string, proj);
    int i;
    for (i = 0; i < 4; i++) {
        char* values = "| %0.3f %0.3f %0.3f %0.3f |\n";
        printf(values,
                proj->mat->m[i][0], proj->mat->m[i][1],
                proj->mat->m[i][2], proj->mat->m[i][3]);
    }
};

MatRotX* MatRotX_new(float theta) {
    Mat4x4* mat = (Mat4x4*)malloc(sizeof(Mat4x4));
    MatRotX* rot = (MatRotX*)malloc(sizeof(MatRotX));
    float tmp[4][4] = {
        {1.0f,               0.0f,              0.0f, 0.0f},
        {0.0f,  cos(theta * 0.5f), sin(theta * 0.5f), 0.0f},
        {0.0f, -sin(theta * 0.5f), cos(theta * 0.5f), 0.0f},
        {0.0f,               0.0f,              0.0f, 1.0f}
    };
    memcpy(mat->m, tmp, sizeof(tmp));
    rot->mat = mat;
    return rot;
}

MatRotZ* MatRotZ_new(float theta) {
    Mat4x4* mat = (Mat4x4*)malloc(sizeof(Mat4x4));
    MatRotZ* rot = (MatRotZ*)malloc(sizeof(MatRotZ));
    float tmp[4][4] = {
        { cos(theta), sin(theta), 0.0f, 0.0f},
        {-sin(theta), cos(theta), 0.0f, 0.0f},
        {       0.0f,       0.0f, 1.0f, 0.0f},
        {       0.0f,       0.0f, 0.0f, 1.0f}
    };
    memcpy(mat->m, tmp, sizeof(tmp));
    rot->mat = mat;
    return rot;
}

void MatMul(Vec3d* vec, Mat4x4* mat, Vec3d* res) {
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

