#include "parte_arriba.h"
#include "PlyReader.h"
ParteArriba ::ParteArriba() {}

void ParteArriba ::dibuja(bool chess, bool vertice, bool arista, bool solid, float rot)
{
	float ini = 145;
	ini = ini + rot;

	glPushMatrix();

	glScalef(5, 3, 3);
	if (chess)
		c.dibuja_ajedrez();
	if (vertice)
		c.dibuja_puntos();
	if (arista)
		c.dibuja_alambre();
	if (solid)
		c.dibuja_solido();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(2.0, 0, 0);
	glRotatef(-ini, 0, 0, 1);

	b.dibuja(chess, vertice, arista, solid);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-2.0, 0, 0);
	glRotatef(ini, 0, 0, 1);

	b.dibuja(chess, vertice, arista, solid);

	glPopMatrix();
	
	glPushMatrix();

	glRotatef(90, 0, 1, 0);
	glRotatef(-ini, 0, 0, 1);

	b.dibuja(chess, vertice, arista, solid);

	glPopMatrix();

	glPushMatrix();

	glRotatef(90, 0, 1, 0);
	glRotatef(ini, 0, 0, 1);

	b.dibuja(chess, vertice, arista, solid);

	glPopMatrix();
}
