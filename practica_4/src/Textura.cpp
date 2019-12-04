#include "Textura.h"

Textura::Textura(char *archivo, bool autom){
	mi_img = new jpg::Imagen(archivo);
	this->autom = autom;
	ncol = mi_img->tamX();
	nfil = mi_img->tamY();
	pxls = mi_img->leerPixels();
}

void Textura::activarTextura(){
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,0);
    if(autom) {
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
        glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
    } else {
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    }

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexImage2D(GL_TEXTURE_2D,0, GL_RGB, ncol, nfil, 0, GL_RGB, GL_UNSIGNED_BYTE, pxls);
}
