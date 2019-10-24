#include "tetraedro.h"


Tetraedro::Tetraedro(){
	Vertices.resize(4);

	Vertices[0]=_vertex3f(0,0.5,0);
	Vertices[1]=_vertex3f(-0.5,-0.5,-0.5);
	Vertices[2]=_vertex3f(0,-0.5,0.5);
	Vertices[3]=_vertex3f(0.5,-0.5,-0.5);


	Triangles.resize(4);
	//Tabla de Triangles
	Triangles[0]=_vertex3i(0,1,2);
	Triangles[1]=_vertex3i(0,2,3);
	Triangles[2]=_vertex3i(1,3,2);
	Triangles[3]=_vertex3i(0,3,1);
}
