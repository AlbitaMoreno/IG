#include "piramide.h"

Piramide ::Piramide()
{
    vertices.push_back(_vertex3f(-0.5, -0.5, -0.5)); //1
    vertices.push_back(_vertex3f(-0.5, -0.5, 0.5));  //2
    vertices.push_back(_vertex3f(0.5, -0.5, 0.5));   //3
    vertices.push_back(_vertex3f(0.5, -0.5, -0.5));  //

    vertices.push_back(_vertex3f(0, 0.5, 0)); // punta de la piramid

    triangulos.push_back(_vertex3i(1, 3, 0));
    triangulos.push_back(_vertex3i(1, 2, 3));
    triangulos.push_back(_vertex3i(0, 1, 4));
    triangulos.push_back(_vertex3i(3, 0, 4));
    triangulos.push_back(_vertex3i(2, 3, 4));
    triangulos.push_back(_vertex3i(1, 2, 4));
}
