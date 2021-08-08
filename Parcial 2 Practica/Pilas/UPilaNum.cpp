// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPilaNum.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaNum::PilaNum() {
	datos = 0;
}

bool PilaNum::vacia() {
	return datos == 0;
}

void PilaNum::meter(int e) {
	if (e > 0 && e < 10)
		datos = datos * 10 + e;
	else
		cout << "Solo numeros del 1 al 9\n";
}

void PilaNum::sacar(int& e) {
	if (!vacia()) {
		e = datos % 10;
		datos = datos / 10;
	}
}

int PilaNum::cima() {
	if (!vacia())
		return datos % 10;
}

string PilaNum::to_str() {
	string r = "";
	PilaNum* aux = new PilaNum();
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
