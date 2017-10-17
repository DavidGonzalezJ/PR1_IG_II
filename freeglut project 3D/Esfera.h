#pragma once
#include "ObjetoCuadrico.h"
class Esfera :
	public ObjetoCuadrico
{
public:
	Esfera() : radius(1), slices(20), stacks(20){};
	Esfera(GLfloat radius, GLint slices, GLint stacks) : radius(radius),
		slices(slices), stacks(stacks){};
	virtual ~Esfera();
	virtual void dibuja();
protected:
	GLfloat radius;
	GLint slices, stacks;
};