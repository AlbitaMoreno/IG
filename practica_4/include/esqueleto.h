#ifndef ESQUELETO_
#define ESQUELETO_

#include "bloque_central.h"
#include "parte_arriba.h"

class Esqueleto{
private:
	BloqueCentral m;
	ParteArriba a;


public:
	Esqueleto();
	void dibuja(bool chess, bool vertice, bool arista, bool solid, float rotacion);
};

#endif
