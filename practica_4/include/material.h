#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "Textura.h"


class Material{
public:
	_vertex4f difusa;
	_vertex4f especular;
	_vertex4f ambiental;
	bool textura_asociada;
	GLfloat brillo;
	Textura *tex;

	Material(_vertex4f dif, _vertex4f esp, _vertex4f amb, GLfloat brightness, bool textura, char * archivo);
	Material(){};
	void activarMaterial();

};

#endif
