#include "cubo.h"


Cubo::Cubo(){
	Vertices.reserve(8);
// Vertices
	Vertices.push_back(_vertex3f(-0.5,-0.5, 0.5));  // V0
	Vertices.push_back(_vertex3f(0.5,-0.5,0.5));    // V1
	Vertices.push_back(_vertex3f(-0.5, 0.5, 0.5));  // V2
	Vertices.push_back(_vertex3f(0.5, 0.5, 0.5));   // V3


	Vertices.push_back(_vertex3f(-0.5,-0.5,-0.5));  // V4
	Vertices.push_back(_vertex3f(0.5,-0.5,-0.5));   // V5
	Vertices.push_back(_vertex3f(-0.5,0.5,-0.5));   // V6
	Vertices.push_back(_vertex3f(0.5,0.5, -0.5));   // V7


	// Caras
	Triangles.push_back(_vertex3i(0, 1, 2));
	Triangles.push_back(_vertex3i(1, 3, 2));

	Triangles.push_back(_vertex3i(1, 5, 3));
	Triangles.push_back(_vertex3i(5, 7, 3));

	Triangles.push_back(_vertex3i(5, 4, 7));
	Triangles.push_back(_vertex3i(4, 6, 7));

	Triangles.push_back(_vertex3i(4, 0, 6));
	Triangles.push_back(_vertex3i(0, 2, 6));

	Triangles.push_back(_vertex3i(2, 3, 6));
	Triangles.push_back(_vertex3i(3, 7, 6));

	Triangles.push_back(_vertex3i(4, 5, 0));
	Triangles.push_back(_vertex3i(5, 1, 0));


}
