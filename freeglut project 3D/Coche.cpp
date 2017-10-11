#include "Coche.h"
#include "Rueda.h"
#include "ObjetoCuadrico.h"

Coche::Coche() {
	//Se añaden 7 elementos al objeto compuesto Coche
	//(1 chasis, 4 ruedas y 2 faros)
	//Por ejemplo, se añaden 4 ruedas,
	//compuestas por un cilindro y un disco
	for (int i = 0; i<4; i++)
		this->introduceObjeto(new Rueda());
	for (int i = 0; i < 2; i++)
	{
		this->introduceObjeto(new Cilindro());
	}
	//Se sitúan los 7 elementos dentro del coche
	//Por ejemplo, las ruedas 1..4
	//hijos[0] = 
	//hijos[1]->rota(90, 1, 0, 0);
	PuntoVector3D aux(1, 1, 1, 0 );
	hijos[1]->mt->traslada(&aux);
	
}

Coche::~Coche()
{
}
