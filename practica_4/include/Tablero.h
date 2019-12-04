#ifndef _TABLERO_H_
#define _TABLERO_H_

#include "O3D.h"

class Tablero: public O3D{
public:
	int tam;				// El tablero será tamanio x tamanio cuadrados.

  Tablero(int m);
	void calcularCoordenadas();
	void dibuja_sombreado_plano();		   // normales de las caras
	void dibuja_sombreado_gouraud();		// normales de los vertices
	void dibuja2(bool chess, bool vertice, bool arista, bool solid, bool gourand, bool plano);
	void calcularCoordenadasTextura_Invertido();
	void calcularCoordenadasTextura_CuartaParte();
	void calcularCoordenadas_TexturaCentro();

};

#endif
