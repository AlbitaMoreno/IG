#include <cstdlib>
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include "cubo.h"
#include "tetraedro.h"
#include "PlyReader.h"
#include "O3DR.h"
#include "cilindro.h"
#include "vaso.h"
#include "vaso_inv.h"
#include "cono.h"
#include "tubo.h"
#include "piramide.h"
#include "esfera.h"


#include "base.h"
#include "block.h"
#include "parte_arriba.h"
#include "brazo.h"
#include "regulador.h"
#include "bloque_central.h"
#include "esqueleto.h"


#include "Tablero.h"
#include "fuenteluz.h"
#include "Textura.h"
#include "material.h"


using namespace std;

enum Figura { cubo, tetraedro, piramide, esfera, ply, revolucion, tube, vas, vas_inv, cone, cilind, regulador, tablero};
// tamaño de los ejes
const int AXIS_SIZE=5000;

Figura figure;

Cubo cube;
Tetraedro tetra;

PlyReader aux_ply("perfil.ply");
PlyReader objeto_ply("beethoven.ply");

Cilindro cilinder;
Vaso va;
VasoInvertido vi;
Cono con;
Tubo tub;
Piramide pirami;

O3DR rev(aux_ply.Vertices);
Esfera sphere;

Base bot;
Block bloc;
ParteArriba pa;
Brazo bra;
BloqueCentral bc;
Esqueleto esq;
Regulador reg;

bool vertice = true;
bool arista = false;
bool chess = false;
bool solid = false;
bool gourand = false;
bool plano = false;
bool l1 = true;
bool l2 = true;

float rot = 0, inc = 1.0;
float vel = 0;
float inc_vel = 0.2;		// Velocidad e incremento del cilindro de la base.
float vel_min = 0.2, vel_max = 10;
float bajada_min = 0, subida_max = 15;

Tablero table(4);

FuenteLuz luz1(GL_LIGHT0,false, (0,1,1), _vertex4f(0,5,200,1), _vertex4f(0.8,0.8,0.8,1), _vertex4f(0.9,0.9,0.9,1), _vertex4f(0.5,0.5,0.5,1));
FuenteLuz luz2(GL_LIGHT1,true, (0,1,0), _vertex4f(0,5,200,0), _vertex4f(0.7,0.7,0.7,1), _vertex4f(1,1,1,1), _vertex4f(0.3,0.3,0.3,1));

Material m1(_vertex4f(0.5,0.0,0.0,1), _vertex4f(0.7,0.6,0.6,1), _vertex4f(0.0,0.0,0.0,1), 10, false, NULL);
Material m2(_vertex4f(0.0,0.0,0.5,1), _vertex4f(0.04,0.7,0.04,0), _vertex4f(0.0,0.05,0.0,1), 5, false, NULL);		// Dif espec ambiental
Material m3(_vertex4f(0.8,0.8,0.8,1), _vertex4f(0.8,0.8,0.8,1), _vertex4f(0.8,0.8,0.8,1), 1, true, "./texturas/dia_8192.jpg");
// Dif espec ambiental


// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=1000,UI_window_height=1000;

//**************************************************************************
//
//***************************************************************************

