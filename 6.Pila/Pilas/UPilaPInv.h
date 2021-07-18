// ---------------------------------------------------------------------------

#ifndef UPilaPInvH
#define UPilaPInvH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoPInv {
	int elemento;
	NodoPInv* sig;
};

class PilaPInv {
private:
	NodoPInv* ptr;
    NodoPInv* fin();

public:
	PilaPInv();
	bool vacia();
	void meter(int e);
	void sacar(int& e);
	int cima();
	string to_str();
};
#endif
