#include <stdlib.h>
#include "camera.h"

Camera* Camera_New(float x, float y, float z,
        int W, int H, float fov, float zn, float zf) {
    Camera* camera = (Camera*)malloc(sizeof(Camera));
    camera->x = x; camera->y = y; camera->z = z;
    camera->ratio = (float)H/(float)W;
    camera->W = W;
    camera->H = H;
    camera->fov = fov;
    camera->zn = zn;
    camera->zf = zf;
    return camera;
}

