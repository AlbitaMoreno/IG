#include "tubo.h"

Tubo::Tubo(){
	Vertices.resize(2);
	Vertices[0] = _vertex3f( 0.5, 0.5, 0 );
	Vertices[1] = _vertex3f( 0.5, -0.5, 0 );

	this->Revolucionar(Vertices,10);
}