void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects()
{

    glPointSize(6);
    glLineWidth(2);

    switch(figure){
        // Dibujar cubo
        case cubo:
            cube.calcularNormales();

            if(chess) cube.dibuja_ajedrez();
            if(vertice) cube.dibuja_puntos();
            if(arista) cube.dibuja_alambre();
            if(solid) cube.dibuja_solido();
            if(gourand) cube.dibuja_sombreado_gouraud();
            if(plano) cube.dibuja_sombreado_plano();

        break;
        // Dibujar tetraedro
        case tetraedro:
            tetra.calcularNormales();

            if(chess) tetra.dibuja_ajedrez();
            if(vertice) tetra.dibuja_puntos();
            if(arista) tetra.dibuja_alambre();
            if(solid) tetra.dibuja_solido();
            if(gourand) tetra.dibuja_sombreado_gouraud();
            if(plano) tetra.dibuja_sombreado_plano();

        break;
        // Dibujar piramide
        case piramide:
          if(chess) pirami.dibuja_ajedrez();
          if(vertice) pirami.dibuja_puntos();
          if(arista) pirami.dibuja_alambre();
          if(solid) pirami.dibuja_solido();
          if(gourand) pirami.dibuja_sombreado_gouraud();
          if(plano) pirami.dibuja_sombreado_plano();
       break;

        case esfera:
          if(chess) sphere.dibuja_ajedrez();
          if(vertice) sphere.dibuja_puntos();
          if(arista) sphere.dibuja_alambre();
          if(solid) sphere.dibuja_solido();
          if(gourand) sphere.dibuja_sombreado_gouraud();
          if(plano) sphere.dibuja_sombreado_plano();
        break;
        case tube:
          if(chess) tub.dibuja_ajedrez();
          if(vertice) tub.dibuja_puntos();
          if(arista) tub.dibuja_alambre();
          if(solid) tub.dibuja_solido();
          if(gourand) tub.dibuja_sombreado_gouraud();
          if(plano) tub.dibuja_sombreado_plano();
        break;
        case vas_inv:
          if(chess) vi.dibuja_ajedrez();
          if(vertice) vi.dibuja_puntos();
          if(arista) vi.dibuja_alambre();
          if(solid) vi.dibuja_solido();
          if(gourand) vi.dibuja_sombreado_gouraud();
          if(plano) vi.dibuja_sombreado_plano();
        break;
        case vas:
          if(chess) va.dibuja_ajedrez();
          if(vertice) va.dibuja_puntos();
          if(arista) va.dibuja_alambre();
          if(solid) va.dibuja_solido();
          if(gourand) va.dibuja_sombreado_gouraud();
          if(plano) va.dibuja_sombreado_plano();
        break;
        case cone:
          if(chess) con.dibuja_ajedrez();
          if(vertice) con.dibuja_puntos();
          if(arista) con.dibuja_alambre();
          if(solid) con.dibuja_solido();
          if(gourand) con.dibuja_sombreado_gouraud();
          if(plano) con.dibuja_sombreado_plano();
        break;
        case ply:
            if(chess) objeto_ply.dibuja_ajedrez();
            if(vertice) objeto_ply.dibuja_puntos();
            if(arista) objeto_ply.dibuja_alambre();
            if(solid) objeto_ply.dibuja_solido();
        break;

        case revolucion:
          if(chess) rev.dibuja_ajedrez();
          if(vertice) rev.dibuja_puntos();
          if(arista) rev.dibuja_alambre();
          if(solid) rev.dibuja_solido();
        break;
        case cilind:
          if(chess) cilinder.dibuja_ajedrez();
          if(vertice) cilinder.dibuja_puntos();
          if(arista) cilinder.dibuja_alambre();
          if(solid) cilinder.dibuja_solido();
          if(gourand) cilinder.dibuja_sombreado_gouraud();
          if(plano) cilinder.dibuja_sombreado_plano();
        break;
        /*case regulador:
          reg.dibuja(chess, vertice, arista, solid,vel,rot);
        break;*/
        // Dibujar tablero
		    case tablero:
			     table.dibuja2(chess, vertice, arista, solid, gourand, plano);
			  break;
        default:
            cout << "Pulse una tecla válida : \n p -> puntos \n l -> lados \n c -> chess \n f -> sólido \n N -> luz1.Deactivate\n M -> luz2.Deactivate\n E -> luz1.alfa\n D -> l1.beta\n R -> luz2.alfa\n F -> luz2.beta\n Z -> material1\n X -> material2\n B -> imagen"<< endl;
            break;
    }
    glEnd();

}


void idle(){
	vel+=inc_vel;
	glutPostRedisplay();
}
//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{

clear_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();

