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
	float evaluar(float x);
	void derivada(PoliP *p);
	void mostrar_integral();
	PoliP* suma(PoliP* a, PoliP* b);
	PoliP* resta(PoliP* a, PoliP* b);
    PoliP* producto(PoliP* a, PoliP* b);
	string to_str();

};

#endif
