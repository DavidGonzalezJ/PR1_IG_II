#include "Escena.h"
#include "Coche.h"


Escena::Escena()
{
	this->introduceObjeto(new Coche());
	hijos[0]->mt->traslada(new PuntoVector3D(0, 0.5, 0, 0));
}


Escena::~Escena()
{
}
