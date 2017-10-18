#include "Disco.h"


Disco::Disco() : outerRadius(0), innerRadius(1), slices(20), rings(20)
{
}
Disco::Disco(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint rings) :
innerRadius(innerRadius), outerRadius(outerRadius), slices(slices), rings(rings){};

Disco::~Disco()
{
}

void Disco::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//Cargar m como matriz actual de modelado-vista
	glMultMatrixf(mt->m);
	glColor3f(color->getX(), color->getY(), color->getZ());
	gluDisk(q, innerRadius, outerRadius, slices, rings);
	glPopMatrix();
};
