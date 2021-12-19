#ifndef CAMERA_H
#define CAMERA_H

typedef struct {
    float x, y, z;
    int WINDOW_W;
    int WINDOW_H;
    float RATIO;
    float FOV;
    float CLIP_N, CLIP_F;
} Camera;  

Camera* Camera_New(float x, float y, float z,
        int WINDOW_W, int WINDOW_H, float FOV, float CLIP_N, float CLIP_F);

#endif
