#ifndef BLOQUE_CENTRAL_
#define BLOQUE_CENTRAL_

#include "block.h"
#include "cilindro.h"

class BloqueCentral{
private:
	Cilindro c;
	Block b;
public:
	BloqueCentral();
	void dibuja(bool chess, bool vertice, bool arista, bool solid, float rot);
};

#endif
