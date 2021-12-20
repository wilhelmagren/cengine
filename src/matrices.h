#ifndef MATRICES_H
#define MATRICES_H
#include <stdint.h>
#include "vecs.h"
#include "mesh.h"
#include "camera.h"

typedef struct {
    float m[4][4]; 
} Mat4x4;

Mat4x4* Mat4x4_Identity();
Mat4x4* Mat4x4_Zeros();
Mat4x4* Mat4x4_Ones();
Mat4x4* CENGINE_ProjectionMatrix(Camera* camera);
Mat4x4* CENGINE_RotationMatrix_X(float theta, float vel);
Mat4x4* CENGINE_RotationMatrix_Y(float theta, float vel);
Mat4x4* CENGINE_RotationMatrix_Z(float theta, float vel);
void CENGINE_MultiplyMatrix(Vec3* vec, Mat4x4* mat, Vec3* res);
void _RotatePolygon(Polygon* pol, uint8_t axis);
void CEGINE_RotatePolygons(Mesh* mesh);
void CENGINE_ScalePolygons(Camera* camera, Mesh* mesh);

#endif
