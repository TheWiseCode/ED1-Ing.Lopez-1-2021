#include <iostream>
#include "UColaV3.h"
#include "UColaLS.h"
#include "UColaP.h"
#include "UColaPi.h"

using namespace std;

int main() {
	// CSMemoria* m = new CSMemoria();
	// ColaLS* c = new ColaLS(m);
	ColaPi* c = new ColaPi();
	c->poner(1);
	c->poner(2);
	c->poner(3);
	c->poner(4);
	// m->mostrar();
    int elem;
	c->sacar(elem);
    cout << elem << endl;
	cout << c->to_str() << endl;
	system("pause");
	return 0;
}
