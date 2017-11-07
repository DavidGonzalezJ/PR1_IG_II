#include "QuadtreeNode.h"
#define umbral 10
#define tamBosque 40

QuadtreeNode::QuadtreeNode(float x, float z, float s) : SWCornerX(x), SWCornerZ(z), size(s)
{
	SWChild = NWChild = SEChild = NEChild = nullptr;
}


QuadtreeNode::~QuadtreeNode()
{
}
void QuadtreeNode::build(std::vector<ObjetoCompuesto*>const & trees){
	if (this->numberIntersected(trees) <= umbral)
		this->addIntersectingToList(trees);
	else {
		SWChild = new QuadtreeNode(SWCornerX, SWCornerZ, size / 2.0);
		NWChild = new QuadtreeNode(SWCornerX - size / 2.0, SWCornerZ,
			size / 2.0);
		NEChild = new QuadtreeNode(SWCornerX - size / 2.0,
			SWCornerZ - size / 2.0, size / 2.0);
		SEChild = new QuadtreeNode(SWCornerX, SWCornerZ - size / 2.0,
			size / 2.0);
		SWChild->build(trees); NWChild->build(trees);
		NEChild->build(trees); SEChild->build(trees);
	}
}


int QuadtreeNode::numberIntersected(std::vector<ObjetoCompuesto*>const & trees){
	int numVal = 0;
	for (int j = 0; j < trees.size(); j++){
			if (trees[j]->activo){
				if (checkDiscRectangleIntersection(trees[j]->mt->damePos().getX(),
					trees[j]->mt->damePos().getZ()))
					numVal++;
			}
		}
	return numVal;
}


void QuadtreeNode::addIntersectingToList(std::vector<ObjetoCompuesto*>const & trees){
	for (int j = 0; j < trees.size(); j++){
		if (trees[j]->activo){
				if (checkDiscRectangleIntersection(trees[j]->mt->damePos().getX(),
					trees[j]->mt->damePos().getZ()))
					treesInNode.push_back(trees[j]);
		}
	}
}

bool QuadtreeNode::checkDiscRectangleIntersection(float coorX, float coorZ){
	return coorX <= SWCornerX && coorZ <= SWCornerZ &&
		coorX > SWCornerX - size && coorZ > SWCornerZ -size;
}

//Para las 4 esquinas del nodo
struct esquina {
	GLdouble posX, posZ;
};

bool QuadtreeNode::checkQuadrilateralsIntersection(GLdouble top, GLdouble bot, GLdouble right, GLdouble left, ObjetoCompuesto* coche){
	//Calculamos el centro del nodo
	esquina esqSW, esqSE, esqNE, esqNW, centro;
	esqSW.posX = SWCornerX; esqSW.posZ = SWCornerZ;
	esqNW.posX = SWCornerX - size; esqNW.posZ = SWCornerZ;
	esqNE.posX = SWCornerX - size; esqNE.posZ = SWCornerZ - size;
	esqSE.posX = SWCornerX; esqSE.posZ = SWCornerZ - size;
	centro.posX = SWCornerX - size / 2.0; centro.posZ = SWCornerZ - size / 2.0;
	if(((esqSW.posX > coche->mt->damePos().getX() - top && esqSW.posX < coche->mt->damePos().getX() - bot &&
		esqSW.posZ < coche->mt->damePos().getZ() + right && esqSW.posZ > coche->mt->damePos().getZ() + left)
		|| (esqNW.posX > coche->mt->damePos().getX() - top && esqNW.posX < coche->mt->damePos().getX() - bot &&
		esqNW.posZ < coche->mt->damePos().getZ() + right && esqNW.posZ > coche->mt->damePos().getZ() + left)
		|| (esqSE.posX > coche->mt->damePos().getX() - top && esqSE.posX < coche->mt->damePos().getX() - bot &&
		esqSE.posZ < coche->mt->damePos().getZ() + right && esqSE.posZ > coche->mt->damePos().getZ() + left)
		|| (esqNE.posX > coche->mt->damePos().getX() - top && esqNE.posX < coche->mt->damePos().getX() - bot &&
		esqNE.posZ < coche->mt->damePos().getZ() + right && esqNE.posZ > coche->mt->damePos().getZ() + left)
		|| (centro.posX > coche->mt->damePos().getX() - top && centro.posX < coche->mt->damePos().getX() - bot &&
			centro.posZ < coche->mt->damePos().getZ() + right && centro.posZ > coche->mt->damePos().getZ() + left))

		|| ((esqSW.posX < coche->mt->damePos().getX() - top && esqSW.posX > coche->mt->damePos().getX() - bot &&
		esqSW.posZ > coche->mt->damePos().getZ() + right && esqSW.posZ < coche->mt->damePos().getZ() + left)
		|| (esqNW.posX < coche->mt->damePos().getX() - top && esqNW.posX > coche->mt->damePos().getX() - bot &&
		esqNW.posZ > coche->mt->damePos().getZ() + right && esqNW.posZ < coche->mt->damePos().getZ() + left)
		|| (esqSE.posX < coche->mt->damePos().getX() - top && esqSE.posX > coche->mt->damePos().getX() - bot &&
		esqSE.posZ > coche->mt->damePos().getZ() + right && esqSE.posZ < coche->mt->damePos().getZ() + left)
		|| (esqNE.posX < coche->mt->damePos().getX() - top && esqNE.posX > coche->mt->damePos().getX() - bot &&
		esqNE.posZ > coche->mt->damePos().getZ() + right && esqNE.posZ < coche->mt->damePos().getZ() + left)
		|| (centro.posX < coche->mt->damePos().getX() - top && centro.posX > coche->mt->damePos().getX() - bot &&
			centro.posZ > coche->mt->damePos().getZ() + right && centro.posZ < coche->mt->damePos().getZ() + left)))
		return true;
	else return false;
	//return true;
}

void QuadtreeNode::draw(GLdouble top, GLdouble bot, GLdouble right, GLdouble left, ObjetoCompuesto* coche) {
	//If the square does not intersect the frustum do nothing.
	if (checkQuadrilateralsIntersection(top, bot, right, left, coche)) {

		if (SWChild == nullptr) { //Square is leaf.
			//Draw all the trees of this node
			for (int i = 0; i < treesInNode.size(); i++)
				treesInNode[i]->dibuja();
		}
		else {
			SWChild->draw(top, bot, right, left, coche);
			NWChild->draw(top, bot, right, left, coche);
			NEChild->draw(top, bot, right, left, coche);
			SEChild->draw(top, bot, right, left, coche);
		}
	}
}