#include "O3D.h"

void O3D :: dibuja_ajedrez(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i< Triangles.size();i++){
        if(i%2)
           glColor3f(1,0,0);
        else
            glColor3f(0,0,0);

        glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
        glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
        glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
    }
    glEnd();
}


void O3D :: dibuja_solido() {
    glColor3f(1,0,0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glBegin(GL_TRIANGLES);
    for(int i = 0;i< Triangles.size();i++){
        glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
        glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
        glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
    }
    glEnd();
}

void O3D :: dibuja_alambre(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3f(1,0,1);

    glBegin(GL_TRIANGLES);
    for(int i=0;i< Triangles.size();i++){
        glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
        glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
        glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
    }
    glEnd();
}
