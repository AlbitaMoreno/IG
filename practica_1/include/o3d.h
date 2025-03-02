#ifndef O3D_H
#define O3D_H

#include "vertex.h"
#include "o3ds.h"

class O3D : public O3DS {
protected:
    vector<_vertex3i> triangulos;
public:
    O3D();
    void dibuja_solido();
    void dibuja_alambre();
    void dibuja_ajedrez();
};

#endif // O3D_H