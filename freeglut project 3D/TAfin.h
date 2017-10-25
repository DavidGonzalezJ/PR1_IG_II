#pragma once
#include <GL/freeglut.h>
#include "PuntoVector3D.h"

class TAfin
{
public:
	TAfin();
	~TAfin();
	GLfloat m[16];
	void traslada(PuntoVector3D* v);
	void rota(PuntoVector3D* a,int ang);
	void escala(PuntoVector3D* v);
	PuntoVector3D damePos();

protected:
	void postMultiplica(GLfloat* m1);
};

