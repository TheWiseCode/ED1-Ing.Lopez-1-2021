// ---------------------------------------------------------------------------

#ifndef UColaLSH
#define UColaLSH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListaS.h"

using namespace std;

class ColaLS {
private:
	ListaS* L;

public:
	ColaLS();
	ColaLS(CSMemoria* m);
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};
#endif
