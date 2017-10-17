#pragma once
#include "ObjetoCuadrico.h"
class DiscoParcial :
	public ObjetoCuadrico
{
public:
	DiscoParcial();
	DiscoParcial(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint stacks,
		GLdouble startAngle, GLdouble sweepAngle);
	virtual ~DiscoParcial();
	virtual void dibuja();

protected:
	GLdouble innerRadius, outerRadius, startAngle, sweepAngle;
	GLint slices, rings;
};

