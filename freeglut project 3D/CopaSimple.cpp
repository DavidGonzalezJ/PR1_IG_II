#include "CopaSimple.h"
#include "Esfera.h"
#include "Cilindro.h"

CopaSimple::CopaSimple(bool esf, GLfloat tam){
	PuntoVector3D aux(0,0,0,0);
	if (esf){
		this->introduceObjeto(new Esfera(tam, 20, 20));
		aux = { 0, tam, 0, 0 };
		hijos[0]->mt->traslada(&aux);
	}
	else{
		this->introduceObjeto(new Cilindro(tam, 0, 4, 20, 20));
		aux = {1, 0, 0, 0};
		hijos[0]->mt->rota(&aux, -90);
	}
	color = new PuntoVector3D(0, 0.7, 0.4, 0);
	hijos[0]->color = color;
}


CopaSimple::~CopaSimple()
{
}
