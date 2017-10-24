#include "Escena.h"
#include "Coche.h"
#include "Arbol.h"

// Tipos de arboles:
// Copa simple: Roble(Esfera), Abeto(Cono)
// Copa doble: Alamo(Esfera), Pino(Cono)

Escena::Escena()
{
	this->introduceObjeto(new Coche());
	hijos[0]->mt->traslada(new PuntoVector3D(0, 0.5, 0, 0));
	this->introduceObjeto(new Arbol(TipoArbol::Abeto));
	hijos[1]->mt->traslada(new PuntoVector3D(6, 0, 7, 0));
	this->introduceObjeto(new Arbol(TipoArbol::Roble));
	hijos[2]->mt->traslada(new PuntoVector3D(-7, 0, 6, 0));
	this->introduceObjeto(new Arbol(TipoArbol::Pino));
	hijos[3]->mt->traslada(new PuntoVector3D(6, 0, -6, 0));
	this->introduceObjeto(new Arbol(TipoArbol::Alamo));
	hijos[4]->mt->traslada(new PuntoVector3D(-5, 0, -5, 0));

}


Escena::~Escena()
{
}
