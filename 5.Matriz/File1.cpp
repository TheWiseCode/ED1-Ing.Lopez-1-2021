#include <iostream>
#include "UMatrizL.h"

using namespace std;

bool es_simetrica(MatrizL * m) {
	int f = m->dimension_fila();
	int c = m->dimension_columna();
	if (f == c) {
		for (int i = 1; i <= f; i++) {
			for (int j = 1; j <= c; j++) {
				if (m->elemento(i, j) != m->elemento(j, i))
					return false;
			}
		}
		return true;
	}
	return false;
}

MatrizL* transpuesta(MatrizL * m) {
	MatrizL* trans = new MatrizL();
	int f = m->dimension_fila();
	int c = m->dimension_columna();
	trans->dimensionar(c, f);
	for (int i = 1; i <= f; i++) {
		for (int j = 1; j <= c; j++) {
			trans->poner(j, i, m->elemento(i, j));
		}
	}
	return trans;
}

int main() {
	CSMemoria* mem = new CSMemoria();
	MatrizL* m = new MatrizL(mem);
	int x = mem->new_espacio("juan,perez,torrez");
	mem->poner_dato(x, "->perez", 666);
	m->dimensionar(100000, 1000000);
	m->definir_valor_repetido(0);
	m->poner(3, 2, 300);
	mem->mostrar();
	m->definir_valor_repetido(1);
	m->poner(1, 2, 100);
	m->poner(2, 3, 200);
	mem->mostrar();
	m->mostrar();
	m->poner(2, 3, 1);
	mem->mostrar();
	system("pause");
	return 0;
}
