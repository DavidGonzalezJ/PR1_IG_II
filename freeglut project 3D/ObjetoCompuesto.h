#pragma once
#include "Objeto3D.h"
class ObjetoCompuesto :
	public Objeto3D
{
public:
	ObjetoCompuesto();
	virtual ~ObjetoCompuesto();
	virtual void dibuja();
	void introduceObjeto(Objeto3D* hijo){
		hijos[numHijos] = hijo;
		numHijos++;
	}
protected:
	int numHijos;
	Objeto3D** hijos;
};