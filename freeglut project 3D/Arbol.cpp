#include "Arbol.h"
#include "copaDoble.h"
#include "Cilindro.h"


Arbol::Arbol(bool roble)
{
	this->introduceObjeto(new Cilindro(0.75, 0.75, 4, 20, 20));
	this->introduceObjeto(new copaDoble(roble));
	hijos[0]->color = new PuntoVector3D(0.58, 0.39, 0.02, 0);
	PuntoVector3D aux{ 1, 0, 0, 0 };
	hijos[0]->mt->rota(&aux, -90);
	aux={ 0, 3, 0, 0 };
	hijos[1]->mt->traslada(&aux);
}


Arbol::~Arbol()
{
}
