#include "fuenteluz.h"

FuenteLuz::FuenteLuz(GLenum luz, bool type, _vertex3i color, _vertex4f posicion, _vertex4f difusa, _vertex4f especular, _vertex4f ambiental){
	light = luz;
	tipo = type;
	this->color = color;

	alfa = 0;
	beta = 0;
	this->posicion = posicion;
	this->difusa = difusa;
	this->especular = especular;
	this->ambiental = ambiental;
}


void FuenteLuz::Activate(){
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);		//  para como se calculan los angulos para la reflexion de la luz especular
	glEnable(GL_LIGHTING);
	glEnable(light);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glRotatef(alfa,0,1,0);		//alfa rota en  Y
	glRotatef(beta,1,0,0);		//beta rota en  X

	glLightfv(light,GL_POSITION,(GLfloat *) &posicion);
	glLightfv(light,GL_AMBIENT,(GLfloat *) &ambiental);
	glLightfv(light,GL_SPECULAR,(GLfloat *) &especular);
	glLightfv(light,GL_DIFFUSE,(GLfloat *) &difusa);
	glPopMatrix();
	glDisable(GL_LIGHTING);
}

void FuenteLuz::Deactivate(){
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glDisable(light);
    glPopMatrix();
}

void FuenteLuz::ChangeAlfa(){
	alfa+=10;
}

void FuenteLuz::ChangeBeta(){
	beta+=10;
}
