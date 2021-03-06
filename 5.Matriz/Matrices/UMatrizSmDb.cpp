// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UMatrizSmDb.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

MatrizSD::MatrizSD() {
	mem = new CSMemoria();
	ptrFil = NULO;
	df = dc = repe = 0;
	nt = 0;
}

MatrizSD::MatrizSD(CSMemoria* m) {
	mem = m;
	ptrFil = NULO;
	df = dc = repe = 0;
	nt = 0;
}

void MatrizSD::dimensionar(int f, int c) {
	df = f;
	dc = c;
}

int MatrizSD::dimension_fila() {
	return df;
}

int MatrizSD::dimension_columna() {
	return dc;
}

int MatrizSD::buscarC(int f, int c) {
	int auxf = ptrFil;
	while (auxf != NULO) {
		int auxf_fil = mem->obtener_dato(auxf, filMf);
		if (auxf_fil == f) {
			int auxc = mem->obtener_dato(auxf, ptrColMf);
			while (auxc != NULO) {
				int auxc_col = mem->obtener_dato(auxc, colMc);
				if (auxc_col == c)
					return auxc;
				auxc = mem->obtener_dato(auxc, sigMc);
			}
			return NULO;
		}
		auxf = mem->obtener_dato(auxf, sigMf);
	}
	return NULO;
}

int MatrizSD::buscarF(int f) {
	int auxf = ptrFil;
	while (auxf != NULO) {
		int auxf_fil = mem->obtener_dato(auxf, filMf);
		if (auxf_fil == f)
			return auxf;
		auxf = mem->obtener_dato(auxf, sigMf);
	}
	return NULO;
}

int MatrizSD::posicionIns(int f) {
	int aux = ptrFil;
	while (aux != NULO) {
		int aux_fil = mem->obtener_dato(aux, filMf);
		if (f < aux_fil)
			return aux;
		aux = mem->obtener_dato(aux, sigMf);
	}
	return NULO;
}

void MatrizSD::suprimir2(int dirFil, int dirCol) {
	int dirFil_ptrCol = mem->obtener_dato(dirFil, ptrColMf);
	if (dirCol == dirFil_ptrCol) {
		int dirFil_ptrCol_sigC = mem->obtener_dato(dirFil_ptrCol, sigMc);
		mem->poner_dato(dirFil, ptrColMf, dirFil_ptrCol_sigC);
	}
	else {
		int ant;
		// Codido de anterior
		int x = mem->obtener_dato(dirFil, ptrColMf);
		ant = NULO;
		while (x != NULO) {
			if (x == dirCol)
				break;
			ant = x;
			x = mem->obtener_dato(x, sigMc);
		}
		//
		int dirCol_sigC = mem->obtener_dato(dirCol, sigMc);
		mem->poner_dato(ant, sigMc, dirCol_sigC);
	}
	mem->delete_espacio(dirCol);
	nt--;
	dirFil_ptrCol = mem->obtener_dato(dirFil, ptrColMf);
	if (dirFil_ptrCol == NULO) {
		suprimir1(dirFil);
	}
}

void MatrizSD::suprimir1(int dir) {
	if (dir == ptrFil) {
		int ptrFil_sigF = mem->obtener_dato(ptrFil, sigMf);
		ptrFil = ptrFil_sigF;
	}
	else {
		int ant = mem->obtener_dato(dir, antMf);
		int sig = mem->obtener_dato(dir, sigMf);
		mem->poner_dato(ant, sigMf, sig);
		if (sig != NULO) {
			mem->poner_dato(sig, antMf, ant);
		}
	}
	mem->delete_espacio(dir);
}

