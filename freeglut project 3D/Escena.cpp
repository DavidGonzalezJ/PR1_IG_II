#include "Escena.h"
#include "Coche.h"
#include "Arbol.h"
#include "CopaSimple.h"
#include "copaDoble.h"

#include "Esfera.h"
#include <iostream>

// Tipos de arboles:
// Copa simple: Roble(Esfera), Abeto(Cono)
// Copa doble: Alamo(Esfera), Pino(Cono)

Escena::Escena()
{
	//this->introduceObjeto(new Coche());
	
	//hijos[0]->mt->traslada(new PuntoVector3D(0, 0.5, 0, 0));
	//this->introduceObjeto(new Arbol(Alamo));
	this->introduceObjeto(new copaDoble(true,  1, 2));
	/*
	this->introduceObjeto(new Arbol(Roble));
	this->introduceObjeto(new Arbol(Pino));
	this->introduceObjeto(new CopaSimple(false, 5));
	this->introduceObjeto(new Arbol(Alamo));

	for (int i = 1; i < 5; i++)
		hijos[i]->mt->traslada(new PuntoVector3D(i*2, 0 , 2*i, 0));*/

	//creaBosque();
}


Escena::~Escena()
{
}

void Escena::mueveCoche(bool dir) {
	PuntoVector3D aux = {1,0,0,1};
	if (dir)
		hijos[0]->mt->traslada(&aux);
	else{
		aux = { -1,0,0,1 };
		hijos[0]->mt->traslada(&aux);
	}
	digievolucion = 0;
	compruebaColision();
}

void Escena::giraCoche(bool right)
{
	PuntoVector3D aux = {0,1,0,1};
	if (right) {
		hijos[0]->mt->rota(&aux, -15);
		digievolucion += 15;
	}
	else {
		hijos[0]->mt->rota(&aux, 15);
		digievolucion -= 15;
	}
	if (digievolucion >= 1800 || digievolucion <= -1800) {
		digievolucion = 0;
		static_cast<Coche*>(hijos[0])->digievolucion();
		colision = 2;
	}
}


int Escena::dameRandom(int min, int max) {
	return rand() % (max - (min - 1)) + min;
}

void Escena::creaBosque()
{
	PuntoVector3D auxP{0,0,0,0};
	TipoArbol aux;
	for (int i = -10; i < 10; i++)//x
	{
		for (int j = -10;  j < 10; j++)//z
		{
			if (dameRandom(0, 1) == 1) {
				aux = static_cast<TipoArbol>(dameRandom(0,3));
				introduceObjeto(new Arbol(aux));
				auxP = { (GLfloat)i * 4,0,(GLfloat)j * 4,0 };
				hijos[numHijos - 1]->mt->traslada(&auxP);
			}
		}
	}
}

void Escena::compruebaColision()
{
	PuntoVector3D aux = hijos[0]->mt->damePos();
	std::cout << aux.getX() << " " << aux.getZ() << "\n";
	std::cout << hijos[1]->mt->damePos().getX() << " " << hijos[1]->mt->damePos().getZ() << "\n";

	for (int i = 1; i < numHijos; i++) {
		if (aux.getX() >= hijos[i]->mt->damePos().getX() - colision
			&& aux.getX() <= hijos[i]->mt->damePos().getX() + colision
			&& aux.getZ() >= hijos[i]->mt->damePos().getZ() - colision
			&& aux.getZ() <= hijos[i]->mt->damePos().getZ() + colision)
			hijos[i]->activo = false;
	}
}
