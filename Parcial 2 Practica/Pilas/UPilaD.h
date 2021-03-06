// ---------------------------------------------------------------------------

#ifndef UPilaDH
#define UPilaDH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UColaV3.h"

using namespace std;

// Pila que utiliza una dicola con vector circular

class PilaD {
private:
	ColaV3* k;

public:
	PilaD();
	bool vacia();
	void meter(int e);
	void sacar(int& e);
	int cima();
	string to_str();
};

#endif
