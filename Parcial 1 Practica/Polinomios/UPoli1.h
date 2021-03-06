// ---------------------------------------------------------------------------

#ifndef UPoli1H
#define UPoli1H

#include "UListaP.h"

// ---------------------------------------------------------------------------
/*
 Polinomio que guarda el grado maximo al inicio en una lista K
 9x3 + 5x1 + 4x7

 K = [7,  9, 3,5, 1, 4, 7]
 */
class Poli1 {
private:
	ListaP *k;

public:
	Poli1() {
		k = new ListaP();
	}

	string mostrar() {
		return k->to_str();
	}

	void poner_termino(int coef, int exp);

};
#endif
