#ifndef _TEXTURA_H_
#define _TEXTURA_H_

#include "jpg_imagen.hpp"
#include "jpg_jinclude.h"
#include <iostream>
#include "vertex.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>

using namespace std;

class Textura{
public:
	jpg::Imagen *mi_img = NULL;
	int ncol;
	int nfil;
	unsigned char * pxls;
	bool autom;
	int id_tex;

	Textura(char *archivo, bool autom);
	void activarTextura();

};

#endif
