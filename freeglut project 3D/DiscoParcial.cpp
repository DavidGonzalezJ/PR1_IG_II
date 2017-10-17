#include "DiscoParcial.h"


DiscoParcial::DiscoParcial() : outerRadius(1), innerRadius(1), slices(20),
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
	glColor3f(color->getX(), color->getY(), color->getZ());
	gluPartialDisk(q, innerRadius, outerRadius, slices, rings,
		startAngle, sweepAngle);
};