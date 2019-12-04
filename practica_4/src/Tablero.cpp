#include "Tablero.h"

Tablero::Tablero(int m){
	this->tam = m;
	int j;

  Vertices.resize( (m+1)*(m+1) );
	for(int i = 0; i < Vertices.size(); i++){
		j = (i/(m+1))*(m+1);
		Vertices[i].x = ((-m/2.0)+i)-j;
		Vertices[i].y = 0;		// Creo que va a ser el z el que tiene que ser 0.
		Vertices[i].z = (-m/2.0)+(i/(m+1));


	}

	Triangles.resize(m*m*2);
	int h = 0;
	int k = 0;
	for(int i = 0; i < m*m; i++){

		if( i%m == 0 && i != 0)
			h++;

		Triangles[k].x = h;
		Triangles[k].y = h+1;
		Triangles[k].z = h+m+1;

		k++;
		h++;

		Triangles[k].x = h;
		Triangles[k].y = h+m+1;
		Triangles[k].z = h+m;

		k++;
	}

	calcularCoordenadas();
	calcularNormales();

}

void Tablero::calcularCoordenadas(){
	coordenadas_textura.resize(Vertices.size());
	resetCoordenadas();

	for(int i = 0; i < Vertices.size(); i++){
		coordenadas_textura[i].x = (1.0/tam)*(i%(tam+1));
		coordenadas_textura[i].y = (1.0/tam)*(i/(tam+1));
		}
}

void Tablero::calcularCoordenadasTextura_Invertido(){
	coordenadas_textura.resize(Vertices.size());
	resetCoordenadas();

	for(int i = 0; i < Vertices.size(); i++){
		coordenadas_textura[Vertices.size()-(i+1)].x = (1.0/tam)*(i%(tam+1));
		coordenadas_textura[Vertices.size()-(i+1)].y = (1.0/tam)*(i/(tam+1));

		}
}

void Tablero::calcularCoordenadasTextura_CuartaParte(){
	int n_tam = tam/2;		// tam de la parte donde se va poner la textura
	coordenadas_textura.resize(Vertices.size());
	resetCoordenadas();
	int aux = tam - n_tam;
	int h = 0;

	for(int i = 0; i < (n_tam+1)*(n_tam+1); i++){

		if(i%(n_tam+1) == 0 && i !=0){
			h+=aux;
		}
		coordenadas_textura[h].x = (1.0/n_tam)*(i%(n_tam+1));
		coordenadas_textura[h].y = (1.0/n_tam)*(i/(n_tam+1));
		h++;
		}

}


void Tablero::calcularCoordenadas_TexturaCentro(){
	coordenadas_textura.resize(Vertices.size());
	resetCoordenadas();
	int centro;
	centro = ((tam+1)*(tam/2))+(tam/2);
	if(tam % 2 == 0){
		int n_centro = centro - (tam+2);
		coordenadas_textura[n_centro].x= 0;
		coordenadas_textura[n_centro].y= 0;

		coordenadas_textura[n_centro+1].x= 0.5;
		coordenadas_textura[n_centro+1].y= 0;

		coordenadas_textura[n_centro+2].x= 1;
		coordenadas_textura[n_centro+2].y= 0;

		coordenadas_textura[n_centro+tam+1].x=0;
		coordenadas_textura[n_centro+tam+1].y=0.5;

		coordenadas_textura[n_centro+tam+2].x=0.5;
		coordenadas_textura[n_centro+tam+2].y=0.5;

		coordenadas_textura[n_centro+tam+3].x=1;
		coordenadas_textura[n_centro+tam+3].y=0.5;

		coordenadas_textura[n_centro+((tam+1)*2)].x=0;
		coordenadas_textura[n_centro+((tam+1)*2)].y=1;

		coordenadas_textura[n_centro+((tam+1)*2)+1].x=0.5;
		coordenadas_textura[n_centro+((tam+1)*2)+1].y=1;

		coordenadas_textura[n_centro+((tam+1)*2)+2].x=1;
		coordenadas_textura[n_centro+((tam+1)*2)+2].y=1;
	}
	else{
		coordenadas_textura[centro].x = 0;
		coordenadas_textura[centro+1].x = 1;
		coordenadas_textura[centro+tam+1].x = 0;
		coordenadas_textura[centro+tam+2].x = 1;

		coordenadas_textura[centro].y = 0;
		coordenadas_textura[centro+1].y = 0;
		coordenadas_textura[centro+tam+1].y = 1;
		coordenadas_textura[centro+tam+2].y = 1;
	}

}


