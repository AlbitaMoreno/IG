#include "tetraedro.h"

Tetraedro :: Tetraedro()
{
    //h = sqrt(6)/3
    vertices.push_back(_vertex3f(0.0,0.43, 0.0));   //cúspide
    vertices.push_back(_vertex3f(0.5, -0.43,-0.37));
    vertices.push_back(_vertex3f(-0.5,-0.43,-0.37));
    vertices.push_back(_vertex3f(0.0,-0.43, 0.5));

    triangulos.push_back(_vertex3i(0,1,2));    //e0
    triangulos.push_back(_vertex3i(0,2,3));    //e1
    triangulos.push_back(_vertex3i(0,3,1));    //e2
    triangulos.push_back(_vertex3i(2,1,3));    //e4
}