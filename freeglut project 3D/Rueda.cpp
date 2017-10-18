#include "Rueda.h"


Rueda::Rueda()
{
	this->introduceObjeto(new Cilindro(0.5, 0.5, 0.25, 20, 20));
	this->introduceObjeto(new Disco(0, 0.5 ,20, 20));
	this->introduceObjeto(new Disco(0, 0.5, 20, 20));
	
	hijos[0]->color = new PuntoVector3D(0, 0, 0, 0);
	hijos[1]->color = new PuntoVector3D(0.8, 0.6, 0.1, 0);
	hijos[2]->color = new PuntoVector3D(0.8, 0.6, 0.1, 0);

	PuntoVector3D aux(0, 0, 0.25, 0);
	hijos[1]->mt->traslada(&aux);
}


Rueda::~Rueda()
{
}