#include "regulador.h"

Regulador::Regulador(){}

void Regulador::dibuja(bool chess, bool vertice, bool arista, bool solid, float vel, float rot){
	float r = rot;
	float v = vel;		// Velocidad de giro.

	glPushMatrix();

	base.dibuja(chess,vertice,arista,solid,v);

	glPopMatrix();

	glPushMatrix();
	glRotatef(v,0,1,0);
	glTranslatef(0,17,0);

	esq.dibuja(chess,vertice,arista,solid, r);

	glPopMatrix();

}
