#include "esqueleto.h"

Esqueleto::Esqueleto(){}

void Esqueleto::dibuja(bool chess, bool vertice, bool arista, bool solid, float rot){
	float r = rot;	 // rotacion bloque_central
	if(r > 32)
		r = 32;
	if(r < 0)
		r = 0;
	float r2 = -(r*1.5);			 // rotacion parte de arriba

	float alt;		// lo que subira el bloque dependiendo de la posicion de sus brazos.
	alt = rot*0.40;

	if(alt > 12){
		alt = 12;
	}
	if(alt < 0)
		alt = 0;

	glPushMatrix();

	glTranslatef(0,alt,0);
	m.dibuja(chess,vertice,arista,solid,r);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,16,0);
	a.dibuja(chess,vertice,arista,solid,r2);

	glPopMatrix();

}
