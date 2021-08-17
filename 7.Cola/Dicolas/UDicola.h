// ---------------------------------------------------------------------------

#ifndef UDicolaH
#define UDicolaH
// ---------------------------------------------------------------------------
#include <iostream>
#include "UMemoria.h"
#include <string>
using namespace std;

class Dicola {
private:
	CSMemoria* m;
	int ini, fin;

public:
	Dicola();
	Dicola(CSMemoria* mem);
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	void poner_frente(int e);
	void sacar_final(int &e);
	int ultimo();
	string to_str();
};
#endif
