#include "bloque_central.h"
#include "PlyReader.h"
BloqueCentral::BloqueCentral() {}

void BloqueCentral::dibuja(bool chess, bool vertice, bool arista, bool solid, float rot)
{
	float ini = 45;

	ini = ini + rot;

	glPushMatrix();

	b.dibuja(chess, vertice, arista, solid);

	glPopMatrix();
	PlyReader objeto_ply("beethoven.ply");

	glPushMatrix();

	glTranslatef(2, 0, 0);
	glRotatef(-ini, 0, 0, 1);
	glTranslatef(0, 4.5, 0);
	glScalef(0.8, 10, 0.8);

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

	glTranslatef(7.5, 1.75, 0);
	glRotatef(ini, 0, 0, 1);
	glTranslatef(0, 4, 0);
	glScalef(0.3, 0.3, 0.3);

	if (chess)
		objeto_ply.dibuja_ajedrez();
	if (vertice)
		objeto_ply.dibuja_puntos();
	if (arista)
		objeto_ply.dibuja_alambre();
	if (solid)
		objeto_ply.dibuja_solido();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-2, 0, 0);
	glRotatef(ini, 0, 0, 1);
	glTranslatef(0, 4.5, 0);
	glScalef(0.8, 10, 0.8);

	if (chess)
		c.dibuja_ajedrez();
	if (vertice)
		c.dibuja_puntos();
	if (arista)
		c.dibuja_alambre();
	if (solid)
		c.dibuja_solido();

	glPopMatrix();

	PlyReader objeto_ply2("beethoven.ply");
	glPushMatrix();

	glTranslatef(-7.5, 1.75, 0);
	glRotatef(-ini, 0, 0, 1);
	glTranslatef(0, 4, 0);
	glScalef(0.3, 0.3, 0.3);

	if (chess)
		objeto_ply2.dibuja_ajedrez();
	if (vertice)
		objeto_ply2.dibuja_puntos();
	if (arista)
		objeto_ply2.dibuja_alambre();
	if (solid)
		objeto_ply2.dibuja_solido();

	glPopMatrix();

	/*//CUATRO BRAZOS

	glPushMatrix();

	glRotatef(90,0,1,0);
	glRotatef(-ini,0,0,1);
	glTranslatef(0,5,0);
	glScalef(0.8,9,0.8);

	if(chess) c.dibuja_ajedrez();
	if(vertice) c.dibuja_puntos();
	if(arista) c.dibuja_alambre();
	if(solid) c.dibuja_solido();

	glPopMatrix();

	glPushMatrix();


	glRotatef(90,0,1,0);
	glRotatef(ini,0,0,1);
	glTranslatef(0,5,0);
	glScalef(0.8,9,0.8);

	if(chess) c.dibuja_ajedrez();
	if(vertice) c.dibuja_puntos();
	if(arista) c.dibuja_alambre();
	if(solid) c.dibuja_solido();

	glPopMatrix();
	*/
}
