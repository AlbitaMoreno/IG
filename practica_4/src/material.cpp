#include "material.h"

Material::Material(_vertex4f dif, _vertex4f esp, _vertex4f amb, GLfloat brightness, bool textura, char * archivo){
	difusa = dif;
	especular = esp;
	ambiental = amb;
	textura_asociada = textura;
	brillo = brightness;
	if(textura_asociada)
		tex = new Textura(archivo, false);
	else
		tex = NULL;
}

void Material::activarMaterial(){
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) & ambiental);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) & difusa);
    glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) & especular);
    glMaterialf(GL_FRONT,GL_SHININESS,brillo);
    if(textura_asociada) {
        tex->activarTextura();
    } else {
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}
