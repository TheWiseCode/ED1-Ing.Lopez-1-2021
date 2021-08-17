// ---------------------------------------------------------------------------

#ifndef UPilaCoH
#define UPilaCoH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UColaS.h"

class PilaCo {
private:
	ColaS* k;

public:
	PilaCo();
	PilaCo(CSMemoria* m);
    bool vacia();
	void meter(int e);
	void sacar(int &e);
	int cima();
	string to_str();
};

#endif
