#include "cilindro.h"

Cilindro::Cilindro(){
	Vertices.resize(4);
	Vertices[0] = _vertex3f( 0, 0.5, 0 );
	Vertices[1] = _vertex3f( 0.5, 0.5, 0 );
	Vertices[2] = _vertex3f( 0.5, -0.5, 0 );
	Vertices[3] = _vertex3f( 0, -0.5, 0 );

	this->Revolucionar( Vertices, 10);
}
