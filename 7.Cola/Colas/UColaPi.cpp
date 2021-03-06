// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaPi.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaPi::ColaPi() {
	p = new PilaL();
}

bool ColaPi::vacia() {
	return p->vacia();
}

void ColaPi::poner(int e) {
	p->meter(e);
}

void ColaPi::sacar(int &e) {
	if (!vacia()) {
		PilaL* aux = new PilaL();
		while (!p->vacia()) {
			int x;
			p->sacar(x);
			aux->meter(x);
		}
		aux->sacar(e);
		while (!aux->vacia()) {
			int x;
			aux->sacar(x);
			p->meter(x);
		}
	}
}

int ColaPi::primero() {
	if (!vacia()) {
		PilaL* aux = new PilaL();
		while (!p->vacia()) {
			int x;
			p->sacar(x);
			aux->meter(x);
		}
        int e = aux->cima();
		while (!aux->vacia()) {
			int x;
			aux->sacar(x);
			p->meter(x);
		}
        return e;
	}
}

string ColaPi::to_str() {
	string s = "<<";
	int e;
	ColaPi* aux = new ColaPi();
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
