// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoli3.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Poli3::Poli3() {
	k = new ListaP();
}

bool Poli3::es_cero() {
	return k->vacia();
}

int Poli3::grado() {
	if (!es_cero())
		return k->longitud() - 1;
}

int Poli3::coeficiente(int exp) {
	NodoL* aux = buscar_exponente(exp);
	int coef = k->recupera(aux);
	if (coef != 0)
		return coef;
}

NodoL* Poli3::buscar_exponente(int exp) {
	if (exp > grado())
		return NULL;
	NodoL* aux = k->primero();
	int cont = grado();
	while (aux != NULL) {
		if (exp == cont)
			return aux;
		cont--;
		aux = k->siguiente(aux);
	}
	return NULL;
}

NodoL* Poli3::buscar_termino_n(int i) {
	if (i < 0 || i > numero_terminos())
		return NULL;
	int cont = 0;
	NodoL* aux = k->primero();
	while (aux != NULL) {
		if (k->recupera(aux) != 0) {
			cont++;
			if (cont == i)
				return aux;
		}
		aux = k->siguiente(aux);
	}
	return NULL;
}

void Poli3::poner_termino(int coef, int exp) {
	if (exp >= 0 && coef != 0) {
		if (es_cero()) {
			k->inserta_ultimo(coef);
			for (int i = 0; i < exp; i++)
				k->inserta_ultimo(0);
		}
		else {
			NodoL* aux = buscar_exponente(exp);
			if (aux == NULL) { // Exp > grado
				int cant = exp - grado();
				for (int i = 0; i < cant; i++)
					k->inserta_primero(0);
				k->modifica(k->primero(), coef);
			}
			else {
				int suma = k->recupera(aux) + coef;
				k->modifica(aux, suma);
				if (exp == grado() && suma == 0) {
					NodoL* prim = k->primero();
					while (prim != NULL && k->recupera(prim) == 0) {
						NodoL* sig = k->siguiente(prim);
						k->suprime(prim);
						prim = sig;
					}

				}
			}
		}
	}
}

int Poli3::numero_terminos() {
	int nro = 0;
	if (!es_cero()) {
		NodoL* aux = k->primero();
		while (aux != NULL) {
			if (k->recupera(aux) != 0)
				nro++;
			aux = k->siguiente(aux);
		}
	}
	return nro;
}

int Poli3::exponente(int nro_ter) {
	NodoL* exp = buscar_termino_n(nro_ter);
	if (exp != NULL) {
		NodoL* aux = k->primero();
		int cont = grado();
		while (aux != NULL) {
			if (aux == exp)
				return cont;
			cont--;
			aux = k->siguiente(aux);
		}
	}
}

float Poli3::evaluar(float x) {
	float sum = 0;
	for (int i = 0; i < numero_terminos(); i++) {
		int exp = exponente(i + 1);
		int coef = coeficiente(exp);
		sum += coef * pow(x, exp);
	}
	return sum;
}

void Poli3::derivada() {
	Poli3* aux = new Poli3();
	while (!es_cero()) {
		int exp = exponente(1);
		int coef = coeficiente(exp);
		poner_termino(-coef, exp);
		aux->poner_termino(coef * exp, exp - 1);
	}
	while (!aux->es_cero()) {
		int exp = aux->exponente(1);
		int coef = aux->coeficiente(exp);
		aux->poner_termino(-coef, exp);
		poner_termino(coef, exp);
	}
}

void Poli3::mostrar() {
	cout << "K: " << k->to_str() << endl;
	string r = "";
	int n = numero_terminos();
	for (int i = 1; i <= n; i++) {
		int exp = exponente(i);
		int coef = coeficiente(exp);
		if (coef > 0)
			r += "+";
		r += to_string(coef) + "x^" + to_string(exp);
	}
	cout << r << endl;
}
