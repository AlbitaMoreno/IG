#ifndef _BASE_H_
#define _BASE_H_

#include "cubo.h"
#include "cilindro.h"

class Base{
private:
	Cubo cubo;
	Cilindro c;

public:
	Base();
	void dibuja(bool chess, bool vertice, bool arista, bool solid, float vel);
};

#endif
