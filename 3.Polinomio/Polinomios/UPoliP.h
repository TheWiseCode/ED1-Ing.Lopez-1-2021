// ---------------------------------------------------------------------------

#ifndef UPoliPH
#define UPoliPH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoPo {
	int coef;
	int exp;
	NodoPo* sig;
};

class PoliP {
private:
	NodoPo* ptr_poli;
    int nt;

	NodoPo* buscar_exponente(int exp);
	NodoPo* buscar_termino_n(int i);
    NodoPo* anterior(NodoPo* dir);
    void suprime(NodoPo* dir);

public:
	PoliP();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	string to_str();

};

#endif
