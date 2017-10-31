#include "copaDoble.h"
#include "Esfera.h"
#include "Cilindro.h"

copaDoble::copaDoble(bool esf, GLfloat tam1, GLfloat tam2){
	color = new PuntoVector3D(0, 0.7, 0.4, 0);
	GLfloat menor, mayor;
	if (tam1 < tam2){ 
		menor = tam1; 
		mayor = tam2; 
	}else{
		menor = tam2;
		mayor = tam1; 
	}

	if (esf){
		this->introduceObjeto(new Esfera(mayor, 20, 20));
		this->introduceObjeto(new Esfera(menor, 20, 20));
		PuntoVector3D aux(0.5*menor, menor, 0, 0);
		hijos[0]->mt->traslada(&aux);
		GLfloat mult = 0.5*menor;
		aux = { mult, menor, 0, 0 };
		hijos[1]->mt->traslada(&aux);
	}
	else{
		this->introduceObjeto(new Cilindro(1.5, 0, 4, 20, 20));
		this->introduceObjeto(new Cilindro(1.5, 0, 4, 20, 20));
		PuntoVector3D aux(0, 1, 0, 0);
		hijos[1]->mt->traslada(&aux);
		aux = { 1, 0, 0, 0 };
		hijos[0]->mt->rota(&aux, -90);
		hijos[1]->mt->rota(&aux, -90);

	}
	hijos[0]->color = color;
	hijos[1]->color = color;

}

copaDoble::~copaDoble()
{
}
