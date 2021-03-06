// ---------------------------------------------------------------------------

#ifndef UConjuntoLH
#define UConjuntoLH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "UListaV.h"

using namespace std;

class ConjuntoL {
private:
	ListaV* elem;
	// ListaP* elem;

public:
	ConjuntoL();
	bool vacio();
	bool pertenece(int e);
	void inserta(int e);
	void suprime(int e);
	int cardinal(); // numero elementos
	int ordinal(int e); // posicion de e
	int muestrea();
	string to_str();
};
#endif
