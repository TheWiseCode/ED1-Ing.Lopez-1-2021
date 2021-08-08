// ---------------------------------------------------------------------------

#ifndef UColaPrioridadH
#define UColaPrioridadH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UColaV3.h"
#include "UColaS.h"
#include "UMemoria.h"

const int MAXCP = 3;
using namespace std;

class ColaPrioridad {
private:
	ColaS** vc;
	int* vf;
	int colaAct;
	int cant;

public:
	ColaPrioridad();
	ColaPrioridad(CSMemoria* m);
	bool vacia();
	int primero();
	void poner(int e, int prioridad);
	void asignar_frec_prioridad(int frec, int prioridad);
	void sacar(int &e);
	string to_str();
};

#endif
