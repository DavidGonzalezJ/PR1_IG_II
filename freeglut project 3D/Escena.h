#pragma once
#include "ObjetoCompuesto.h"
#include "Quadtree.h"
class Escena :
	public ObjetoCompuesto
{
public:
	Escena();
	virtual ~Escena();
	void mueveCoche(bool dir);
	void giraCoche(bool right);
	PuntoVector3D damePosCoche() { return hijos[0]->mt->damePos(); };
	bool finPartida() { return finalP; };
private:
//	Quadtree woodsQuadtree;

	int dameRandom(int min, int max);
	void creaBosque();
	void compruebaColision();
	int digievolucion = 0;
	int colision = 1;
	int numArboles, numArbRecog;
	bool finalP;
	Quadtree* quadtree;
};