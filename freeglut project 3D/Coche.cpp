#include "Coche.h"
#include "Rueda.h"
#include "Cubo.h"


Coche::Coche() {
	//Se añaden 7 elementos al objeto compuesto Coche
	//(1 chasis, 4 ruedas y 2 faros)
	//Por ejemplo, se añaden 4 ruedas,
	//compuestas por un cilindro y un disco
	this->introduceObjeto(new Cubo(2));
	for (int i = 0; i < 4; i++){
		this->introduceObjeto(new Rueda());
	}
	//FAROS
	for (int i = 0; i < 2; i++)
	{
		this->introduceObjeto(new Cilindro(0.25,0.25,0.3,20,20));
	}
	hijos[5]->color=new PuntoVector3D(0, 1, 0.5,0);
	hijos[6]->color=new PuntoVector3D(0, 1, 0.5,0);

	//CHASIS
	PuntoVector3D aux(0, 0.5, 0, 0);
	hijos[0]->mt->traslada(&aux);

	//RUEDAS
	aux = { -1, 0, -1.25, 0 };
	hijos[1]->mt->traslada(&aux);
	aux = { -1, 0, 1, 0 };
	hijos[2]->mt->traslada(&aux);
	aux = { 1, 0, -1.25, 0 };
	hijos[3]->mt->traslada(&aux);
	aux = { 1, 0, 1, 0 };
	hijos[4]->mt->traslada(&aux);
	
	//FAROS
	aux = { 1, 0.75, 0.5, 0 };
	hijos[5]->mt->traslada(&aux);
	aux = { 0, 1, 0, 0 };
	hijos[5]->mt->rota(&aux,90);

	aux = { 1, 0.75, -0.5, 0 };
	hijos[6]->mt->traslada(&aux);
	aux = { 0, 1,0, 0 };
	hijos[6]->mt->rota(&aux,90);

	
}

Coche::~Coche()
{
}
