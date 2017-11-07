#pragma once
#include "QuadtreeNode.h"

class Quadtree
{
public:
	Quadtree(Objeto3D** objetosEscena, ObjetoCompuesto* coche, int numHijos); //Le creo un vector de referencias a los árboles del bosque (a partir del vector de la escena) para poder operar con ellos
	~Quadtree();
	void initialize(float x, float z, float s);
	void draw();//Le paso directamente los valores del frustum
private:
	QuadtreeNode *header;
	std::vector<ObjetoCompuesto*> trees;
	ObjetoCompuesto* coche;
};

