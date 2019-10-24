#include "base.h"
#include <GL/glut.h>

Base::Base(){}

void Base::dibuja(bool chess, bool vertice, bool arista, bool solid, float vel){

	float velocidad = vel;

	glPushMatrix();

	glTranslatef(0,1,0);
	glScalef(18,2,18);

	if(chess) cubo.dibuja_ajedrez();
	if(vertice) cubo.dibuja_puntos();
	if(arista) cubo.dibuja_alambre();
	if(solid) cubo.dibuja_solido();


	glPopMatrix();

	glPushMatrix();

	glRotatef(vel,0,1,0);
	glTranslatef(0,17,0);		// En caso de que mida 30 -->(15 + 2).
	glScalef(1.25,30,1.25);

	if(chess) c.dibuja_ajedrez();
	if(vertice) c.dibuja_puntos();
	if(arista) c.dibuja_alambre();
	if(solid) c.dibuja_solido();

	glPopMatrix();
}
