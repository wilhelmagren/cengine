#ifndef CAMERA_H
#define CAMERA_H
#include "vec3.h"
#include "utils.h"

typedef struct {
    Vec3* position;
    f4 rotX, f4 rotY;
} Camera;

Camera* Camera_Constructor(f4 x, f4 y, f4 z);

#endif
