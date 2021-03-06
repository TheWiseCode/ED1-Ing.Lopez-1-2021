// ---------------------------------------------------------------------------

#ifndef UConjuntoVH
#define UConjuntoVH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX_C = 100;

class ConjuntoV {
private:
	bool* v;
	int cant;

public:
	ConjuntoV();
	bool vacio();
	bool pertenece(int e);
	void inserta(int e);
	void suprime(int e);
	int cardinal(); // numero elementos
	int ordinal(int e); // posicion de e
	int muestrea();
	string to_str();
};
#endif
