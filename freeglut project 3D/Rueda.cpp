#include "Rueda.h"
#include "ObjetoCuadrico.h"

Rueda::Rueda()
{
	this->introduceObjeto(new Cilindro(1,1,1,20,20));
	this->introduceObjeto(new Disco(1,1 ,20, 20));
	this->introduceObjeto(new Disco(1, 1, 20, 20));

	PuntoVector3D aux(0, 0, 1, 0);
	hijos[1]->mt->traslada(&aux);

}


Rueda::~Rueda()
{
}
