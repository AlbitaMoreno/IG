#ifndef BRAZO_H
#define BRAZO_H

#include "cilindro.h"
#include "esfera.h"
#include "PlyReader.h"

class Brazo{
private:
  Cilindro c2;
  Esfera sphere;
  //PlyReader objeto_ply("beethoven.ply");
public:
  Brazo();
  void dibuja(bool chess, bool vertice, bool arista, bool solid);
};
#endif
