#include "copaDoble.h"
#include "Esfera.h"
#include "Cilindro.h"

copaDoble::copaDoble(bool esf){
	color = new PuntoVector3D(0, 0.7, 0.4, 0);
	if (esf){
		this->introduceObjeto(new Esfera(2,20,20));
		this->introduceObjeto(new Esfera(1.5, 20, 20));
		PuntoVector3D aux(-0.75, 1, 0, 0);
		hijos[0]->mt->traslada(&aux);
		aux = { 0.75, 1, 0, 0 };
		hijos[1]->mt->traslada(&aux);
	}
	else{
		this->introduceObjeto(new Cilindro(1.5, 0, 4, 20, 20));
		this->introduceObjeto(new Cilindro(1.5, 0, 4, 20, 20));
		PuntoVector3D aux(0, 1, 0, 0);
		hijos[1]->mt->traslada(&aux);
		aux = { 1, 0, 0, 0 };
		hijos[0]->mt->rota(&aux,-90);
		hijos[1]->mt->rota(&aux, -90);

	}
	hijos[0]->color = color;
	hijos[1]->color = color;

}

copaDoble::~copaDoble()
{
}
