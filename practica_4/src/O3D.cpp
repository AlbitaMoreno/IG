#include "O3D.h"

void O3D ::dibuja_ajedrez()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLES);
	for (unsigned int i = 0; i < Triangles.size(); i++)
	{
		if (i % 2)
			glColor3f(1, 0, 0);
		else
			glColor3f(0, 0, 0);

		glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
		glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
		glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
	}
	glEnd();
}

void O3D ::dibuja_solido()
{
	glColor3f(0, 1, 1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < Triangles.size(); i++)
	{
		glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
		glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
		glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
	}
	glEnd();
}

void O3D ::dibuja_alambre()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1, 0, 1);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < Triangles.size(); i++)
	{
		glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
		glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
		glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
	}
	glEnd();
}

void O3D::elegirMaterial(Material mat)
{
	m = mat;
}

void O3D::dibuja_sombreado_plano()
{
	m.activarMaterial();
	calcularNormales();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLES);

	glColor3f(1, 0, 0); // Rojo
	float vert1, vert2, vert3;
	for (int i = 0; i < Triangles.size(); i++)
	{
		vert1 = Triangles[i].x;
		vert2 = Triangles[i].y;
		vert3 = Triangles[i].z;
		glNormal3fv((GLfloat *)&normales_caras[i]); // Posible error, comprobar.
		glVertex3fv((GLfloat *)&Vertices[vert1]);
		glVertex3fv((GLfloat *)&Vertices[vert2]);
		glVertex3fv((GLfloat *)&Vertices[vert3]);
	}
	glEnd();
}

void O3D::dibuja_sombreado_gouraud()
{ // Todavia no se ha comprobado que sirva pero podemos usarlo
	m.activarMaterial();
	calcularNormales();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);

	glColor3f(1, 0, 0);
	float vert1, vert2, vert3;
	for (int i = 0; i < Triangles.size(); i++)
	{
		vert1 = Triangles[i].x;
		vert2 = Triangles[i].y;
		vert3 = Triangles[i].z;
		glNormal3fv((GLfloat *)&normales_vertices[vert1]);
		glVertex3fv((GLfloat *)&Vertices[vert1]);
		glNormal3fv((GLfloat *)&normales_vertices[vert2]);
		glVertex3fv((GLfloat *)&Vertices[vert2]);
		glNormal3fv((GLfloat *)&normales_vertices[vert3]);
		glVertex3fv((GLfloat *)&Vertices[vert3]);
	}
	glEnd();
}

void O3D::calcularNormales()
{

	// Comenzamos calculando la tabla de normales de caras.

	normales_caras.resize(Triangles.size());

	_vertex3f aux_a;
	_vertex3f aux_b;
	_vertex3f a;
	_vertex3f b;
	_vertex3f c;
	_vertex3f mc;
	double modulo;

	for (int i = 0; i < Triangles.size(); i++)
	{

		a = Vertices[Triangles[i].x];
		b = Vertices[Triangles[i].y];
		c = Vertices[Triangles[i].z];
		aux_b = b - a;
		aux_a = c - a;

		// Producto vectorial a x b
		mc.x = aux_a.y * aux_b.z - aux_a.z * aux_b.y;
		mc.y = aux_a.z * aux_b.x - aux_a.x * aux_b.z;
		mc.z = aux_a.x * aux_b.y - aux_a.y * aux_b.x;

		//Normalizacion del vector mc para obtener la normal de la cara
		modulo = sqrt((mc.x * mc.x) + (mc.y * mc.y) + (mc.z * mc.z));
		normales_caras[i].x = mc.x / modulo;
		normales_caras[i].y = mc.y / modulo;
		normales_caras[i].z = mc.z / modulo;
	}

	// Calculamos las normales de los vertices.
	normales_vertices.resize(Vertices.size());
	vector<_vertex3f> mv;
	mv.resize(Vertices.size());

	for (int i = 0; i < Triangles.size(); i++)
	{
		mv[Triangles[i].x] += normales_caras[i];
		mv[Triangles[i].y] += normales_caras[i];
		mv[Triangles[i].z] += normales_caras[i];
	}

	for (int i = 0; i < mv.size(); i++)
	{
		modulo = sqrt((mv[i].x * mv[i].x) + (mv[i].y * mv[i].y) + (mv[i].z * mv[i].z));
		normales_vertices[i].x = mv[i].x / modulo;
		normales_vertices[i].y = mv[i].y / modulo;
		normales_vertices[i].z = mv[i].z / modulo;
	}
}

void O3D::resetCoordenadas()
{
	for (int i = 0; i < coordenadas_textura.size(); i++)
	{
		coordenadas_textura[i].x = -1;
	}
}
