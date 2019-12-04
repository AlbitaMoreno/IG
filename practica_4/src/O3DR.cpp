#include "O3DR.h"

O3DR::O3DR(){}

O3DR::O3DR(vector <_vertex3f> puntos_ply){
	this->Revolucionar(puntos_ply,50);
}

void O3DR::Revolucionar(vector <_vertex3f> perfil, int nlados){
	_vertex3f auxiliar,down,up;
	bool tapa_arriba = false, tapa_abajo = false;

	float alpha = 0;

	float alpha_aux = 2*PI/(float)nlados;


	if(perfil[0].x == 0 ){
		tapa_arriba = true;
		up = perfil[0];
		perfil.erase(perfil.begin());
	}

	if(perfil[perfil.size()-1].x == 0){
		tapa_abajo = true;
		down = perfil[perfil.size()-1];
		perfil.erase(perfil.end());			// Hacemos lo mismo con el vertice de la tapa de abajo.
	}


	Vertices.resize(nlados*perfil.size());

	for(int i = 0; i < nlados; i++){
		for(int j = 0; j < perfil.size();j++){

      		auxiliar.x =  perfil[j].x * cos(alpha);
      		auxiliar.z =  perfil[j].x * sin(alpha);
      		auxiliar.y  = perfil[j].y;
      		Vertices[(perfil.size()*i)+j] = auxiliar;
    	}
		alpha += alpha_aux;
  	}

  	if(tapa_arriba)
  		Vertices.push_back(up);
  	if(tapa_abajo)
  		Vertices.push_back(down);


	int punto=0;
	int max = nlados*perfil.size() ;
	for(int i = 0 ; i < nlados ; i++){
		for(int j=0 ; j < perfil.size()-1 ; j++){
			punto = (perfil.size()*i)+j;
			Triangles.push_back( _vertex3i( punto, ( punto+perfil.size()+1 )%max, (punto+perfil.size())%max ) );
			Triangles.push_back( _vertex3i( punto, punto+1, ( punto+perfil.size()+1 ) % max) );
	 	}
	}

// Triangulos de las tapas:
	if(tapa_abajo)
		for(int i = 0 ; i < nlados ; i++){
	 		Triangles.push_back(_vertex3i( (i+1)*(perfil.size())-1, Vertices.size()-1, ( ((i+1)*(perfil.size())-1)+perfil.size() )% max ));			// Triangulos de la cara de abajo.
		}

	if(tapa_abajo && tapa_arriba)
		for(int i = 0 ; i < nlados ; i++){
	 		Triangles.push_back(_vertex3i( Vertices.size()-2, i*perfil.size(), ( ((i+1)*(perfil.size()) )% max )) );								// Triangulos de la cara de arriba cuando tambien está presente la de abajo.
		}

	if(!tapa_abajo && tapa_arriba)
		for(int i = 0 ; i < nlados ; i++){
	 		Triangles.push_back(_vertex3i( Vertices.size()-1, i*perfil.size(), ( ((i+1)*(perfil.size()) )% max )) );								// Triangulos de la cara de arriba cuando no existe la de abajo.
		}


}
