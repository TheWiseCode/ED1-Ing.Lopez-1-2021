// ---------------------------------------------------------------------------

#ifndef UMatrizSmDbH
#define UMatrizSmDbH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UMemoria.h"

using namespace std;

const string colMc = "->col";
const string datoMc = "->dato";
const string sigMc = "->sigC";
const string nodoMc = "col,dato,sigC";

const string filMf = "->fil";
const string antMf = "->antF";
const string sigMf = "->sigF";
const string ptrColMf = "->ptrCol";
const string nodoMf = "fil,antF,sigF,ptrCol";

class MatrizSD {
private:
	CSMemoria *mem;
	int ptrFil;
	int repe, df, dc;
	int nt;

	int buscarC(int f, int c);
	int buscarF(int f);
	int posicionIns(int f);
	void insertar(int f, int c, int v);
	void suprimir2(int dirFil, int dirCol);
	void suprimir1(int dir);

public:
	MatrizSD();
	MatrizSD(CSMemoria* m);
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int valor);
	string to_str();
    void mostrar();

};
#endif
