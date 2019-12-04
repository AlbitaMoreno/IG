#include "block.h"

Block::Block(){}

void Block::dibuja(bool chess, bool vertice, bool arista, bool solid){
	glPushMatrix();

	glScalef(4,2,2);

	if(chess) centro.dibuja_ajedrez();
	if(vertice) centro.dibuja_puntos();
	if(arista) centro.dibuja_alambre();
	if(solid) centro.dibuja_solido();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-1.5, -6.5, 0);
	glScalef(0.7, 12, 0.7);

	if(chess) c.dibuja_ajedrez();
	if(vertice) c.dibuja_puntos();
	if(arista) c.dibuja_alambre();
	if(solid) c.dibuja_solido();

	glPopMatrix();
}
