// ---------------------------------------------------------------------------

#ifndef UColaPiH
#define UColaPiH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UPilaL.h"

using namespace std;

class ColaPi {
private:
	PilaL* p;

public:
	ColaPi();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};
#endif
