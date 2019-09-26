#include "o3d.h"

#include <vector>

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>

O3D::O3D() {}

void O3D ::dibuja_ajedrez()
{
    glPolygonMode(GL_FRONT, GL_FILL);

    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < triangulos.size(); i++)
    {
        if (i % 2)
            glColor3f(0.75, 0.5, 0);
        else
            glColor3f(0, 0.5, 0.75);

        glVertex3f(vertices[triangulos[i]._0].x, vertices[triangulos[i]._0].y, vertices[triangulos[i]._0].z);
        glVertex3f(vertices[triangulos[i]._1].x, vertices[triangulos[i]._1].y, vertices[triangulos[i]._1].z);
        glVertex3f(vertices[triangulos[i]._2].x, vertices[triangulos[i]._2].y, vertices[triangulos[i]._2].z);
    }
    glEnd();
}

void O3D ::dibuja_solido()
{
    glColor3f(0.5, 0.5, 1);
    glPolygonMode(GL_FRONT, GL_FILL);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < triangulos.size(); i++)
    {
        glVertex3f(vertices[triangulos[i]._0].x, vertices[triangulos[i]._0].y, vertices[triangulos[i]._0].z);
        glVertex3f(vertices[triangulos[i]._1].x, vertices[triangulos[i]._1].y, vertices[triangulos[i]._1].z);
        glVertex3f(vertices[triangulos[i]._2].x, vertices[triangulos[i]._2].y, vertices[triangulos[i]._2].z);
    }
    glEnd();
}

void O3D ::dibuja_alambre()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1, 0, 1);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < triangulos.size(); i++)
    {
        glVertex3f(vertices[triangulos[i]._0].x, vertices[triangulos[i]._0].y, vertices[triangulos[i]._0].z);
        glVertex3f(vertices[triangulos[i]._1].x, vertices[triangulos[i]._1].y, vertices[triangulos[i]._1].z);
        glVertex3f(vertices[triangulos[i]._2].x, vertices[triangulos[i]._2].y, vertices[triangulos[i]._2].z);
    }
    glEnd();
}
