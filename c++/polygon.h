#ifndef POLYGON_H
#define POLYGON_H
#include "vec3.h"

class Polygon {
    
    public:
        Vec3* vecs[3];
        Polygon(Vec3* a, Vec3* b, Vec3* c);
};

#endif
