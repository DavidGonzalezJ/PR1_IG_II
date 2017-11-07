#pragma once
#include "ObjetoCompuesto.h"
#include <vector>
class QuadtreeNode
{
public:
	QuadtreeNode(float x, float z, float s);
	~QuadtreeNode();

	void build(std::vector<ObjetoCompuesto*>const & trees); //Construye todos los nodos recursivamente
	int numberIntersected(std::vector<ObjetoCompuesto*>const & trees); //Devuelve el num de arboles dentro del nodo
	void addIntersectingToList(std::vector<ObjetoCompuesto*>const & trees); //Introduce en la lista del nodo actual todos los �rboles que posee
	void draw(float x1, float z1,
		float x2, float z2,
		float x3, float z3,
		float x4, float z4);

private:

	//Comprueba si unas coordenadas est�n dentro del nodo
	bool checkDiscRectangleIntersection(float coorX, float coorZ);
	//Comprueba si el nodo est� dentro del frustrum
	void checkQuadrilateralsIntersection(float x1, float z1,
		float x2, float z2,
		float x3, float z3,
		float x4, float z4,
		float X, float SWCornerZ, float SWCornerX, float difSWCornerZ,
		float sumaSWCornerX, float dif2SWCornerZ, float sum2SWCornerX, float SWCornerZ2);

	QuadtreeNode *SWChild, *NWChild, *NEChild, *SEChild; //Nodos hijos
	float SWCornerX, SWCornerZ, size; //Esquina y tama�o del nodo
	std::vector<ObjetoCompuesto*> treesInNode;
};

