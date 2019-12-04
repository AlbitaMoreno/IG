#ifndef PARTE_ARRIBA_H
#define PARTE_ARRIBA_H

#include "cubo.h"
#include "brazo.h"

class ParteArriba{
private:
  Brazo b;
  Cubo c;

public:
  ParteArriba();
  void dibuja(bool chess, bool vertice, bool arista, bool solid, float rot);
};
#endif
