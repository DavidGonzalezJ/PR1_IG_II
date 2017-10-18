#include "Cilindro.h"


Cilindro::Cilindro():baseRadius(1), topRadius(1), height(1), slices(20), stacks(20)
{
}

Cilindro::Cilindro(GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks) :
baseRadius(baseRadius), topRadius(topRadius), height(height), slices(slices), stacks(stacks){}

Cilindro::~Cilindro()
{
}
void Cilindro::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mt->m);

	glColor3f(color->getX(), color->getY(), color->getZ());
	gluCylinder(q, baseRadius, topRadius, height, slices,
		stacks);
	glPopMatrix();
};