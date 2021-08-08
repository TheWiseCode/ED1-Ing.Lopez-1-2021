// ---------------------------------------------------------------------------

#ifndef UDicola1H
#define UDicola1H
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UColaP.h"

using namespace std;

// Esta dicola usa una cola k como atributo

class Dicola1 {
private:
	ColaP* k;

public:
	Dicola1();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();

	int ultimo();
	void poner_frente(int e);
	void sacar_final(int &e);
};
#endif
