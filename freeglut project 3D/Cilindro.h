#pragma once
#include "ObjetoCuadrico.h"
class Cilindro :
	public ObjetoCuadrico
{
public:
	Cilindro();
	Cilindro(GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks);
	virtual ~Cilindro();
	virtual void dibuja();

protected:
	GLdouble baseRadius, topRadius, height;
	GLint slices, stacks;
};
