#pragma once
#include "QuadtreeNode.h"

class Quadtree
{
public:
	Quadtree(Objeto3D** objetosEscena); //Le creo un vector de referencias a los árboles del bosque (a partir del vector de la escena) para poder operar con ellos
	~Quadtree();
	void initialize(float x, float z, float s);
	void draw(float x1, float z1,
		float x2, float z2,
		float x3, float z3,
		float x4, float z4);
private:
	QuadtreeNode *header;
	std::vector<ObjetoCompuesto*> trees;
};

