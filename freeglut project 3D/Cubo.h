#pragma once
#include "Malla.h"
class Cubo : public Malla
{
public:
	Cubo();
	virtual ~Cubo();
	virtual void dibuja();
	void cambiaSoliAWire(){
		solido = !solido;
	}
	bool solido = true;
	//GLfloat size;
};

