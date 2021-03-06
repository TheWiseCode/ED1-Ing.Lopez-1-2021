// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicola1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Dicola1::Dicola1() {
	k = new ColaP();
}

bool Dicola1::vacia() {
	return k->vacia();
}

void Dicola1::poner(int e) {
	k->poner(e);
}

void Dicola1::sacar(int &e) {
	k->sacar(e);
}

int Dicola1::primero() {
	return k->primero();
}

string Dicola1::to_str() {
	string s = "<<";
	int e;
	Dicola1* aux = new Dicola1();
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

int Dicola1::ultimo() {
	if (!vacia()) {
		Dicola1* aux = new Dicola1();
		int c = 0;
        int e;
		while (!vacia()) {
			sacar(e);
			aux->poner(e);
			c++;
		}
		for (int i = 0; i < c; i++) {
			int x;
			aux->sacar(x);
			poner(x);
		}
        return e;
	}
}

void Dicola1::poner_frente(int e) {
	Dicola1* aux = new Dicola1();
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
	}
	poner(e);
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		poner(e);
	}
}

void Dicola1::sacar_final(int &e) {
	if (!vacia()) {
		Dicola1* aux = new Dicola1();
		int c = 0;
		while (!vacia()) {
			sacar(e);
			aux->poner(e);
			c++;
		}
		for (int i = 0; i < c - 1; i++) {
			int x;
			aux->sacar(x);
			poner(x);
		}
	}
}
