#include <stdlib.h>
#include "camera.h"

Camera* Camera_Constructor(f4 x, f4 y, f4 z) {
    Camera* camera = (Camera*)malloc(sizeof(Camera));
    camera->position = Vec3_Constructor(x, y, z, 1.0);

    return camera;
}
