#include "vaso_inv.h"

VasoInvertido::VasoInvertido(){
	Vertices.resize(3);
	Vertices[0] = _vertex3f(0, 0.5, 0);
	Vertices[1] = _vertex3f(0.25, 0.5, 0);
	Vertices[2] = _vertex3f(0.5, -0.5, 0);

	this->Revolucionar( Vertices, 10);
}
