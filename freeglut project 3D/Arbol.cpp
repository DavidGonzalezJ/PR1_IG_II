#include "Arbol.h"
#include "copaDoble.h"
#include "Cilindro.h"
#include "Esfera.h"


Arbol::Arbol(TipoArbol tipo)
{
	this->introduceObjeto(new Cilindro(0.75, 0.75, 4, 20, 20));
	if (tipo == TipoArbol::Abeto) {
		this->introduceObjeto(new Cilindro(1.5, 0, 4, 20, 20));
		hijos[1]->color = new PuntoVector3D(0, 0.7, 0.4, 0);
	}
	else if (tipo == TipoArbol::Roble) {
		this->introduceObjeto(new Esfera(2, 20, 20));
		hijos[1]->color = new PuntoVector3D(0, 0.7, 0.4, 0);
		PuntoVector3D aux{ 0, 2, 0, 0 };
		hijos[1]->mt->traslada(&aux);
	}
	else if (tipo == TipoArbol::Pino)
		this->introduceObjeto(new copaDoble(false));
	else
		this->introduceObjeto(new copaDoble(true));

	hijos[0]->color = new PuntoVector3D(0.58, 0.39, 0.02, 0);
	PuntoVector3D aux{ 1, 0, 0, 0 };
	hijos[0]->mt->rota(&aux, -90);
	aux={ 0, 3, 0, 0 };
	hijos[1]->mt->traslada(&aux);

	//Parche guarro para el abeto (porque se traslada mal al haberlo rotado)
	if (tipo == TipoArbol::Abeto) {
		aux = { 1,0,0,0 };
		hijos[1]->mt->rota(&aux, -90);
	}
}


Arbol::~Arbol()
{
}
