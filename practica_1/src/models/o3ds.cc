#include "o3ds.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>


O3DS::O3DS(){}


void O3DS :: dibuja_puntos(){
    glColor3f(1,0,0);
    glPointSize(4);
    glBegin(GL_POINTS);
        for (int i=0;i< vertices.size();i++){
            glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);
        }
    glEnd();
}