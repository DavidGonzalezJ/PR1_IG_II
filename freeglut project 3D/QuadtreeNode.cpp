#include "QuadtreeNode.h"
#define umbral 10
#define tamBosque 40

QuadtreeNode::QuadtreeNode(float x, float z, float s) : SWCornerX(x), SWCornerZ(z), size(s)
{
}


QuadtreeNode::~QuadtreeNode()
{
}
void QuadtreeNode::build(std::vector<ObjetoCompuesto*>const & trees){
	if (this->numberIntersected(trees) <= umbral)
		this->addIntersectingToList(trees);
	else {
		SWChild = new QuadtreeNode(SWCornerX, SWCornerZ, size / 2.0);
		NWChild = new QuadtreeNode(SWCornerX, SWCornerZ - size / 2.0,
			size / 2.0);
		NEChild = new QuadtreeNode(SWCornerX + size / 2.0,
			SWCornerZ - size / 2.0, size / 2.0);
		SEChild = new QuadtreeNode(SWCornerX + size / 2.0, SWCornerZ,
			size / 2.0);
		SWChild->build(trees); NWChild->build(trees);
		NEChild->build(trees); SEChild->build(trees);
	}
}


int QuadtreeNode::numberIntersected(std::vector<ObjetoCompuesto*>const & trees){
	int numVal = 0;
	for (int j = 0; j < tamBosque; j++){
		for (int i = 0; i < tamBosque; i++){
			if (trees[i][j].activo){
				if (checkDiscRectangleIntersection(trees[i][j].mt->damePos().getX(),
					trees[i][j].mt->damePos().getZ()))
					numVal++;
			}
		}
	}
	return numVal;
}


void QuadtreeNode::addIntersectingToList(std::vector<ObjetoCompuesto*>const & trees){
	for (int j = 0; j < tamBosque; j++){
		for (int i = 0; i < tamBosque; i++){
			if (trees[i][j].activo){
				if (checkDiscRectangleIntersection(trees[i][j].mt->damePos().getX(),
					trees[i][j].mt->damePos().getZ()))
					treesInNode.push_back(&trees[i][j]);
			}
		}
	}
}

bool QuadtreeNode::checkDiscRectangleIntersection(float coorX, float coorZ){
	return coorX <= SWCornerX && coorZ <= SWCornerZ &&
		coorX > SWCornerX - size && coorZ > SWCornerZ -size;
}

void QuadtreeNode::checkQuadrilateralsIntersection(
	float x1, float z1,
	float x2, float z2,
	float x3, float z3,
	float x4, float z4,
	float X, float SWCornerZ, float SWCornerX, float difSWCornerZ,
	float sumaSWCornerX, float dif2SWCornerZ, float sum2SWCornerX, float SWCornerZ2){




}

void QuadtreeNode::draw(float x1, float z1,float x2, float z2,float x3, float z3,float x4, float z4){
//If the square does not intersect the frustum do nothing.
	if (checkQuadrilateralsIntersection(x1, z1, x2, z2, x3, z3, x4, z4,

		SWCornerX,
		SWCornerZ, 
		SWCornerX, 
		SWCornerZ - size,
		SWCornerX + size,
		SWCornerZ - size,
		SWCornerX + size, 
		SWCornerZ)) {

		if (SWChild == nullptr) { //Square is leaf.
			//Draw all the trees of this node
			for (int i = 0; i < treesInNode.size(); i++)
				treesInNode[i]->dibuja();
		}
		else {
			SWChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
			NWChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
			NEChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
			SEChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
		}
	}
}