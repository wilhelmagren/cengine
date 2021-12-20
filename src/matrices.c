#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
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

Mat4x4* CENGINE_ProjectionMatrix(Camera* camera) {
    float ratio = camera->ratio;
    float fov = camera->fov;
    float zn = camera->zn;
    float zf = camera->zf;
    Mat4x4* proj = Mat4x4_Zeros();
    proj->m[0][0] = ratio * 1.0f / tan(fov * 0.5f / 180.f * 3.141592f);
    proj->m[1][1] = 1.0f / tan(fov * 0.5f / 180.f * 3.141592f);
    proj->m[2][2] = zf / (zf-zn);
    proj->m[3][2] = -zn*zf / (zf-zn);
    proj->m[2][3] = 1.0f;

    return proj;
}

Mat4x4* CENGINE_RotationMatrix_X(float theta, float vel) {
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

Mat4x4* CENGINE_RotationMatrix_Y(float theta, float vel) {
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

Mat4x4* CENGINE_RotationMatrix_Z(float theta, float vel) {
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

void CENGINE_MatrixMultiply(Vec3* vec, Mat4x4* mat, Vec3* res) {
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

void _RotatePolygon(Polygon* pol, uint8_t axis) {
    Mat4x4* rot;
    if (axis == 0) {
        rot = CENGINE_RotationMatrix_X(pol->angle, pol->vx);
    } else if (axis == 1) {
        rot = CENGINE_RotationMatrix_Y(pol->angle, pol->vy);
    } else if (axis == 2) {
        rot = CENGINE_RotationMatrix_Z(pol->angle, pol->vz);
    } else {
        fprintf(stderr, "Unknown axis alignment %d in _RotatePolygon, skipping rotate...", axis);
    }
    CENGINE_MatrixMultiply(pol->vecs[0], rot, pol->vecs[0]);
    CENGINE_MatrixMultiply(pol->vecs[1], rot, pol->vecs[1]);
    CENGINE_MatrixMultiply(pol->vecs[2], rot, pol->vecs[2]);
    free(rot);
}

void CENGINE_RotatePolygons(Mesh* mesh) {
    uint8_t i;
    for (i = 0; i < mesh->pidx; i++) {
        _RotatePolygon(mesh->polygons[i], 0);
        _RotatePolygon(mesh->polygons[i], 1);
        _RotatePolygon(mesh->polygons[i], 2);
    }
}

void CENGINE_ProjectPolygons(Camera* camera, Mesh* mesh) {
    uint8_t i;
    Mat4x4* proj = CENGINE_ProjectionMatrix(camera);
    for (i = 0; i < mesh->pidx; i++) {
        Polygon* polygon = mesh->polygons[i];
        CENGINE_MatrixMultiply(polygon->vecs[0], proj, polygon->vecs[0]);
        CENGINE_MatrixMultiply(polygon->vecs[1], proj, polygon->vecs[1]);
        CENGINE_MatrixMultiply(polygon->vecs[2], proj, polygon->vecs[2]);
    }
    free(proj);
}

void CENGINE_ScalePolygons(Camera* camera, Mesh* mesh) {
    uint8_t i;
    for (i= 0; i < mesh->pidx; i++) {
        mesh->polygons[i]->vecs[0]->x += 1.0f;
        mesh->polygons[i]->vecs[0]->y += 1.0f;
        mesh->polygons[i]->vecs[0]->z += 1.0f;
        mesh->polygons[i]->vecs[1]->x += 1.0f;
        mesh->polygons[i]->vecs[1]->y += 1.0f;
        mesh->polygons[i]->vecs[1]->z += 1.0f;
        mesh->polygons[i]->vecs[2]->x += 1.0f;
        mesh->polygons[i]->vecs[2]->y += 1.0f;
        mesh->polygons[i]->vecs[2]->z += 1.0f;

        mesh->polygons[i]->vecs[0]->x *= 0.5f * (float)camera->W;
        mesh->polygons[i]->vecs[0]->y *= 0.5f * (float)camera->H;
        mesh->polygons[i]->vecs[0]->z *= 0.5f * (float)camera->H;
        mesh->polygons[i]->vecs[1]->x *= 0.5f * (float)camera->W;
        mesh->polygons[i]->vecs[1]->y *= 0.5f * (float)camera->H;
        mesh->polygons[i]->vecs[1]->z *= 0.5f * (float)camera->H;
        mesh->polygons[i]->vecs[2]->x *= 0.5f * (float)camera->W;
        mesh->polygons[i]->vecs[2]->y *= 0.5f * (float)camera->H;
        mesh->polygons[i]->vecs[2]->z *= 0.5f * (float)camera->H;
    }
}

