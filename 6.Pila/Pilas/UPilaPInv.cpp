// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPilaPInv.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaPInv::PilaPInv() {
	ptr = NULL;
}

bool PilaPInv::vacia() {
	return ptr == NULL;
}

NodoPInv* PilaPInv::fin() {
	NodoPInv* aux = ptr;
	while (aux->sig != NULL)
		aux = aux->sig;
	return aux;
}

void PilaPInv::meter(int e) {
	NodoPInv* nuevo = new NodoPInv();
	nuevo->elemento = e;
	nuevo->sig = NULL;
	if (vacia()) {
		ptr = nuevo;
	}
	else {
		NodoPInv* final = fin();
		final->sig = nuevo;
	}
}

void PilaPInv::sacar(int& e) {
	if (!vacia()) {
		NodoPInv* final = fin();
		e = final->elemento;
		if (ptr == final) {
			ptr = NULL;
		}
		else {
			NodoPInv* ant = ptr;
			while (ant->sig != final)
				ant = ant->sig;
			ant->sig = NULL;
		}
		delete(final);

	}
}

int PilaPInv::cima() {
	if (!vacia()) {
		NodoPInv* final = fin();
		return final->elemento;
	}
}

string PilaPInv::to_str() {
	string r = "";
	PilaPInv* aux = new PilaPInv();
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
