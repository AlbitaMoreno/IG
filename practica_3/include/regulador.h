#ifndef REGULADOR_H
#define REGULADOR_H

#include "base.h"
#include "esqueleto.h"

class Regulador{
private:
	Base base;
	Esqueleto esq;

public:
	Regulador();
	void dibuja(bool chess, bool vertice, bool arista, bool solid, float vel, float rot);
};

#endif
