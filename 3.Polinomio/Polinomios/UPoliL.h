// ---------------------------------------------------------------------------

#ifndef UPoliLH
#define UPoliLH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListaP.h"

using namespace std;

class PoliL {
private:
	ListaP* pol;

	NodoL* buscar_exponente(int exp);
	NodoL* buscar_termino_n(int i);

public:
	PoliL();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
    string to_str();

};
#endif
