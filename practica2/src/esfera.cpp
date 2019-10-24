#include "esfera.h"

Esfera::Esfera(){
	Vertices.resize(40);

	float angulo_b = 360.0/80.0;
    float angulo = (angulo_b*PI)/180;
    angulo_b = angulo;
    angulo = 0;
    float c1,c2;
    for(int i = 1; i < 42; i++){
    		c1 = cos(angulo)*0.5;
        c2 = sin(angulo)*0.5;
        Vertices.push_back(_vertex3f(c2,c1,0));
        angulo += angulo_b;
    }

    this->Revolucionar(Vertices,40);
}