void MatrizSD::insertar(int f, int c, int v) {
	int x = mem->new_espacio(nodoMc);
	if (x != NULO) {
		mem->poner_dato(x, colMc, c);
		mem->poner_dato(x, datoMc, v);
		mem->poner_dato(x, sigMc, NULO);
		int dirFila = buscarF(f); // Buscamos si ya existe la fila
		if (dirFila != NULO)
		{ // Ya existe la fila, insertamos el nodo de columna
			int dirFila_ptrCol = mem->obtener_dato(dirFila, ptrColMf);
			mem->poner_dato(x, sigMc, dirFila_ptrCol);
			mem->poner_dato(dirFila, ptrColMf, x);
		}
		else { // Insercion nueva, hay dos casos
			int xf = mem->new_espacio(nodoMf);
			if (xf != NULO) {
				mem->poner_dato(xf, filMf, f);
				mem->poner_dato(xf, antMf, NULO);
				mem->poner_dato(xf, sigMf, NULO);
				mem->poner_dato(xf, ptrColMf, NULO);
				int posF = posicionIns(f);
				if (posF == NULO)
				{ // No  hay datos en los nodos o se tendra q insertar al final
					if (ptrFil == NULO) // No hay datos
							ptrFil = xf;
					else { // Insercion a lo ultimo
						int fin = ptrFil;
						int fin_sigF = mem->obtener_dato(fin, sigMf);
						while (fin_sigF != NULO) {
							fin_sigF = mem->obtener_dato(fin, sigMf);
							fin = fin_sigF;
						}
						mem->poner_dato(xf, antMf, fin);
						mem->poner_dato(fin, sigMf, xf);
					}
				}
				else { // Se inserta en el primero, o algun nodo que no sea al final
					if (posF == ptrFil) { // Inserta al inicio
						mem->poner_dato(xf, sigMf, ptrFil);
						mem->poner_dato(ptrFil, antMf, xf);
						ptrFil = xf;
					}
					else { // Insercion por el medio
						int ant = mem->obtener_dato(posF, antMf); ;
						int sig = posF;
						mem->poner_dato(xf, sigMf, sig);
						mem->poner_dato(xf, antMf, ant);
						mem->poner_dato(ant, sigMf, xf);
						mem->poner_dato(sig, antMf, xf);
					}
				}
				int xf_ptrCol = mem->obtener_dato(xf, ptrColMf);
				mem->poner_dato(x, sigMc, xf_ptrCol);
				mem->poner_dato(xf, ptrColMf, x);
			}
		}
		nt++;
	}
	else
		cout << "ERROR NO EXISTE ESPACIO DE MEMORIA\n";
}

void MatrizSD::poner(int f, int c, int valor) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int dir = buscarC(f, c);
		if (dir != NULO) {
			mem->poner_dato(dir, datoMc, valor);
			// Analizar si valor == repe
			if (valor == repe) {
				int dirFila = buscarF(f);
				suprimir2(dirFila, dir);
			}
		}
		else if (valor != repe) // Insercion nueva
				insertar(f, c, valor);

	}
}

int MatrizSD::elemento(int f, int c) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int dir = buscarC(f, c);
		if (dir != NULO)
			return mem->obtener_dato(dir, datoMc);
		else
			return repe;
	}
}

void MatrizSD::definir_valor_repetido(int valor) {
	bool hayRepe = false;
	int auxF = ptrFil;
	while (auxF != NULO && hayRepe == false) {
		int auxC = mem->obtener_dato(auxF, ptrColMf);
		while (auxC != NULO && hayRepe == false) {
			if (mem->obtener_dato(auxC, datoMc) == valor)
				hayRepe = true;
			auxC = mem->obtener_dato(auxC, sigMc);
		}
		auxF = mem->obtener_dato(auxF, sigMf);
	}
	if (ptrFil == NULO || hayRepe == false) {
		repe = valor;
	}
	else {
		int nRep = valor;
		int aRep = repe;
		for (int i = 1; i <= df; i++) {
			for (int j = 1; j <= dc; j++) {
				int e = elemento(i, j);
				if (e == nRep) {
					int dirF = buscarF(i);
					int dirC = buscarC(i, j);
					suprimir2(dirF, dirC);
				}
				else if (e == aRep)
					insertar(i, j, aRep);
			}
		}
		repe = valor;
	}
}

string MatrizSD::to_str() {
	string r = "";
	for (int i = 1; i <= df; i++) {
		r += "| ";
		for (int j = 1; j <= dc; j++) {
			int e = elemento(i, j);
			r += to_string(e) + "  ";
		}
		r += "|\n";
	}
	r += "NT: " + to_string(nt) + "\n";
	return r;
}

void MatrizSD::mostrar() {
	cout << "DimF: " << df << endl;
	cout << "DimC: " << dc << endl;
	cout << "Repe: " << repe << endl;
	cout << "PtrFil: " << ptrFil << endl;
}
