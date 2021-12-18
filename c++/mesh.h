#ifndef MESH_H
#define MESH_H
#include "polygon.h"

class Mesh {
    
    private:
        int idx;

    public:
        Polygon* polygons[1024];
        Mesh();
        void push(Polygon* poly);
        Polygon* pop();
};

#endif
