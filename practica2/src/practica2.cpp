#include "stdlib.h"
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

using namespace std;

enum Figura
{
    cubo,
    tetraedro,
    piramide,
    esfera,
    ply,
    revolucion,
    tube,
    vas,
    vas_inv,
    cone,
    cilind
};
// tamaño de los ejes
const int AXIS_SIZE = 5000;

Figura figure;

Cubo cube;
Tetraedro tetra;

PlyReader aux_ply("perfil.ply");
PlyReader objeto_ply("ant.ply");

Cilindro cilinder;
Vaso va;
VasoInvertido vi;
Cono con;
Tubo tub;
Piramide pirami;

O3DR rev(aux_ply.Vertices);
Esfera sphere;

bool vertice = true;
bool arista = false;
bool chess = false;
bool solid = false;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width, Window_height, Front_plane, Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x = 50, UI_window_pos_y = 50, UI_window_width = 1000, UI_window_height = 1000;

//**************************************************************************
//
//***************************************************************************

void clear_window()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
    glFrustum(-Window_width, Window_width, -Window_height, Window_height, Front_plane, Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

    // posicion del observador
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -Observer_distance);
    glRotatef(Observer_angle_x, 1, 0, 0);
    glRotatef(Observer_angle_y, 0, 1, 0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
    glBegin(GL_LINES);
    // eje X, color rojo
    glColor3f(1, 0, 0);
    glVertex3f(-AXIS_SIZE, 0, 0);
    glVertex3f(AXIS_SIZE, 0, 0);
    // eje Y, color verde
    glColor3f(0, 1, 0);
    glVertex3f(0, -AXIS_SIZE, 0);
    glVertex3f(0, AXIS_SIZE, 0);
    // eje Z, color azul
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, -AXIS_SIZE);
    glVertex3f(0, 0, AXIS_SIZE);
    glEnd();
}

//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects()
{

    glPointSize(6);
    glLineWidth(2);

    switch (figure)
    {
    // Dibujar cubo
    case cubo:
        if (chess)
            cube.dibuja_ajedrez();
        if (vertice)
            cube.dibuja_puntos();
        if (arista)
            cube.dibuja_alambre();
        if (solid)
            cube.dibuja_solido();

        break;
    // Dibujar tetraedro
    case tetraedro:
        if (chess)
            tetra.dibuja_ajedrez();
        if (vertice)
            tetra.dibuja_puntos();
        if (arista)
            tetra.dibuja_alambre();
        if (solid)
            tetra.dibuja_solido();

        break;
    // Dibujar piramide
    case piramide:
        if (chess)
            pirami.dibuja_ajedrez();
        if (vertice)
            pirami.dibuja_puntos();
        if (arista)
            pirami.dibuja_alambre();
        if (solid)
            pirami.dibuja_solido();
        break;

    case esfera:
        if (chess)
            sphere.dibuja_ajedrez();
        if (vertice)
            sphere.dibuja_puntos();
        if (arista)
            sphere.dibuja_alambre();
        if (solid)
            sphere.dibuja_solido();
        break;
    case tube:
        if (chess)
            tub.dibuja_ajedrez();
        if (vertice)
            tub.dibuja_puntos();
        if (arista)
            tub.dibuja_alambre();
        if (solid)
            tub.dibuja_solido();
        break;
    case vas_inv:
        if (chess)
            vi.dibuja_ajedrez();
        if (vertice)
            vi.dibuja_puntos();
        if (arista)
            vi.dibuja_alambre();
        if (solid)
            vi.dibuja_solido();
        break;
    case vas:
        if (chess)
            va.dibuja_ajedrez();
        if (vertice)
            va.dibuja_puntos();
        if (arista)
            va.dibuja_alambre();
        if (solid)
            va.dibuja_solido();
        break;
    case cone:
        if (chess)
            con.dibuja_ajedrez();
        if (vertice)
            con.dibuja_puntos();
        if (arista)
            con.dibuja_alambre();
        if (solid)
            con.dibuja_solido();
        break;
    case ply:
        if (chess)
            objeto_ply.dibuja_ajedrez();
        if (vertice)
            objeto_ply.dibuja_puntos();
        if (arista)
            objeto_ply.dibuja_alambre();
        if (solid)
            objeto_ply.dibuja_solido();
        break;

    case revolucion:
        if (chess)
            rev.dibuja_ajedrez();
        if (vertice)
            rev.dibuja_puntos();
        if (arista)
            rev.dibuja_alambre();
        if (solid)
            rev.dibuja_solido();
        break;
    case cilind:
        if (chess)
            cilinder.dibuja_ajedrez();
        if (vertice)
            cilinder.dibuja_puntos();
        if (arista)
            cilinder.dibuja_alambre();
        if (solid)
            cilinder.dibuja_solido();
        break;
    default:
        cout << "Pulse una tecla para cambiar de modo" << endl;
        break;
    }
    glEnd();
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
}

