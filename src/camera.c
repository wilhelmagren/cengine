#include <stdlib.h>
#include "camera.h"

Camera* Camera_New(float x, float y, float z,
        int WINDOW_W, int WINDOW_H, float FOV, float CLIP_N, float CLIP_F) {
    Camera* cam = (Camera*)malloc(sizeof(Camera));
    cam->x = x; cam->y = y; cam->z = z;
    cam->RATIO = (float)WINDOW_H/(float)WINDOW_W;
    cam->WINDOW_W = WINDOW_W;
    cam->WINDOW_H = WINDOW_H;
    cam->FOV = FOV;
    cam->CLIP_N = CLIP_N;
    cam->CLIP_F = CLIP_F;
    return cam;
}

