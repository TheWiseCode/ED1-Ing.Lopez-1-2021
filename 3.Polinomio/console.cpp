#include <iostream>
#include "UPoliP.h"

using namespace std;

bool es_polinomio_ordenado(PoliP* p);

int main() {
	PoliP* a = new PoliP();
	a->poner_termino(15, 2);
	a->poner_termino(23, 3);
	a->poner_termino(2, 2);
	if (es_polinomio_ordenado(a))
		cout << "Es polinomio ordenado" << endl;
	else
		cout << "No esta ordenado el polinomio" << endl;
	return 0;
}

bool es_polinomio_ordenado(PoliP* p) {
	bool ord1 = true;
	bool ord2 = true;
	int n = p->numero_terminos();
	if (n > 0) {
		int eM = p->exponente(1);
		for (int i = 1; i <= n; i++) {
			int e = p->exponente(i);
			if (e < eM)
				ord1 = false;
			if(e > eM)
                ord2 = false;
			eM = e;
		}
	}
	return ord1 || ord2;
}
