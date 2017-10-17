#include "Disco.h"


Disco::Disco() : outerRadius(1), innerRadius(1), slices(20), rings(20)
{
}
Disco::Disco(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint stacks) :
innerRadius(innerRadius), outerRadius(outerRadius), slices(slices), rings(rings){};

Disco::~Disco()
{
}

void Disco::dibuja(){
	glColor3f(color->getX(), color->getY(), color->getZ());
	gluDisk(q, innerRadius, outerRadius, slices, rings);
};
