// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaV3.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaV3::ColaV3() {
	ini = 1;
	fin = 0;
	v = new int[MAXVC3];
}

bool ColaV3::vacia() {
	return siguiente(fin) == ini;
}

int ColaV3::siguiente(int dir) {
	if (dir == MAXVC3)
		return 1;
	else
		return dir + 1;
}

int ColaV3::anterior(int dir) {
	if (dir == 1)
		return MAXVC3;
	else
		return dir - 1;
}

void ColaV3::poner(int e) {
	if (siguiente(siguiente(fin)) != ini) {
		fin = siguiente(fin);
		v[fin - 1] = e;
	}
}

void ColaV3::sacar(int &e) {
	if (!vacia()) {
		e = v[ini - 1];
		ini = siguiente(ini);
	}
}

int ColaV3::primero() {
	if (!vacia())
		return v[ini - 1];
}

string ColaV3::to_str() {
	string s = "<<";
	int e;
	ColaV3* aux = new ColaV3();
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

int ColaV3::ultimo() {
	if (!vacia())
		return v[fin - 1];
}

void ColaV3::poner_frente(int e) {
	if (siguiente(siguiente(fin)) != ini) {
		ini = anterior(ini);
		v[ini - 1] = e;
	}
}

void ColaV3::sacar_final(int &e) {
	if (!vacia()) {
		e = v[fin - 1];
		fin = anterior(fin);
	}
}
