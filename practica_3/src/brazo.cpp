#include "brazo.h"

Brazo :: Brazo (){}

void Brazo :: dibuja(bool chess, bool vertice, bool arista, bool solid){

  glPushMatrix();

  glTranslatef(0,7.5,0);
	glScalef(1,15,1);

  if(chess) c2.dibuja_ajedrez();
  if(vertice) c2.dibuja_puntos();
  if(arista) c2.dibuja_alambre();
  if(solid) c2.dibuja_solido();

  glPopMatrix();

  glPushMatrix();

  glTranslatef(0,15,0);
  glScalef(4,4,4);

  if(chess) sphere.dibuja_ajedrez();
  if(vertice) sphere.dibuja_puntos();
  if(arista) sphere.dibuja_alambre();
  if(solid) sphere.dibuja_solido();


 /*// MODIFICACIÓN PARA QUE ESTÉ BEETHOVEN EN LUGAR DE LAS ESFERAS
    glTranslatef(0,15,0);
    glScalef(0.5,0.5,0.5);
    PlyReader objeto_ply("beethoven.ply");

    if(chess) objeto_ply.dibuja_ajedrez();
    if(vertice) objeto_ply.dibuja_puntos();
    if(arista) objeto_ply.dibuja_alambre();
    if(solid) objeto_ply.dibuja_solido();
*/
	glPopMatrix();


}
