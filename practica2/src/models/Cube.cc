#include "Cube.h"

#include <vector>
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>

Cube::Cube()
{

    // Vertices
    vertices.push_back(_vertex3f(-0.5, -0.5, 0.5)); // V0
    vertices.push_back(_vertex3f(0.5, -0.5, 0.5));  // V1
    vertices.push_back(_vertex3f(-0.5, 0.5, 0.5));  // V2
    vertices.push_back(_vertex3f(0.5, 0.5, 0.5));   // V3

    vertices.push_back(_vertex3f(-0.5, -0.5, -0.5)); // V4
    vertices.push_back(_vertex3f(0.5, -0.5, -0.5));  // V5
    vertices.push_back(_vertex3f(-0.5, 0.5, -0.5));  // V6
    vertices.push_back(_vertex3f(0.5, 0.5, -0.5));   // V7

    // Caras
    triangulos.push_back(_vertex3i(0, 1, 2));
    triangulos.push_back(_vertex3i(1, 3, 2));

    triangulos.push_back(_vertex3i(1, 5, 3));
    triangulos.push_back(_vertex3i(5, 7, 3));

    triangulos.push_back(_vertex3i(5, 4, 7));
    triangulos.push_back(_vertex3i(4, 6, 7));

    triangulos.push_back(_vertex3i(4, 0, 6));
    triangulos.push_back(_vertex3i(0, 2, 6));

    triangulos.push_back(_vertex3i(2, 3, 6));
    triangulos.push_back(_vertex3i(3, 7, 6));

    triangulos.push_back(_vertex3i(4, 5, 0));
    triangulos.push_back(_vertex3i(5, 1, 0));
}
