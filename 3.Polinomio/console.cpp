#include <iostream>
#include "UPoliL.h"

using namespace std;

int main() {
	PoliL* p = new PoliL();
	int v[] = {-1, 1, 3, 5, 4, 3};
	cout << p->to_str() << endl;
	for (int i = 0; i < 6; i += 2) {
		p->poner_termino(v[i], v[i + 1]);
		cout << p->to_str() << endl;
	}
	cout << "Grado: " << p->grado() << endl;
	cout << "Coef de 1: " << p->coeficiente(1) << endl;
	p->asignar_coeficiente(0, 5);
	cout << p->to_str() << endl;
	cout << "Exponente nro 2: " << p->exponente(2) << endl;;
	system("pause");
	return 0;
}
