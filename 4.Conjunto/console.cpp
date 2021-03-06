#include <iostream>
#include "UConjuntoV.h"
#include "UConjuntoL.h"
#include "UConjuntoP.h"
#include "UConjuntoS.h"

using namespace std;

bool iguales(ConjuntoP* c1, ConjuntoP* c2);
void iguales();

bool subconjunto(ConjuntoP* c1, ConjuntoP* c2);
void subconjunto();

void _union(ConjuntoP* a, ConjuntoP* b, ConjuntoP* c);
void _union();

void interseccion(ConjuntoP* a, ConjuntoP* b, ConjuntoP* c);
void interseccion();

// (A n B) - C
void combi1(ConjuntoP* a, ConjuntoP* b, ConjuntoP* c, ConjuntoP* d);
void combi1();

int main() {
	ConjuntoP* c = new ConjuntoP();
	c->inserta(1);
	c->inserta(3);
	c->inserta(7);
	c->inserta(15);
	c->inserta(20);
	cout << c->to_str() << endl;
	c->suprime(7);
	c->suprime(15);
	cout << c->to_str() << endl;
	for (int i = 0; i < 10; i++) {
		int e = c->muestrea();
		cout << e << endl;
	}
	bool x;
	cin >> x;
	// iguales();
	// subconjunto();
	// _union();
	// interseccion();
	// combi1();
	system("pause");
	return 0;
}

bool iguales(ConjuntoP* c1, ConjuntoP* c2) {
	if (c1->cardinal() == c2->cardinal()) {
		ConjuntoP* aux = new ConjuntoP();
		while (!c1->vacio()) {
			int m = c1->muestrea();
			if (!c2->pertenece(m))
				break;
			c1->suprime(m);
			aux->inserta(m);
		}
		bool ig = c1->vacio();
		while (!aux->vacio()) {
			int m = aux->muestrea();
			aux->suprime(m);
			c1->inserta(m);
		}
		return ig;
	}
	return false;
}

bool subconjunto(ConjuntoP* c1, ConjuntoP* c2) {
	if (c1->cardinal() <= c2->cardinal()) {
		ConjuntoP* aux = new ConjuntoP();
		bool sub = true;
		while (!c1->vacio()) {
			int m = c1->muestrea();
			if (!c2->pertenece(m)) {
				sub = false;
				break;
			}
			c1->suprime(m);
			aux->inserta(m);
		}
		while (!aux->vacio()) {
			int m = aux->muestrea();
			aux->suprime(m);
			c1->inserta(m);
		}
		return sub;
	}
	return false;
}

void subconjunto() {
	ConjuntoP* c1 = new ConjuntoP();
	ConjuntoP* c2 = new ConjuntoP();
	c1->inserta(1);
	c1->inserta(2);
	c1->inserta(5);
	c2->inserta(1);
	c2->inserta(2);
	c2->inserta(3);
	c2->inserta(4);
	bool sub = subconjunto(c1, c2);
	if (sub)
		cout << "Subconjuntos\n";
	else
		cout << "No son subconjuntos\n";
}

void iguales() {
	ConjuntoP* c1 = new ConjuntoP();
	ConjuntoP* c2 = new ConjuntoP();
	c1->inserta(1);
	c1->inserta(2);
	c1->inserta(3);
	c1->inserta(5);
	c2->inserta(1);
	c2->inserta(2);
	c2->inserta(3);
	c2->inserta(4);
	bool ig = iguales(c1, c2);
	if (ig)
		cout << "Iguales\n";
	else
		cout << "No son Iguales\n";
}

void _union(ConjuntoP* a, ConjuntoP* b, ConjuntoP* c) {
	ConjuntoP* aux = new ConjuntoP();
	while (!a->vacio()) {
		int m = a->muestrea();
		a->suprime(m);
		aux->inserta(m);
		c->inserta(m);
	}
	while (!aux->vacio()) {
		int m = aux->muestrea();
		aux->suprime(m);
		a->inserta(m);
	}
	while (!b->vacio()) {
		int m = b->muestrea();
		b->suprime(m);
		aux->inserta(m);
		if (!c->pertenece(m))
			c->inserta(m);
	}
	while (!aux->vacio()) {
		int m = aux->muestrea();
		aux->suprime(m);
		b->inserta(m);
	}
}

void _union() {
	ConjuntoP* a = new ConjuntoP();
	ConjuntoP* b = new ConjuntoP();
	ConjuntoP* c = new ConjuntoP();
	a->inserta(1);
	a->inserta(2);
	a->inserta(3);
	a->inserta(5);
	b->inserta(1);
	b->inserta(2);
	b->inserta(3);
	b->inserta(4);
	_union(a, b, c);
	cout << a->to_str() << endl;
	cout << b->to_str() << endl;
	cout << c->to_str() << endl;
}

void interseccion(ConjuntoP* a, ConjuntoP* b, ConjuntoP* c) {
	ConjuntoP* aux = new ConjuntoP();
	while (!a->vacio()) {
		int m = a->muestrea();
		if (a->pertenece(m) && b->pertenece(m))
			c->inserta(m);
		a->suprime(m);
		aux->inserta(m);
	}
	while (!aux->vacio()) {
		int m = aux->muestrea();
		aux->suprime(m);
		a->inserta(m);
	}
}

void interseccion() {
	ConjuntoP* a = new ConjuntoP();
	ConjuntoP* b = new ConjuntoP();
	ConjuntoP* c = new ConjuntoP();
	a->inserta(1);
	a->inserta(2);
	a->inserta(3);
	a->inserta(5);
	b->inserta(1);
	b->inserta(2);
	b->inserta(3);
	b->inserta(4);
	interseccion(a, b, c);
	cout << a->to_str() << endl;
	cout << b->to_str() << endl;
	cout << c->to_str() << endl;
}

// (A n B) - C
void combi1(ConjuntoP* a, ConjuntoP* b, ConjuntoP* c, ConjuntoP* d) {
	ConjuntoP* x = new ConjuntoP();
	interseccion(a, b, x);
	while (!x->vacio()) {
		int m = x->muestrea();
		if (x->pertenece(m) && !c->pertenece(m))
			d->inserta(m);
		x->suprime(m);
	}
}

void combi1() {
	ConjuntoP* a = new ConjuntoP();
	ConjuntoP* b = new ConjuntoP();
	ConjuntoP* c = new ConjuntoP();
	ConjuntoP* d = new ConjuntoP();
	a->inserta(1);
	a->inserta(7);
	a->inserta(5);
	a->inserta(3);
	a->inserta(10);
	a->inserta(12);
	a->inserta(99);
	a->inserta(100);
	// -----------
	b->inserta(1);
	b->inserta(7);
	b->inserta(5);
	b->inserta(8);
	b->inserta(15);
	b->inserta(99);
	b->inserta(100);
	// -----------
	c->inserta(5);
	c->inserta(3);
	c->inserta(15);
	c->inserta(9);
	c->inserta(14);
	c->inserta(77);
	combi1(a, b, c, d);
	cout << a->to_str() << endl;
	cout << b->to_str() << endl;
	cout << c->to_str() << endl;
	cout << d->to_str() << endl;
}
