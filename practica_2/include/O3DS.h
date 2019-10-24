#include <iostream>
#include "vertex.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>

using namespace std;

class O3DS{
public:
	vector<_vertex3f> Vertices;
	O3DS(){};
	void dibuja_puntos();
};
