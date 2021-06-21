// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjuntoL.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoL::ConjuntoL() {
	elem = new ListaV();
	srand(time(NULL));
}

bool ConjuntoL::vacio() {
	return elem->vacia();
}

bool ConjuntoL::pertenece(int e) {
	int aux = elem->primero();
	while (aux != NULL) {
		int el = elem->recupera(aux);
		if (el == e)
			return true;
		aux = elem->siguiente(aux);
	}
	return false;
}

void ConjuntoL::inserta(int e) {
	if (!pertenece(e)) {
		elem->inserta(elem->primero(), e);
	}
}

void ConjuntoL::suprime(int e) {
	if (pertenece(e)) {
		int aux = elem->primero();
		int dir = -1;
		while (aux != -1) {
			int el = elem->recupera(aux);
			if (el == e) {
				dir = aux;
				break;
			}
			aux = elem->siguiente(aux);
		}
		if (dir != -1)
			elem->suprime(dir);
	}
}

int ConjuntoL::cardinal() {
	return elem->longitud();
}

int ConjuntoL::ordinal(int e) {
	int aux = elem->primero();
	int c = 0;
	while (aux != -1) {
		c++;
		int el = elem->recupera(aux);
		if (el == e)
			return c;
		aux = elem->siguiente(aux);
	}
	cout << "Elemento no encontrado\n";
}

int ConjuntoL::muestrea() {
	if (!vacio()) {
		int aux = elem->primero();
		int lug = (rand() % cardinal()) + 1;
		int c = 0;
		while (aux != -1) {
			c++;
			if (c == lug)
				return elem->recupera(aux);
			aux = elem->siguiente(aux);
		}
		return 0;
	}
}

string ConjuntoL::to_str() {
	string s = "{";
	int aux = elem->primero();
	while (aux != -1) {
		int el = elem->recupera(aux);
		s += to_string(el) + ",";
		aux = elem->siguiente(aux);
	}
	s.erase(s.length() - 1, 1);
	return s + "}";
}
