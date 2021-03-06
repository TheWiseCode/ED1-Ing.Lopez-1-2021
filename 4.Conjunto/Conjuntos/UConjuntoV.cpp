// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjuntoV.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoV::ConjuntoV() {
	v = new bool[MAX_C];
	cant = 0;
	srand(time(NULL));
}

bool ConjuntoV::vacio() {
	return cant == 0;
}

bool ConjuntoV::pertenece(int e) {
	if (e >= 1 && e <= MAX_C)
		return v[e - 1];
	return false;
}

void ConjuntoV::inserta(int e) {
	if (!pertenece(e)) {
		v[e - 1] = true;
		cant++;
	}
}

void ConjuntoV::suprime(int e) {
	if (pertenece(e)) {
		v[e - 1] = false;
		cant--;
	}
}

int ConjuntoV::cardinal() {
	return cant;
}

int ConjuntoV::ordinal(int e) {
	int c = 0;
	for (int i = 0; i < MAX_C; i++) {
		if (v[i]) {
			c++;
			if (i + 1 == e)
				return c;
		}
	}
	cout << "No pertenece el elemento\n";
}

int ConjuntoV::muestrea() {
	if (!vacio()) {
		int lug = (rand() % cardinal()) + 1;
		int c = 0;
		for (int i = 0; i < MAX_C; i++) {
			if (v[i]) {
				c++;
				if (c == lug)
					return i + 1;
			}
		}
	}
}

string ConjuntoV::to_str() {
	string s = "{";
	for (int i = 0; i < MAX_C; i++) {
		if (v[i]) {
			s += to_string((i + 1)) + ",";
		}
	}
	s.erase(s.length() - 1, 1);
	return s + "}";
}
