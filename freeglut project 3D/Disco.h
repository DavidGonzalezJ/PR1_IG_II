#pragma once
#include "ObjetoCuadrico.h"
class Disco :
	public ObjetoCuadrico
{
public:
	Disco();
	Disco(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint stacks);
	~Disco();
	virtual void dibuja();

protected:
	GLdouble innerRadius, outerRadius;
	GLint slices, rings;

};