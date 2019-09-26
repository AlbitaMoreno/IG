#ifndef O3DS_H
#define O3DS_H

#include <vector>
#include "vertex.h"

class O3DS{
protected:
protected:
    vector<_vertex3f> vertices;
public:
    O3DS();
    void dibuja_puntos();
};

#endif // O3DS_H