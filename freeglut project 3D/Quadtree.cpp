#include "Quadtree.h"


Quadtree::Quadtree(Objeto3D** objetosEscena, ObjetoCompuesto* coche, int numHijos):coche(coche)
{
	//Relleno el vector de referencias a los árboles
	int i = 1;
	while (i < numHijos) {
		trees.push_back(static_cast<ObjetoCompuesto*>(objetosEscena[i]));
		i++;
	}
}


Quadtree::~Quadtree()
{
	delete header;
}

void Quadtree::initialize(float x, float z, float s){
	header = new QuadtreeNode(x, z, s);
	header->build(trees);
};

void Quadtree::draw(){
	header->draw(100,-100,100,-100,coche);
};
