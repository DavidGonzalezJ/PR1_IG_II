#pragma once
#include "ObjetoCompuesto.h"
enum TipoArbol {Abeto, Roble, Pino, Alamo};
class Arbol :
	public ObjetoCompuesto
{
public:
	Arbol(TipoArbol tipo);
	virtual ~Arbol();
};

