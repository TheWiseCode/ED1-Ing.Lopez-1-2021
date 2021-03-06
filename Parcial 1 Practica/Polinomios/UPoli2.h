//---------------------------------------------------------------------------

#ifndef UPoli2H
#define UPoli2H
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListaP.h"

using namespace std;

class Poli2 {
private:
	ListaP*k;

	NodoL* buscar_exponente(int exp);
	NodoL* buscar_termino_n(int i);

public:
	Poli2();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	float evaluar(float x);
	void derivada();
	void mostrar();

};
#endif
