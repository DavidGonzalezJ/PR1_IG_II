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

bool QuadtreeNode::checkQuadrilateralsIntersection(GLdouble top, GLdouble bot, GLdouble right, GLdouble left, ObjetoCompuesto* coche){
	//Calculamos el centro del nodo
	/*GLdouble centroX, centroZ;
	centroX = SWCornerX - size / 2;
	centroZ = SWCornerZ - size / 2;
	if(centroX > coche->mt->damePos().getX() - top && centroX < coche->mt->damePos().getX() - bot &&
		centroZ < coche->mt->damePos().getZ() + right && centroZ > coche->mt->damePos().getZ() + left)
		return true;
	else return false;*/
	return true;
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