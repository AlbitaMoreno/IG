#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <string>

// ----------------------------------------------------------------------
// NECESARIO PARA CARGAR LAS IMÁGENES DE DISCO
#include "CImg.h"
using namespace cimg_library;
// ----------------------------------------------------------------------

//Functions declarations
void Init();
void OnDraw();

// FUNCIÓN QUE PREPARA LA TEXTURA
void prepara_textura(void);

// FUNCIÓN QUE DIBUJA
void dibuja(void);

// FUNCIÓN QUE LIBERA LA TEXTURA DE GPU
void libera_textura(void);


// IDENTIFICADOR DE TEXTURA
GLuint textura_id;
GLfloat vertices[] = {0, 0,
		      10, 0,
		      10, 5,
		      0, 5};
GLfloat texVertices[] = {0.0,1.0,
			 1.0,1.0,
			 1.0,0.0,
			 0.0,0.0};


void Init(int argc, char **argv){
   //Initialize GLUT windows manager
   //Create the window
   glutInit(&argc, argv);
   glutInitWindowSize(800,600);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutCreateWindow("My World");

   //enable lights and define perspective
   //glEnable(GL_LIGHT0);
   //glEnable(GL_LIGHTING);
   glEnable(GL_DEPTH_TEST);
   //glEnable(GL_COLOR_MATERIAL);
   glMatrixMode(GL_PROJECTION);
   gluPerspective( 40.0, 800/600.0f, 0.1, 150);

   prepara_textura();
}

void OnDraw(void){
   //cleaning the screen
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   //Define view
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   // eye position -> (0.0, 10, 20)
   // target -> (0,0,0)
   // define positive Y axis  -> (0.0, 1.0, 0.0)		
   gluLookAt(5.0, 10, 20,
	     0.0, 0, 0.0,
	     0.0, 1.0, 0.0);
   glTranslatef(-2,0,0);
   //Put your code here to draw objects
   dibuja();

   //no delete this line
   glutSwapBuffers();
}

int main(int argc, char** argv) {
   Init(argc, argv);
   //Enter the callbacks
   glutDisplayFunc(OnDraw);

   glutMainLoop(); // begin the loop

   // LIBERA LA TEXTURA
   libera_textura();
   return 0;
}


// ----------------------------------------------------------------------
void prepara_textura (void)
{
   std::vector<unsigned char> data;

   CImg<unsigned char> logo;
   logo.load("./logo.jpg");

   // empaquetamos bien los datos
   for (long y = 0; y < logo.height(); y ++)
      for (long x = 0; x < logo.width(); x ++)
      {
	 unsigned char *r = logo.data(x, y, 0, 0);
	 unsigned char *g = logo.data(x, y, 0, 1);
	 unsigned char *b = logo.data(x, y, 0, 2);
	 data.push_back(*r);
	 data.push_back(*g);
	 data.push_back(*b);
      }

   glGenTextures(1, &textura_id);
   glBindTexture(GL_TEXTURE_2D, textura_id);

   glActiveTexture(GL_TEXTURE0);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

   // TRASFIERE LOS DATOS A GPU
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, logo.width(), logo.height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);
}


void dibuja (void)
{
   glEnable(GL_TEXTURE_2D);
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState (GL_TEXTURE_COORD_ARRAY_EXT);

   glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, textura_id);

   glVertexPointer(2, GL_FLOAT, 0, vertices);
   glTexCoordPointer(2, GL_FLOAT, 0, texVertices);

   glDrawArrays(GL_QUADS, 0, 4);

   glDisableClientState(GL_VERTEX_ARRAY);
   glBindTexture(GL_TEXTURE_2D, 0);
   glDisable(GL_TEXTURE_2D);
}

void libera_textura (void)
{
   glDeleteTextures(1, &textura_id);
}

