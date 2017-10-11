#pragma once
#include "TAfin.h"
class Objeto3D
{
public:

	Objeto3D()
	{
	}

	virtual ~Objeto3D()
	{
	}
	virtual void dibuja() = 0;
	TAfin* mt;
	PuntoVector3D* color;
};

