#include <iostream>
#include "UConjuntoV.h"
#include "UConjuntoL.h"

using namespace std;

int main() {
	ConjuntoV* c = new ConjuntoV();
	c->inserta(1);
	c->inserta(3);
	c->inserta(7);
	c->inserta(15);
	c->inserta(20);
	cout << c->to_str() << endl;
	c->suprime(7);
	c->suprime(15);
	cout << c->to_str() << endl;
	for(int i = 0; i < 10;i++){
		int e = c->muestrea();
        cout << e << endl;
	}
	bool x;
	cin >> x;
	return 0;
}
