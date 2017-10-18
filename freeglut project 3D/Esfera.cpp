#include "Esfera.h"


Esfera::~Esfera()
{
}
void Esfera::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//Cargar m como matriz actual de modelado-vista
	glMultMatrixf(mt->m);
	glColor3f(color->getX(), color->getY(), color->getZ());
	gluSphere(q, radius, slices, stacks);
	glPopMatrix();
}