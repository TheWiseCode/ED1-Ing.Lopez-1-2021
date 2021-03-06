// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaP::ColaP() {
	ini = fin = NULL;
}

bool ColaP::vacia() {
	return ini == NULL;
}

void ColaP::poner(int e) {
	NodoC* aux = new NodoC();
	if (aux != NULL) {
		aux->elemento = e;
		aux->sig = NULL;
		if (vacia()) {
			ini = fin = aux;
		}
		else {
			fin->sig = aux;
			fin = aux;
		}
	}
}

void ColaP::sacar(int &e) {
	if (!vacia()) {
		e = ini->elemento;
		NodoC* x = ini;
		if (ini == fin)
			ini = fin = NULL;
		else
			ini = ini->sig;
		delete(x);
	}
}

int ColaP::primero() {
	if (!vacia())
		return ini->elemento;
}

string ColaP::to_str() {
	string s = "<<";
	int e;
	ColaP* aux = new ColaP();
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

int ColaP::ultimo() {
	if (!vacia())
		return fin->elemento;
}

void ColaP::poner_frente(int e) {
	NodoC* aux = new NodoC();
	if (aux != NULL) {
		aux->elemento = e;
		aux->sig = NULL;
		if (vacia()) {
			ini = fin = aux;
		}
		else {
			aux->sig = ini;
			ini = aux;
		}
	}
}

void ColaP::sacar_final(int &e) {
	if (!vacia()) {
		e = fin->elemento;
		NodoC* x = ini;
		if (ini == fin)
			ini = fin = NULL;
		else {
			NodoC* aux = ini;
			NodoC* ant = NULL;
			while (aux != fin) {
				ant = aux;
				aux = aux->sig;
			}
			ant->sig = NULL;
			fin = ant;
		}
		delete(x);
	}
}
