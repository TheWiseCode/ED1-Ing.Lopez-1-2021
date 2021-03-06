// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoli2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Poli2::Poli2() {
	k = new ListaP();
}

bool Poli2::es_cero() {
	return k->vacia();
}

int Poli2::grado() {
	if (!es_cero())
		return k->recupera(k->primero());
}

int Poli2::coeficiente(int exp) {
	NodoL* aux = buscar_exponente(exp);
	int coef = k->recupera(aux);
	if (coef != 0)
		return coef;
}

NodoL* Poli2::buscar_exponente(int exp) {
	if (exp > grado())
		return NULL;
	NodoL* aux = k->siguiente(k->primero());
	int cont = grado();
	while (aux != NULL) {
		if (exp == cont)
			return aux;
		cont--;
		aux = k->siguiente(aux);
	}
	return NULL;
}

NodoL* Poli2::buscar_termino_n(int i) {
	if (i < 0 || i > numero_terminos())
		return NULL;
	int cont = 0;
	NodoL* aux = k->siguiente(k->primero());
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

void Poli2::poner_termino(int coef, int exp) {
	if (exp >= 0 && coef != 0) {
		if (es_cero()) {
			k->inserta_ultimo(exp);
			k->inserta_ultimo(coef);
			for (int i = 0; i < exp; i++)
				k->inserta_ultimo(0);
		}
		else {
			NodoL* aux = buscar_exponente(exp);
			if (aux == NULL) { // Exp > grado
				int cant = exp - grado();
				for (int i = 0; i < cant; i++) {
					NodoL* seg = k->siguiente(k->primero());
					k->inserta(seg, 0);
				}
				k->modifica(k->primero(), exp);
				k->modifica(k->siguiente(k->primero()), coef);
			}
			else {
				int suma = k->recupera(aux) + coef;
				k->modifica(aux, suma);
				if (exp == grado() && suma == 0) {
					NodoL* seg = k->siguiente(k->primero());
					while (seg != NULL && k->recupera(seg) == 0) {
						NodoL* sig = k->siguiente(seg);
						k->suprime(seg);
						seg = sig;
					}
					if (k->longitud() == 1)
						k->suprime(k->primero());
					else {
						int newGrado = k->longitud() - 2;
						k->modifica(k->primero(), newGrado);
					}

				}
			}
		}
	}
}

int Poli2::numero_terminos() {
	int nro = 0;
	if (!es_cero()) {
		NodoL* aux = k->siguiente(k->primero());
		while (aux != NULL) {
			if (k->recupera(aux) != 0)
				nro++;
			aux = k->siguiente(aux);
		}
	}
	return nro;
}

int Poli2::exponente(int nro_ter) {
	NodoL* exp = buscar_termino_n(nro_ter);
	if (exp != NULL) {
		NodoL* aux = k->siguiente(k->primero());
		int cont = grado();
		while (aux != NULL) {
			if (aux == exp)
				return cont;
			cont--;
			aux = k->siguiente(aux);
		}
	}
}

float Poli2::evaluar(float x) {
	float sum = 0;
	for (int i = 0; i < numero_terminos(); i++) {
		int exp = exponente(i + 1);
		int coef = coeficiente(exp);
		sum += coef * pow(x, exp);
	}
	return sum;
}

void Poli2::derivada() {
	Poli2* aux = new Poli2();
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

void Poli2::mostrar() {
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
