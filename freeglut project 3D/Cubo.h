#pragma once
#include "Malla.h"
class Cubo : public Malla
{
public:
	Cubo() : size(1){};
	Cubo(GLfloat size) :size(size){};
	virtual ~Cubo();
	virtual void dibuja();
	void cambiaSoliAWire(){
		solido = !solido;
	}
	bool solido = true;
	GLfloat size;
};

