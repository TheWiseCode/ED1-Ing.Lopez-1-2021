#include <iostream>
#include "UColaV3.h"
#include "UColaLS.h"
#include "UColaP.h"
#include "UColaPi.h"
#include "UColaPrioridad.h"

using namespace std;

int main() {
	CSMemoria* m = new CSMemoria();
	ColaPrioridad* c = new ColaPrioridad(m);
	c->asignar_frec_prioridad(2, 0);
	c->asignar_frec_prioridad(1, 1);
	c->asignar_frec_prioridad(3, 2);
	// Cola 0
	c->poner(1, 0);
	c->poner(2, 0);
	c->poner(3, 0);
	// Cola 1
	c->poner(4, 1);
	c->poner(5, 1);
	c->poner(6, 1);
	c->poner(7, 1);
	// Cola 2
	c->poner(8, 2);
	c->poner(9, 2);
	c->poner(10, 2);
	c->poner(11, 2);
	c->poner(12, 2);
	cout << c->to_str();
	m->mostrar();
	system("pause");
	return 0;
}
