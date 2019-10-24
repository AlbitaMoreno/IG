#ifndef _REVOLUCION_H_
#define _REVOLUCION_H_
#include "O3D.h"

class O3DR: public O3D{
public:
	O3DR();
	O3DR(vector <_vertex3f> puntos_ply);
	void Revolucionar(vector <_vertex3f> perfil, int nlados);
	void Examen(float angulo_inicio, float angulo_fin, vector <_vertex3f> perfil, int nlados);
};

#endif
