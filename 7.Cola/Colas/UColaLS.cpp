// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaLS.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaLS::ColaLS() {
	L = new ListaS();
}

ColaLS::ColaLS(CSMemoria* m) {
	L = new ListaS(m);
}

bool ColaLS::vacia() {
	return L->vacia();
}

void ColaLS::poner(int e) {
	L->inserta_ultimo(e);
}

void ColaLS::sacar(int &e) {
	if (!vacia()) {
		e = L->recupera(L->primero());
		L->suprime(L->primero());
	}
}

int ColaLS::primero() {
	if (!vacia())
		return L->recupera(L->primero());
}

string ColaLS::to_str() {
	string s = "<<";
	int e;
	ColaLS* aux = new ColaLS();
	while (!vacia()) {
		sacar(e);
		aux->poner(e);
		s += to_string(e);
		if (!vacia())
			s += ",";
	}
	while (!aux->vacia()) {
		aux->sacar(e);
		poner(e);
	}
	return s + "<<";
}
