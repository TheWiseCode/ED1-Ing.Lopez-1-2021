#include <iostream>
#include "UPoliL.h"
#include "UPoliV.h"
#include "UPoliP.h"

using namespace std;

int main() {
	PoliP* p = new PoliP();
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
	cout << "Exponente nro 2: " << p->exponente(2) << endl;
	/* int c = 1043;
	 bool b = false;
	 NodoPo* aux = new NodoPo();
	 cout << NULL << endl;
	 if (aux) {
	 cout << "True" << endl;
	 }
	 else {
	 cout << "Falso" << endl;
	 } */
	system("pause");
	return 0;
}
