#include "O3DS.h"


void O3DS::dibuja_puntos(){
	glBegin(GL_POINTS);
	glColor3f(0,1,0);		// Puntos en verde
	for(int i = 0; i < Vertices.size(); i++){
		glVertex3f(Vertices[i].x, Vertices[i].y, Vertices[i].z);
	}
	glEnd();

	}
