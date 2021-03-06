// ---------------------------------------------------------------------------

#ifndef UPoliVH
#define UPoliVH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAX_VP = 30;

class PoliV {
private:
	int* vc;
	int* ve;
	int nt;

	int buscar_exponente(int exp);

public:
	PoliV();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	string to_str();
	PoliV* PoliV::producto(PoliV* a, PoliV* b);

};
#endif
