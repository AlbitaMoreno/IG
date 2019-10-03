# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS=./bin/practica1

#
GLUT_DIR=/casa/dmartin/codigo/funciontecas/freeglut
GL_DIR=/usr/X11R6

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I.
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I. -I./include

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -L$(GL_DIR)/lib64 -lGL -L$(GLUT_DIR)/lib64 -lglut 

# definicion del compilador
#
CC = g++

# sufijos
.SUFFIXES: .cc .c .o

# Reglas
# $< -> todas las dependencias que han cambiado
# $@ -> el objetivo
# $^ -> todas las dependencias

# como pasar de .cc a .o

obj/%.o:
	$(CC) $(CXXFLAGS) -c $< -o $@

# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de dependencias
#
$(TARGETS) : obj/o3ds.o obj/o3d.o obj/Cube.o obj/tetrahedro.o obj/piramide.o obj/octaedro.o obj/practica1.o
	$(CC) -o $@ $^ $(LDFLAGS) 

obj/practica1.o: src/practica1.cc

obj/o3ds.o: src/models/o3ds.cc include/o3ds.h
obj/o3d.o: src/models/o3d.cc include/o3d.h

obj/Cube.o: src/models/Cube.cc include/Cube.h
obj/tetrahedro.o: src/models/extras/tetrahedro.cc include/tetrahedro.h
obj/piramide.o: src/models/extras/piramide.cc include/piramide.h
obj/octaedro.o: src/models/extras/octaedro.cc include/octaedro.h
#
#
clean:
	rm -f obj/*.o
	rm -f $(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *

