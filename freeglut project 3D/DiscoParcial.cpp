#include "DiscoParcial.h"


DiscoParcial::DiscoParcial() : outerRadius(1), innerRadius(0.5), slices(20),
	rings(20), startAngle(0), sweepAngle(90)
{
}

DiscoParcial:: DiscoParcial(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint stacks,
	GLdouble startAngle, GLdouble sweepAngle) :
	innerRadius(innerRadius), outerRadius(outerRadius), slices(slices), rings(rings),
	startAngle(startAngle), sweepAngle(sweepAngle){};

DiscoParcial::~DiscoParcial()
{
}
void DiscoParcial::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//Cargar m como matriz actual de modelado-vista
	glMultMatrixf(mt->m);
	glColor3f(color->getX(), color->getY(), color->getZ());
	gluPartialDisk(q, innerRadius, outerRadius, slices, rings,
		startAngle, sweepAngle);
	glPopMatrix();
};