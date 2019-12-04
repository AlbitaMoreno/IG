#ifndef _O3D_H_
#define _O3D_H_

#include <unistd.h>
#include "material.h"
#include "O3DS.h"

const double PI = 3.141516;

class O3D: public O3DS {
public:
	vector<_vertex3i> Triangles;

	vector <_vertex3f> normales_caras;
	vector <_vertex3f> normales_vertices;
	vector <_vertex2f> coordenadas_textura;		// Hacer coordenadas_textura.resize(Vertices.size())
																						//esto corresponde a la parte 4.2.2.
	Material m;

	O3D(){};
	void dibuja_alambre();
	void dibuja_solido();
	void dibuja_ajedrez();

	void calcularNormales();						//normales de las caras y de los vertices.
	void dibuja_sombreado_plano();			//  Normales de las caras
	void dibuja_sombreado_gouraud();		// Normales de los vertices
	void elegirMaterial(Material mt);

	void resetCoordenadas();
};

#endif
