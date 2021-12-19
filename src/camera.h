#ifndef CAMERA_H
#define CAMERA_H

typedef struct {
    float x, y, z;
    uint8_t WINDOW_W, WINDOW_H;
    float FOV;
    float CLIP_N, CLIP_F;
} Camera;  

Camera* Camera(float x, float y, float z,
        uint8_t WINDOW_W, uint8_t WINDOW_H, float FOV, float CLIP_N, float CLIP_F);

#endif