luz1.Activate();
luz2.Activate();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{

    unsigned char tecla = Tecla1;
    switch(tecla){
        case 'Q':
            exit(0);
            break;
        case 'p':       //vertices
            vertice = !vertice;
            break;
        case 'l':       //aristas
            arista = !arista;
            break;
        case 'f':       //lados
            solid = !solid;
            chess = false;
            break;
        case 'c':       //ajedrez
            chess = !chess;
            solid = false;
            break;

        case 's':
          gourand = !gourand;
          if(gourand) plano = false;
          else  plano = true;
        /*case 'K':
    			rot-=inc;
    			if(rot <= bajada_min)
    				rot = bajada_min;
    			inc_vel -= 0.3;
    			if(inc_vel <= vel_min)
    				inc_vel = vel_min;
    			break;
    		case 'k':
    			rot+=inc;
    			if(rot >= subida_max)
    				rot = subida_max;
    			inc_vel += 0.3;
    			if(inc_vel >= vel_max)
    				inc_vel = vel_max;
    			break;*/
          // Luces.
      		case 'N':
            l1 = !l1;
            if(l1) luz1.Activate();
            else luz1.Deactivate();
          break;
          case 'M':
            l2 = !l2;
            if(l2)  luz2.Activate();
            else luz2.Deactivate();
          break;
      		case 'E':
      			luz1.ChangeAlfa();
      			break;
      		case 'D':
      			luz1.ChangeBeta();
      			break;
      		case 'R':
      			luz2.ChangeAlfa();
      			break;
      		case 'F':
      			luz2.ChangeBeta();
      			break;
            // Materiales.
      		case 'Z':
      			table.elegirMaterial(m1);
      			cube.elegirMaterial(m1);
      			tetra.elegirMaterial(m1);
      			cilinder.elegirMaterial(m1);
      			tub.elegirMaterial(m1);
      			con.elegirMaterial(m1);
      			va.elegirMaterial(m1);
      			vi.elegirMaterial(m1);
      			rev.elegirMaterial(m1);
      			pirami.elegirMaterial(m1);
      			sphere.elegirMaterial(m1);
      			break;
      		case 'X':
      			table.elegirMaterial(m2);
      			cube.elegirMaterial(m2);
      			tetra.elegirMaterial(m2);
      			cilinder.elegirMaterial(m2);
      			tub.elegirMaterial(m2);
      			con.elegirMaterial(m2);
      			va.elegirMaterial(m2);
      			vi.elegirMaterial(m2);
      			rev.elegirMaterial(m2);
      			pirami.elegirMaterial(m2);
      			sphere.elegirMaterial(m2);
      			break;
      		case 'C':
      			table.elegirMaterial(m3);
      			break;
            // Texturas sobre el tablero
        		case 'K':
        			table.calcularCoordenadasTextura_Invertido();
        			break;
        		case 'L':
        			table.calcularCoordenadasTextura_CuartaParte();
        			break;
        		case 'V':
        			table.calcularCoordenadas_TexturaCentro();
        			break;
        		case 'O':
        			table.calcularCoordenadas();
        			break;


        default:
            break;
    }

    draw_scene();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{

	switch (Tecla1){
	    case GLUT_KEY_F1: figure = cubo;break;		// Cubo
	    case GLUT_KEY_F2: figure = tetraedro;break;		// Tetraedro
	    case GLUT_KEY_F3: figure = piramide; break;     //objeto ply
	    // case GLUT_KEY_F4: figure = revolucion; break;
	    case GLUT_KEY_F5: figure = cilind; break;
      case GLUT_KEY_F6: figure = vas_inv; break;
      case GLUT_KEY_F7: figure = esfera; break;
      case GLUT_KEY_F8: figure = tube; break;
      case GLUT_KEY_F9: figure = vas; break;
      case GLUT_KEY_F10: figure = cone; break;
      case GLUT_KEY_F11: figure = regulador; break;
      case GLUT_KEY_F12: figure = tablero; break;

	  case GLUT_KEY_LEFT:Observer_angle_y--;break;
		case GLUT_KEY_RIGHT:Observer_angle_y++;break;
		case GLUT_KEY_UP:Observer_angle_x--;break;
		case GLUT_KEY_DOWN:Observer_angle_x++;break;
		case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
		case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
		}
	glutPostRedisplay();
}




//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Window_width=0.5;
Window_height=0.5;
Front_plane=1;
Back_plane=1000;

// se inicia la posicion del observador, en el eje z
Observer_distance=2*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color
 //para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
//
change_projection();
//
glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("Práctica 4");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);
glutIdleFunc(idle);		// Animación
// funcion de inicialización
initialize();

// inicio del bucle de eventos
glutMainLoop();
return 0;
}
