#ifndef BLOCK_H
#define BLOCK_H

#include "cubo.h"
#include "cilindro.h"
#include "base.h"

class Block{
private:
	Cilindro centro;
	Cilindro c;
	Base base;
public:
	Block();
	void dibuja(bool chess, bool vertice, bool arista, bool solid);
};

#endif
