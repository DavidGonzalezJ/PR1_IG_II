#include "ObjetoCompuesto.h"


ObjetoCompuesto::ObjetoCompuesto()
{
	hijos = new Objeto3D*[1000000];
	numHijos = 0;
}


ObjetoCompuesto::~ObjetoCompuesto()
{
}

void ObjetoCompuesto::dibuja() {
	if (activo) {
		glColor3f(color->getX(), color->getY(), color->getZ());
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glMultMatrixf(this->mt->m);
		for (int i = 0; i < numHijos; i++)
			hijos[i]->dibuja();
		glPopMatrix();
	}
}
void ObjetoCompuesto::introduceObjeto(Objeto3D* hijo){
	hijos[numHijos] = hijo;
	numHijos++;
}