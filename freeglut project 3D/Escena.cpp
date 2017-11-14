#include "Escena.h"
#include "Coche.h"
#include "Arbol.h"
#include "CopaSimple.h"
#include "copaDoble.h"
#include "Quadtree.h"

#include "Esfera.h"
#include <iostream>

#define tamBosque 40

// Tipos de arboles:
// Copa simple: Roble(Esfera), Abeto(Cono)
// Copa doble: Alamo(Esfera), Pino(Cono)

Escena::Escena():numArboles(0), numArbRecog(0), finalP(false)
{
	this->introduceObjeto(new Coche());
	
	hijos[0]->mt->traslada(new PuntoVector3D(0, 0.5, 0, 0));
	
	creaBosque();
	quadtree = new Quadtree(hijos, static_cast<ObjetoCompuesto*>(hijos[0]),numArboles+1);
	quadtree->initialize(tamBosque*4,tamBosque*4,tamBosque*4*2);
}


Escena::~Escena()
{
	delete quadtree;
}

void Escena::mueveCoche(bool dir) {
	if (!finalP) {
		PuntoVector3D aux = { 1,0,0,1 };
		if (dir)
			hijos[0]->mt->traslada(&aux);
		else {
			aux = { -1,0,0,1 };
			hijos[0]->mt->traslada(&aux);
		}
		digievolucion = 0;
		compruebaColision();
	}
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

void Escena::dibuja()
{
	glColor3f(color->getX(), color->getY(), color->getZ());
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(this->mt->m);
	hijos[0]->dibuja();
	quadtree->draw();
	glPopMatrix();
}


int Escena::dameRandom(int min, int max) {
	return rand() % (max - (min - 1)) + min;
}

void Escena::creaBosque()
{
	PuntoVector3D auxP{0,0,0,0};
	TipoArbol aux;
	for (int i = -tamBosque ; i < tamBosque; i++)//x
	{
		for (int j = -tamBosque;  j < tamBosque; j++)//z
		{
			if (dameRandom(0, 1) == 1) {
				aux = static_cast<TipoArbol>(dameRandom(0,3));
				introduceObjeto(new Arbol(aux));
				auxP = { (GLfloat)i * 4,0,(GLfloat)j * 4,0 };
				hijos[numHijos - 1]->mt->traslada(&auxP);
				++numArboles;
			}
		}
	}
	std::cout << "NUMERO ARBOLES: " << numArboles<< "\n";
}

void Escena::compruebaColision()
{
	PuntoVector3D aux = hijos[0]->mt->damePos();

	for (int i = 1; i < numHijos; i++) {
		if (hijos[i]->activo &&
			aux.getX() >= hijos[i]->mt->damePos().getX() - colision
			&& aux.getX() <= hijos[i]->mt->damePos().getX() + colision
			&& aux.getZ() >= hijos[i]->mt->damePos().getZ() - colision
			&& aux.getZ() <= hijos[i]->mt->damePos().getZ() + colision) {
			hijos[i]->activo = false;
			++numArbRecog;
			std::cout << "CORTACESPED\n";
		}
	}
	if (numArboles == numArbRecog) finalP = true;
}
