TARGETS= bin/practica2

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I.
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut


# Orden por defecto

default : $(TARGETS)


# Programa principal

$(TARGETS) : obj/practica2.o lib/libFiguras.a
	g++ -o $@ $(CXXFLAGS) obj/practica2.o -lFiguras $(LDFLAGS) -Llib

obj/practica2.o: src/practica2.cpp include/vertex.h include/O3DS.h include/O3D.h include/cubo.h include/tetraedro.h  include/PlyReader.h include/file_ply_stl.h include/O3DR.h include/piramide.h include/cilindro.h include/vaso.h include/vaso_inv.h include/cono.h include/tubo.h include/esfera.h
	g++ -o $@ $(CXXFLAGS) -c src/practica2.cpp -Iinclude


# O3DS

obj/O3DS.o: src/O3DS.cpp include/O3DS.h
	g++ -o $@ $(CXXFLAGS) -c src/O3DS.cpp -Iinclude

# O3D

obj/O3D.o: src/O3D.cpp include/O3D.h
	g++ -o $@ $(CXXFLAGS) -c src/O3D.cpp -Iinclude

# Cubo

obj/cubo.o: src/cubo.cpp include/cubo.h
	g++ -o $@ $(CXXFLAGS) -c src/cubo.cpp -Iinclude

# Tetraedro

obj/tetraedro.o: src/tetraedro.cpp include/tetraedro.h
	g++ -o $@ $(CXXFLAGS) -c src/tetraedro.cpp -Iinclude


# PlyReader

obj/file_ply_stl.o: src/file_ply_stl.cc include/file_ply_stl.h
	g++ -o $@ $(CXXFLAGS) -c src/file_ply_stl.cc -Iinclude

obj/PlyReader.o: src/PlyReader.cpp include/PlyReader.h
	g++ -o $@ $(CXXFLAGS) -c src/PlyReader.cpp -Iinclude

# Modelado O3DR

obj/O3DR.o: src/O3DR.cpp include/O3DR.h
	g++ -o $@ $(CXXFLAGS) -c src/O3DR.cpp -Iinclude



# Cilindro
obj/cilindro.o: src/cilindro.cpp include/cilindro.h
	g++ -o $@ $(CXXFLAGS) -c src/cilindro.cpp -Iinclude

# Vaso
obj/vaso.o: src/vaso.cpp include/vaso.h
	g++ -o $@ $(CXXFLAGS) -c src/vaso.cpp -Iinclude

# Vaso Invertido
obj/vaso_inv.o: src/vaso_inv.cpp include/vaso_inv.h
	g++ -o $@ $(CXXFLAGS) -c src/vaso_inv.cpp -Iinclude

# Cono
obj/cono.o: src/cono.cpp include/cono.h
	g++ -o $@ $(CXXFLAGS) -c src/cono.cpp -Iinclude

# Tubo
obj/tubo.o: src/tubo.cpp include/tubo.h
	g++ -o $@ $(CXXFLAGS) -c src/tubo.cpp -Iinclude

# Piramide
obj/piramide.o: src/piramide.cpp include/piramide.h
	g++ -o $@ $(CXXFLAGS) -c src/piramide.cpp -Iinclude

# Esfera
obj/esfera.o: src/esfera.cpp include/esfera.h
	g++ -o $@ $(CXXFLAGS) -c src/esfera.cpp -Iinclude


# LibFiguras

lib/libFiguras.a: obj/O3DS.o obj/O3D.o obj/cubo.o obj/tetraedro.o  obj/PlyReader.o obj/file_ply_stl.o obj/O3DR.o obj/piramide.o obj/cilindro.o obj/vaso.o obj/vaso_inv.o obj/cono.o obj/tubo.o obj/esfera.o
	ar rvs lib/libFiguras.a obj/O3DS.o obj/O3D.o obj/cubo.o obj/tetraedro.o  obj/PlyReader.o obj/file_ply_stl.o obj/O3DR.o  obj/cilindro.o obj/vaso.o obj/vaso_inv.o obj/cono.o obj/tubo.o obj/piramide.o obj/esfera.o



#
#
clean:
	rm -f obj/*.o lib/*
	rm -f $(TARGETS)

#
#
redo:
	touch src/*.cc
	make
