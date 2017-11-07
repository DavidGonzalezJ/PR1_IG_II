#pragma once
class QuadtreeNode
{
public:
	QuadtreeNode(float x, float z, float s);
	~QuadtreeNode();

	void build();
	int numberIntersected();
	void addIntersectingToList();
	void draw(float x1, float z1,
		float x2, float z2,
		float x3, float z3,
		float x4, float z4);
	void checkDiscRectangleIntersection(float x, float z,
		float difX, float difZ,
		float x2, float z2, float radio);

	void checkQuadrilateralsIntersection(float x1, float z1,
		float x2, float z2,
		float x3, float z3,
		float x4, float z4,
		float X, float SWCornerZ, float SWCornerX, float difSWCornerZ,
		float sumaSWCornerX, float dif2SWCornerZ, float sum2SWCornerX, float SWCornerZ2);

	QuadtreeNode *SWChild, *NWChild, *NEChild, *SEChild;
	float SWCornerX, SWCornerZ, size;

	/*
Atributos: (coordenadas de la esquina
	inferior izquierda), size(tamaño del cuadrado), asteroidList
	(lista de asteroides que intersecan con el nodo; solo para nodos
	hoja con 1 asteroide, a lo más), 
	
	
	
	
	QuadtreeNode *SWChild,	*NWChild, *NEChild, *SEChild(punteros a los nodos hijo; no
	nulos solo para nodos internos)
	– Operaciones :
		   • build() : construye recursivamente el nodo
			   • numberAsteroidsIntersected() : recorre todos los asteroides y,
			   por cada uno, averigua si interseca con el cuadrado asociado al nodo
			   • addIntersectingAsteroidsToList() : construye una lista con
			   todos los asteroides que intersecan con el nodo
			   • drawAsteroids() : dibuja recursivamente los asteroides contenidos
			   en un nodo
*/
};

