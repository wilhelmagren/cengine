#ifndef CAMERA_H
#define CAMERA_H

typedef struct {
    float x, y, z;
    int W;
    int H;
    float ratio;
    float fov;
    float zn;
    float zf;
} Camera;  

Camera* Camera_New(float x, float y, float z,
        int W, int H, float FOV, float zclip_near, float zclip_far);

#endif
