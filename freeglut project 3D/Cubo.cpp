#include "Cubo.h"
Cubo::Cubo(){
	numeroVertices = 8;
	vertice = new PuntoVector3D*[numeroVertices];
	numeroNormales = 8;
	normal = new PuntoVector3D*[numeroNormales];
	numeroCaras = 6;
	cara = new Cara*[numeroCaras];
	//modo = false;

	// Vértices  
	vertice[0] = new PuntoVector3D(-0.5f, 0.5f, 0.5f, 1);
	vertice[1] = new PuntoVector3D(-0.5f, -0.5f, 0.5f, 1);
	vertice[2] = new PuntoVector3D(0.5f, -0.5f, 0.5f, 1);
	vertice[3] = new PuntoVector3D(0.5f, 0.5f, 0.5f, 1);
	vertice[4] = new PuntoVector3D(-0.5f, 0.5f, -0.5f, 1);
	vertice[5] = new PuntoVector3D(-0.5f, -0.5f,-0.5f, 1);
	vertice[6] = new PuntoVector3D(0.5f, -0.5f, -0.5f, 1);
	vertice[7] = new PuntoVector3D(0.5f, 0.5f, -0.5f, 1);

	// Normales  
	for (int i = 0; i < 8; i++)
	{

	}

	// Caras
	VerticeNormal** aVN = new VerticeNormal*[3];
	aVN[0] = new VerticeNormal(1, 0);
	aVN[1] = new VerticeNormal(2, 0);
	aVN[2] = new VerticeNormal(3, 0);
	cara[0] = new Cara(3, aVN);

	aVN = new VerticeNormal*[3];
	aVN[0] = new VerticeNormal(0, 1);
	aVN[1] = new VerticeNormal(2, 1);
	aVN[2] = new VerticeNormal(1, 1);
	cara[1] = new Cara(3, aVN);

	aVN = new VerticeNormal*[3];
	aVN[0] = new VerticeNormal(0, 2);
	aVN[1] = new VerticeNormal(3, 2);
	aVN[2] = new VerticeNormal(2, 2);
	cara[2] = new Cara(3, aVN);

	aVN = new VerticeNormal*[3];
	aVN[0] = new VerticeNormal(0, 3);
	aVN[1] = new VerticeNormal(1, 3);
	aVN[2] = new VerticeNormal(3, 3);
	cara[3] = new Cara(3, aVN);
}
Cubo::~Cubo()
{
}

void Cubo::dibuja(){
	if (solido){
		glColor3f(color->getX(), color->getY(), color->getZ());
		glutSolidCube(size);
	}
	else{ 
		glColor3f(color->getX(), color->getY(), color->getZ());
		glutWireCube(size);
	}
}