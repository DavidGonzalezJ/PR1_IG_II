#pragma once
#include "Objeto3D.h"
class ObjetoCuadrico :
	public Objeto3D
{
public:
	ObjetoCuadrico(){
		q = gluNewQuadric();
	};
	virtual ~ObjetoCuadrico(){
		delete q;
	};
	virtual void dibuja(){};
	void setColor(PuntoVector3D* color_){
		color = color_;
	}
protected:
	GLUquadricObj* q;
};