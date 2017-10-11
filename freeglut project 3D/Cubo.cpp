#include "Cubo.h"

Cubo::~Cubo()
{
}

void Cubo::dibuja(){
	if (solido){
		glColor3f(color->getX(), color->getY(), color->getZ());
		glutSolidCube(size);
	}
	else{ 
		glColor3f(color->getX(), color->getY(), color->getZ());
		glutWireCube(size);
	}
}