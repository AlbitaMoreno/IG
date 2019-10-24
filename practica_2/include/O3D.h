#ifndef _O3D_H_
#define _O3D_H_

#include "O3DS.h"

const double PI = 3.141516;

class O3D: public O3DS {
public:
	vector<_vertex3i> Triangles;
	O3D(){};
	void dibuja_alambre();
	void dibuja_solido();
	void dibuja_ajedrez();
};

#endif
