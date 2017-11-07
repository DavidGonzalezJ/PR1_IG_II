#include "QuadtreeNode.h"
#define umbral 5

QuadtreeNode::QuadtreeNode(float x, float z, float s) : SWCornerX(x), SWCornerZ(z), size(s)
{
}


QuadtreeNode::~QuadtreeNode()
{
}
void QuadtreeNode::build(){
	if (this->numberIntersected() <= umbral)
		this->addIntersectingToList();
	else {
		SWChild = new QuadtreeNode(SWCornerX, SWCornerZ, size / 2.0);
		NWChild = new QuadtreeNode(SWCornerX, SWCornerZ - size / 2.0,
			size / 2.0);
		NEChild = new QuadtreeNode(SWCornerX + size / 2.0,
			SWCornerZ - size / 2.0, size / 2.0);
		SEChild = new QuadtreeNode(SWCornerX + size / 2.0, SWCornerZ,
			size / 2.0);
		SWChild->build(); NWChild->build();
		NEChild->build(); SEChild->build();
	}
}


int QuadtreeNode::numberIntersected(){
	int numVal = 0;
	for (int j = 0; j < COLUMNS; j++){
		for (int i = 0; i < ROWS; i++){
			if (arrayAsteroids[i][j].getRadius()>0.0){
				if (checkDiscRectangleIntersection(
					SWCornerX, SWCornerZ,
					SWCornerX + size, SWCornerZ - size,
					arrayAsteroids[i][j].getCenterX(),
					arrayAsteroids[i][j].getCenterZ(),
					arrayAsteroids[i][j].getRadius())){
					numVal++;
				}
			}
		}
	}
	return numVal;}

void QuadtreeNode::addIntersectingToList(){
	for (int j = 0; j < COLUMNS; j++){
		for (int i = 0; i < ROWS; i++){
			if (arrayAsteroids[i][j].getRadius() > 0.0){
				if (checkDiscRectangleIntersection(
					SWCornerX, SWCornerZ,
					SWCornerX + size, SWCornerZ - size,
					arrayAsteroids[i][j].getCenterX(),
					arrayAsteroids[i][j].getCenterZ(),
					arrayAsteroids[i][j].getRadius())){
					asteroidList.push_back(
						Asteroid(arrayAsteroids[i][j]));
				}
			}
		}
	}
}

void QuadtreeNode::checkDiscRectangleIntersection(
	float x, float z,
	float difX, float difZ,
	float x2,float z2,float radio){

}
void QuadtreeNode::checkQuadrilateralsIntersection(
	float x1, float z1,
	float x2, float z2,
	float x3, float z3,
	float x4, float z4,
	float X, float SWCornerZ, float SWCornerX, float difSWCornerZ,
	float sumaSWCornerX, float dif2SWCornerZ, float sum2SWCornerX, float SWCornerZ2){

}

void QuadtreeNode::draw(float x1, float z1,
	float x2, float z2,
	float x3, float z3,
	float x4, float z4){
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
			//Draw all the asteroids in asteroidList.

		}
		else {
			SWChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
			NWChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
			NEChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
			SEChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
		}
	}
}