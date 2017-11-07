#include "Quadtree.h"


Quadtree::Quadtree()
{
}


Quadtree::~Quadtree()
{
	delete header;
}

void Quadtree::initialize(float x, float z, float s){
	header = new QuadtreeNode(x, z, s);
	header->build();
};

void Quadtree::draw(float x1, float z1,
	float x2, float z2,
	float x3, float z3,
	float x4, float z4){
	
	header->draw(x1, z1, x2, z2,
		x3, z3, x4, z4);

};
