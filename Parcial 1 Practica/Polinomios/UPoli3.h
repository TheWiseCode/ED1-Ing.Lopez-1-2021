// ---------------------------------------------------------------------------

#ifndef UPoli3H
#define UPoli3H
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListaP.h"

using namespace std;

class Poli3 {
private:
	ListaP*k;

	NodoL* buscar_exponente(int exp);
	NodoL* buscar_termino_n(int i);

public:
	Poli3();
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
