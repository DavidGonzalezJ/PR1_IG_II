#include "Esfera.h"


Esfera::~Esfera()
{
}
void Esfera::dibuja(){
	glColor3f(color->getX(), color->getY(), color->getZ());
	gluSphere(q, radius, slices, stacks);
}