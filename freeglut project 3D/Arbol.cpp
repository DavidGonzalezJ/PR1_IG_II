#include "Arbol.h"
#include "copaDoble.h"
#include "copaSimple.h"
#include "Cilindro.h"
#include "Esfera.h"


Arbol::Arbol(TipoArbol tipo)
{
	//TRONCO
	GLfloat troncoAl = dameRandom(2, 6);
	this->introduceObjeto(new Cilindro(0.75, 0.5, troncoAl, 20, 20));
	hijos[0]->color = new PuntoVector3D(0.58, 0.39, 0.02, 0);
	PuntoVector3D aux{ 1, 0, 0, 0 };
	hijos[0]->mt->rota(&aux, -90);

	//COPAS
	if (tipo == TipoArbol::Abeto) {
		this->introduceObjeto(new CopaSimple(false, dameRandom(1, 3)));
		hijos[1]->color = new PuntoVector3D(0, 0.7, 0.4, 0);

	}
	else if (tipo == TipoArbol::Roble) {
		this->introduceObjeto(new CopaSimple(true, dameRandom(1, 3)));

	}
	else if (tipo == TipoArbol::Pino){
		this->introduceObjeto(new copaDoble(false, dameRandom(1, 3), dameRandom(1, 3)));
	}
	else //ÁLAMO
		this->introduceObjeto(new copaDoble(true, dameRandom(1, 3), dameRandom(1, 3)));
	troncoAl -= 0.25;
	aux = { 0, troncoAl, 0, 0 };
	hijos[1]->mt->traslada(&aux);
}


Arbol::~Arbol()
{
}
