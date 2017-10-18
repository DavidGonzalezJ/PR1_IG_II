#pragma once
#include "TAfin.h"
class Objeto3D
{
public:

	Objeto3D()
	{
		mt = new TAfin();
		color = new PuntoVector3D(0, 0, 0.5, 0);
	}

	virtual ~Objeto3D()
	{
	}
	virtual void dibuja() = 0;
	TAfin* mt;
	PuntoVector3D* color;
};

