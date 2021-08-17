#include <iostream>
#include "UDicola.h"
#include "UPilaCo.h"

using namespace std;

int main() {
	CSMemoria* m = new CSMemoria();
	m->new_espacio("EXAMEN,FINAL");
	PilaCo* p = new PilaCo(m);
	p->meter(100);
	p->meter(200);
	p->meter(300);
	cout << p->to_str() << endl;
	int e;
	// p->sacar(e);
	e = p->cima();
	cout << "Elem: " << e << endl;
	cout << p->to_str() << endl;
	system("pause");
	return 0;
}

void examen2() {
	CSMemoria* m = new CSMemoria();
	m->new_espacio("EXAMEN,FINAL");
	Dicola* c = new Dicola(m);
	c->poner(100);
	c->poner(300);
	c->poner(400);
	// m->mostrar();
	c->poner(200);
	// m->mostrar();
	int e;
	c->sacar_final(e);
	cout << "elem: " << e << endl;
	m->mostrar();
	cout << c->to_str() << endl;
	c->poner_frente(666);
	cout << c->to_str() << endl;
}