//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1, int Alto1)
{
    change_projection();
    glViewport(0, 0, Ancho1, Alto1);
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

void normal_keys(unsigned char Tecla1, int x, int y)
{

    unsigned char tecla = toupper(Tecla1);
    switch (tecla)
    {
    case 'Q':
        exit(0);
        break;
    case 'P': //vertices
        vertice = !vertice;
        break;
    case 'L': //aristas
        arista = !arista;
        break;
    case 'S': //lados
        solid = !solid;
        chess = false;
        break;
    case 'A': //ajedrez
        chess = !chess;
        solid = false;
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

void special_keys(int Tecla1, int x, int y)
{

    switch (Tecla1)
    {
    case GLUT_KEY_F1:
        figure = cubo;
        break; // Cubo
    case GLUT_KEY_F2:
        figure = tetraedro;
        break; // Tetraedro
    case GLUT_KEY_F3:
        figure = ply;
        break; //objeto ply
    case GLUT_KEY_F4:
        figure = revolucion;
        break;
    case GLUT_KEY_F5:
        figure = cilind;
        break;
    case GLUT_KEY_F6:
        figure = vas_inv;
        break;
    case GLUT_KEY_F7:
        figure = esfera;
        break;
    case GLUT_KEY_F8:
        figure = tube;
        break;
    case GLUT_KEY_F9:
        figure = vas;
        break;
    case GLUT_KEY_F10:
        figure = cone;
        break;

    case GLUT_KEY_LEFT:
        Observer_angle_y--;
        break;
    case GLUT_KEY_RIGHT:
        Observer_angle_y++;
        break;
    case GLUT_KEY_UP:
        Observer_angle_x--;
        break;
    case GLUT_KEY_DOWN:
        Observer_angle_x++;
        break;
    case GLUT_KEY_PAGE_UP:
        Observer_distance *= 1.2;
        break;
    case GLUT_KEY_PAGE_DOWN:
        Observer_distance /= 1.2;
        break;
    }
    glutPostRedisplay();
}

//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
    // se inicalizan la ventana y los planos de corte
    Window_width = 0.5;
    Window_height = 0.5;
    Front_plane = 1;
    Back_plane = 1000;

    // se inicia la posicion del observador, en el eje z
    Observer_distance = 2 * Front_plane;
    Observer_angle_x = 0;
    Observer_angle_y = 0;

    // se indica cual sera el color
    //para limpiar la ventana	(r,v,a,al)
    // blanco=(1,1,1,1) rojo=(1,0,0,1), ...
    glClearColor(1, 1, 1, 1);

    // se habilita el z-bufer
    glEnable(GL_DEPTH_TEST);
    //
    change_projection();
    //
    glViewport(0, 0, UI_window_width, UI_window_height);
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
    glutInitWindowPosition(UI_window_pos_x, UI_window_pos_y);

    // tamaño de la ventana (ancho y alto)
    glutInitWindowSize(UI_window_width, UI_window_height);

    // llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
    // al bucle de eventos)
    glutCreateWindow("Práctica 2");

    // asignación de la funcion llamada "dibujar" al evento de dibujo
    glutDisplayFunc(draw_scene);
    // asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
    glutReshapeFunc(change_window_size);
    // asignación de la funcion llamada "tecla_normal" al evento correspondiente
    glutKeyboardFunc(normal_keys);
    // asignación de la funcion llamada "tecla_Especial" al evento correspondiente
    glutSpecialFunc(special_keys);

    // funcion de inicialización
    initialize();

    // inicio del bucle de eventos
    glutMainLoop();
    return 0;
}
