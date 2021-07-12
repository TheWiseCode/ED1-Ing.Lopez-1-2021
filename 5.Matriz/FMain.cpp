#include <iostream>
#include "UMatrizV.h"
#include "UMatrizVC.h"
#include "UMatrizPtr.h"
#include "UMatrizPtrDb.h"
#include "UMatrizSmDb.h"

using namespace std;

bool es_simetrica(MatrizSD * m) {
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

MatrizSD* transpuesta(MatrizSD * m) {
	MatrizSD* trans = new MatrizSD();
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
	MatrizSD* m = new MatrizSD(mem);
	int x = mem->new_espacio("juan,perez,torrez");
	mem->poner_dato(x, "->perez", 666);
	m->dimensionar(5, 10);
	m->definir_valor_repetido(1);
	m->poner(3, 2, 300);
	// mem->mostrar();
	// m->mostrar();
	m->poner(1, 2, 100);
	m->poner(2, 3, 200);
	// mem->mostrar();
	// m->mostrar();
	m->poner(2, 3, 1);
	// mem->mostrar();
	MatrizSD* t = transpuesta(m);
	cout << m->to_str() << endl;
	cout << t->to_str() << endl;
	/* if (es_simetrica(m))
	 cout << "Es simetrica\n";
	 else
	 cout << "No es simetrica\n"; */
	system("pause");
	return 0;
}
