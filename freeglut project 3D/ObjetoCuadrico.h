#pragma once
#include "Objeto3D.h"
class ObjetoCuadrico :
	public Objeto3D
{
public:
	ObjetoCuadrico(){
		q = gluNewQuadric();
	};
	virtual ~ObjetoCuadrico();
	virtual void dibuja();
	void setColor(PuntoVector3D* color_){
		color = color_;
	}
protected:
	GLUquadricObj* q;
};


//CLASE ESFERA
class Esfera : 
	public ObjetoCuadrico
{
public:
	Esfera() : radius(1), slices(20), stacks(20){};
	Esfera(GLfloat radius, GLint slices, GLint stacks) : radius(radius), 
		slices(slices), stacks(stacks){};
	virtual ~Esfera();
	virtual void dibuja(){
		glColor3f(color->getX(), color->getY(), color->getZ());
		gluSphere(q,radius, slices, stacks);
	};

protected:
	GLfloat radius;
	GLint slices, stacks;
};

//CLASE CILINDRO
class Cilindro :
	public ObjetoCuadrico
{
public:
	Cilindro() : baseRadius(1),topRadius(1), height(1), slices(20),
		stacks(20){};
	Cilindro(GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks) :
		baseRadius(baseRadius), topRadius(topRadius), height(height), slices(slices), stacks(stacks){};

	virtual ~Cilindro();
	virtual void dibuja(){
		glColor3f(color->getX(), color->getY(), color->getZ());
		gluCylinder(q, baseRadius, topRadius, height, slices,
			stacks);
	};

protected:
	GLdouble baseRadius, topRadius, height;
	GLint slices, stacks;
};

//CLASE DISCO
class Disco :
	public ObjetoCuadrico
{
public:
	Disco() : outerRadius(1), innerRadius(1), slices(20), rings(20){};
	Disco(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint stacks) : 
		innerRadius(innerRadius), outerRadius(outerRadius),	slices(slices), rings(rings){};
	virtual ~Disco();
	virtual void dibuja(){
		glColor3f(color->getX(), color->getY(), color->getZ());
		gluDisk(q, innerRadius, outerRadius, slices, rings);
	};

protected:
	GLdouble innerRadius, outerRadius;
	GLint slices, rings;
};

//CLASE DISCO PARCIAL
class DiscoParcial :
	public ObjetoCuadrico
{
public:
	DiscoParcial() : outerRadius(1), innerRadius(1), slices(20), rings(20),startAngle(0), sweepAngle(90){};
	DiscoParcial(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint stacks,
		GLdouble startAngle, GLdouble sweepAngle) :
		innerRadius(innerRadius), outerRadius(outerRadius), slices(slices), rings(rings),
		startAngle(startAngle), sweepAngle(sweepAngle){};

	virtual ~DiscoParcial();
	
	virtual void dibuja(){
		glColor3f(color->getX(), color->getY(), color->getZ());
		gluPartialDisk(q, innerRadius, outerRadius, slices, rings,
			startAngle, sweepAngle);
	};

protected:
	GLdouble innerRadius, outerRadius, startAngle, sweepAngle;
	GLint slices, rings;
};