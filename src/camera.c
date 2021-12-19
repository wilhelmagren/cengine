#include "camera.h"

Camera* Camera(float x, float y, float z,
        uint8_t WINDOW_W, uint8_t WINDOW_H, float FOV, float CLIP_N, float CLIP_F) {
    Camera* cam = (Camera*)malloc(sizeof(Camera));
    cam->x = x;
    cam->y = y;
    cam->z = z;
    cam->RATIO = (float)WINDOW_W/(float)WINDOW_H;
    cam->WINDOW_W = WINDOW_W;
    cam->WINDOW_H = WINDOW_H
    cam->FOV = FOV;
    cam->CLIP_N = CLIP_N;
    cam->CLIP_F = CLIP_F;
    return cam;
}
