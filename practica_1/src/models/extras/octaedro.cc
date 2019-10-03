#include "octaedro.h"

Octaedro ::Octaedro()
{
    vertices.push_back(_vertex3f(-0.5, 0, -0.5)); //0
    vertices.push_back(_vertex3f(-0.5, 0, 0.5));  //1
    vertices.push_back(_vertex3f(0.5, 0, 0.5));   //2
    vertices.push_back(_vertex3f(0.5, 0, -0.5));  //3

    vertices.push_back(_vertex3f(0, 0.5, 0));  // punta 4
    vertices.push_back(_vertex3f(0, -0.5, 0)); // punta 5

    triangulos.push_back(_vertex3i(0, 1, 4));
    triangulos.push_back(_vertex3i(3, 0, 4));
    triangulos.push_back(_vertex3i(2, 3, 4));
    triangulos.push_back(_vertex3i(1, 2, 4));
    //Segunda mitad
    triangulos.push_back(_vertex3i(2, 1, 5));
    triangulos.push_back(_vertex3i(1, 0, 5));
    triangulos.push_back(_vertex3i(0, 3, 5));
    triangulos.push_back(_vertex3i(3, 2, 5));
}