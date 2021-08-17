// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPilaCo.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaCo::PilaCo() {
	k = new ColaS();
}

PilaCo::PilaCo(CSMemoria* m) {
	k = new ColaS(m);
}

bool PilaCo::vacia() {
	return k->vacia();
}

void PilaCo::meter(int e) {
	k->poner(e);
}

void PilaCo::sacar(int &e) {
	if (!vacia()) {
		ColaS* aux = new ColaS();
		int c = 0;
		while (!k->vacia()) {
			k->sacar(e);
			aux->poner(e);
			c++;
		}
		for (int i = 0; i < c - 1; i++) {
			int x;
			aux->sacar(x);
			k->poner(x);
		}
	}
}

int PilaCo::cima() {
	if (!vacia()) {
		ColaS* aux = new ColaS();
		int c = 0;
		int e;
		while (!k->vacia()) {
			k->sacar(e);
			aux->poner(e);
			c++;
		}
		for (int i = 0; i < c; i++) {
			int x;
			aux->sacar(x);
			k->poner(x);
		}
		return e;
	}
}

string PilaCo::to_str() {
	string r = "";
	PilaCo* aux = new PilaCo();
	while (!vacia()) {
		int e;
		sacar(e);
		r += "| " + to_string(e) + " |\n";
		aux->meter(e);
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
	r += "+----+\n";
	return r;
}
