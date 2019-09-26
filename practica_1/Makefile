# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica1

#
GLUT_DIR=/casa/dmartin/codigo/funciontecas/freeglut
GL_DIR=/usr/X11R6

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I.
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I.

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

.cc.o:
	$(CC) $(CXXFLAGS) -c $<

# como pasar de .o a ejecutable (sin sufijo)

.o:
	$(CC) -o $@ $^ $(LDFLAGS) 


# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de dependencias
#
$(TARGETS) : obj/o3ds.o obj/o3d.o obj/cube.o practica1.o

obj/practica1.o: src/practica1.cc

obj/o3ds.o: src/o3ds.cc include/o3ds.h

obj/o3d.o: src/models/o3d.cc include/models/o3d.h

obj/cube.o: src/models/Cube.cc include/models/Cube.h
#
#
clean:
	rm -f *.o
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

