// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjuntoL.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoL::ConjuntoL() {
	elem = new ListaP();
	srand(time(NULL));
}

bool ConjuntoL::vacio() {
	return elem->vacia();
}

bool ConjuntoL::pertenece(int e) {
	NodoL* aux = elem->primero();
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
		NodoL* aux = elem->primero();
		NodoL* dir = NULL;
		while (aux != NULL) {
			int el = elem->recupera(aux);
			if (el == e) {
				dir = aux;
				break;
			}
			aux = elem->siguiente(aux);
		}
		if (dir != NULL)
			elem->suprime(dir);
	}
}

int ConjuntoL::cardinal() {
	return elem->longitud();
}

int ConjuntoL::ordinal(int e) {
	NodoL* aux = elem->primero();
	int c = 0;
	while (aux != NULL) {
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
		NodoL* aux = elem->primero();
		int lug = (rand() % cardinal()) + 1;
		int c = 0;
		while (aux != NULL) {
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
	NodoL* aux = elem->primero();
	while (aux != NULL) {
		int el = elem->recupera(aux);
		s += to_string(el) + ",";
		aux = elem->siguiente(aux);
	}
	if (s != "{")
		s.erase(s.length() - 1, 1);
	return s + "}";
}
