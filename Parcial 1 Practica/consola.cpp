#include <iostream>
#include "UMemoria.h"
#include "UListaS.h"
#include "UConjuntoS.h"
#include "UConjuntoL.h"
#include "UPoliS.h"
#include "UPoli1.h"

using namespace std;

void prueba_memoria();
void poli1();

void interseccion3();
void interseccion3(ConjuntoL a, ConjuntoL b, ConjuntoL c, ConjuntoL &cr);

int main() {
	interseccion3();
	system("pause");
	return 0;
}

void prueba_memoria() {
	int x = 1111;
	int y = 2222;
	int z = 3333;
	int w = 4444;
	CSMemoria* m = new CSMemoria();
	ListaS* l = new ListaS(m);
	ConjuntoS* c = new ConjuntoS(m);
	PoliS* p = new PoliS(m);
	// m->delete_espacio(0);
	l->inserta(l->primero(), x);
	l->inserta(l->primero(), y);
	// m->delete_espacio(1);
	c->inserta(z);
	p->poner_termino(2, 5);
	// m->delete_espacio(6);
	l->inserta(l->fin(), w);
	m->mostrar();

}

void poli1() {
	Poli1* p = new Poli1();
	p->poner_termino(2, 3);
	p->poner_termino(5, 1);
	p->poner_termino(3, 7);
	cout << p->mostrar() << endl;
	p->poner_termino(-3, 7);
	cout << p->mostrar() << endl;
	p->poner_termino(-2, 3);
	cout << p->mostrar() << endl;
	p->poner_termino(-5, 1);
	cout << p->mostrar() << endl;
}

void interseccion3() {
	ConjuntoL a;
	ConjuntoL b;
	ConjuntoL c;
	ConjuntoL d;
	a.inserta(1);
	a.inserta(9);
	b.inserta(2);
	b.inserta(9);
	c.inserta(3);
	c.inserta(9);
	interseccion3(a, b, c, d);
	cout << a.to_str() << endl;
	cout << b.to_str() << endl;
	cout << c.to_str() << endl;
	cout << d.to_str() << endl;
}

// valor o referencia, int, string, char, short int, long int
void interseccion3(ConjuntoL a, ConjuntoL b, ConjuntoL c, ConjuntoL &cr) {
	ConjuntoL aux;
	while (!a.vacio()) {
		int x = a.muestrea();
		if (a.pertenece(x) && b.pertenece(x) && c.pertenece(x))
			cr.inserta(x);
		aux.inserta(x);
		a.suprime(x);
	}
	while (!aux.vacio()) {
		int x = aux.muestrea();
		a.inserta(x);
		aux.suprime(x);
	}
}
