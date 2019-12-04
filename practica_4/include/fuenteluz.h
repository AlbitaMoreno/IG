#ifndef FUENTE_LUZ_
#define FUENTE_LUZ_


#include <iostream>
#include "vertex.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>

using namespace std;

class FuenteLuz{
public:
	GLenum light;
	bool tipo;			// true si direccional y false si posicional
	_vertex3i color;
	float alfa;
	float beta;
	_vertex4f posicion;
	_vertex4f difusa;
	_vertex4f especular;
	_vertex4f ambiental;


	FuenteLuz(GLenum luz, bool type, _vertex3i color, _vertex4f posicion, _vertex4f difusa, _vertex4f especular, _vertex4f ambiental);
	void Activate();
	void Deactivate();
	void ChangeAlfa();
	void ChangeBeta();

};

#endif
