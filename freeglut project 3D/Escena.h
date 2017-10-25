#pragma once
#include "ObjetoCompuesto.h"
class Escena :
	public ObjetoCompuesto
{
public:
	Escena();
	virtual ~Escena();
	void mueveCoche(bool dir);
	void giraCoche(bool right);
private:
	int dameRandom(int min, int max);
	void creaBosque();
	void compruebaColision();
	int digievolucion = 0;
	int colision = 1;
};

