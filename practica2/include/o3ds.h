#ifndef O3DS_H
#define O3DS_H

#include <vector>
#include "vertex.h"

class O3DS{
public:
    vector<_vertex3f> vertices;
    O3DS();
    void dibuja_puntos();
};

#endif // O3DS_H