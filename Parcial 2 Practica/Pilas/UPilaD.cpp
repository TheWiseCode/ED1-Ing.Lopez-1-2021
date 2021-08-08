// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPilaD.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaD::PilaD() {
	k = new ColaV3();
}

bool PilaD::vacia() {
	return k->vacia();
}

void PilaD::meter(int e) {
	k->poner(e);
}

void PilaD::sacar(int& e) {
	k->sacar_final(e);
}

int PilaD::cima() {
	return k->ultimo();
}

string PilaD::to_str() {
	string r = "";
	PilaD* aux = new PilaD();
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
	r += "+---+\n";
	return r;
}