void Tablero::dibuja_sombreado_plano(){
	m.activarMaterial();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLES);

	glColor3f(1,0,0);    		// Rojo
	float vertice1, vertice2, vertice3;
	for(int i = 0; i < Triangles.size(); i++){
		vertice1 = Triangles[i].x;
		vertice2 = Triangles[i].y;
		vertice3 = Triangles[i].z;
		if(coordenadas_textura[vertice1].x != -1 && coordenadas_textura[vertice2].x != -1 && coordenadas_textura[vertice3].x != -1){
			//cout<<"introducimos vertices: "<<vertice1<<" "<<vertice2<<" "<<vertice3<<endl;
			glNormal3fv((GLfloat*) & normales_caras[i]);
			glTexCoord2f(coordenadas_textura[vertice1].x,coordenadas_textura[vertice1].y);
			glVertex3fv((GLfloat*) & Vertices[vertice1]);
			glTexCoord2f(coordenadas_textura[vertice2].x,coordenadas_textura[vertice2].y);
			glVertex3fv((GLfloat*) & Vertices[vertice2]);
			glTexCoord2f(coordenadas_textura[vertice3].x,coordenadas_textura[vertice3].y);
			glVertex3fv((GLfloat*) & Vertices[vertice3]);
		}
		else{
			glNormal3fv((GLfloat*) & normales_caras[i]);
			glTexCoord2f(-1,-1);
			glVertex3fv((GLfloat*) & Vertices[vertice1]);
			glTexCoord2f(-1,-1);
			glVertex3fv((GLfloat*) & Vertices[vertice2]);
			glTexCoord2f(-1,-1);
			glVertex3fv((GLfloat*) & Vertices[vertice3]);
		}


	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Tablero::dibuja_sombreado_gouraud(){
	m.activarMaterial();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);

	glColor3f(1,0,0);    		// Rojo
	float vertice1, vertice2, vertice3;
	for(int i = 0; i < Triangles.size(); i++){
		vertice1 = Triangles[i].x;
		vertice2 = Triangles[i].y;
		vertice3 = Triangles[i].z;
		if(coordenadas_textura[vertice1].x != -1 && coordenadas_textura[vertice2].x != -1 && coordenadas_textura[vertice3].x != -1){
			glTexCoord2f(coordenadas_textura[vertice1].x,coordenadas_textura[vertice1].y);
			glNormal3fv((GLfloat*) & normales_vertices[vertice1]);
			glVertex3fv((GLfloat*) & Vertices[vertice1]);

			glTexCoord2f(coordenadas_textura[vertice2].x,coordenadas_textura[vertice2].y);
			glNormal3fv((GLfloat*) & normales_vertices[vertice2]);
			glVertex3fv((GLfloat*) & Vertices[vertice2]);

			glTexCoord2f(coordenadas_textura[vertice3].x,coordenadas_textura[vertice3].y);
			glNormal3fv((GLfloat*) & normales_vertices[vertice3]);
			glVertex3fv((GLfloat*) & Vertices[vertice3]);
		}
		else{
			glTexCoord2f(-1,-1);
			glNormal3fv((GLfloat*) & normales_vertices[vertice1]);
			glVertex3fv((GLfloat*) & Vertices[vertice1]);

			glTexCoord2f(-1,-1);
			glNormal3fv((GLfloat*) & normales_vertices[vertice2]);
			glVertex3fv((GLfloat*) & Vertices[vertice2]);

			glTexCoord2f(-1,-1);
			glNormal3fv((GLfloat*) & normales_vertices[vertice3]);
			glVertex3fv((GLfloat*) & Vertices[vertice3]);
		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Tablero::dibuja2(bool chess, bool vertice, bool arista, bool solid, bool gourand, bool plano){
	if(chess) this->dibuja_ajedrez();
	if(vertice) this->dibuja_puntos();
	if(arista) this->dibuja_alambre();
	if(solid) this->dibuja_solido();
	if(gourand) this->dibuja_sombreado_gouraud();
	if(plano) this->dibuja_sombreado_plano();
}
