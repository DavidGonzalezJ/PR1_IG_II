#pragma once
#include "ObjetoCompuesto.h"
#include <GL/freeglut.h>
#include <vector>
class QuadtreeNode
{
public:
	QuadtreeNode(float x, float z, float s);
	~QuadtreeNode();

	void build(std::vector<ObjetoCompuesto*>const & trees); //Construye todos los nodos recursivamente
	int numberIntersected(std::vector<ObjetoCompuesto*>const & trees); //Devuelve el num de arboles dentro del nodo
	void addIntersectingToList(std::vector<ObjetoCompuesto*>const & trees); //Introduce en la lista del nodo actual todos los árboles que posee
	void draw(GLdouble top, GLdouble bot, GLdouble right, GLdouble left, ObjetoCompuesto* coche);

private:

	//Comprueba si unas coordenadas están dentro del nodo
	bool checkDiscRectangleIntersection(float coorX, float coorZ);
	//Comprueba si el nodo está dentro del frustrum
	bool checkQuadrilateralsIntersection(GLdouble top,GLdouble bot, GLdouble right, GLdouble left, ObjetoCompuesto* coche);

	QuadtreeNode *SWChild, *NWChild, *NEChild, *SEChild; //Nodos hijos
	float SWCornerX, SWCornerZ, size; //Esquina y tamaño del nodo
	std::vector<ObjetoCompuesto*> treesInNode;
	ObjetoCompuesto* coche;
};

