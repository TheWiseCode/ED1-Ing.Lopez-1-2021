// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoliL.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliL::PoliL() {
	pol = new ListaP();
}

NodoL* PoliL::buscar_exponente(int exp) {
	NodoL* aux = pol->primero();
	while (aux != NULL) {
		NodoL* seg = pol->siguiente(aux);
		if (pol->recupera(seg) == exp)
			return seg;
		aux = pol->siguiente(pol->siguiente(aux));
	}
	return NULL;
}

NodoL* PoliL::buscar_termino_n(int i) {
	int c = 1;
	NodoL* aux = pol->primero();
	while (aux != NULL) {
		if (c == i)
			return aux;
		aux = pol->siguiente(pol->siguiente(aux));
        c++;
	}
	return NULL;
}

bool PoliL::es_cero() {
	return pol->vacia();
}

int PoliL::grado() {
	if (!es_cero()) {
		NodoL* aux = pol->siguiente(pol->primero());
		int max = pol->recupera(aux);
		while (aux != NULL) {
			if (pol->recupera(aux) > max)
				max = pol->recupera(aux);
			if (aux == pol->fin())
				break; // aux = NULL;
			else
				aux = pol->siguiente(pol->siguiente(aux));
		}
		return max;
	}
	else
		cout << "Lista vacia\n";
}

int PoliL::coeficiente(int exp) {
	if (!es_cero()) {
		NodoL* dir_exp = buscar_exponente(exp);
		if (dir_exp != NULL) {
			NodoL* dir_coef = pol->anterior(dir_exp);
			return pol->recupera(dir_coef);
		}
		else
			cout << "No existe ese exponente\n";
	}
}

void PoliL::asignar_coeficiente(int coef, int exp) {
	if (!es_cero()) {
		NodoL* dir_exp = buscar_exponente(exp);
		if (dir_exp != NULL) {
			NodoL* dir_coef = pol->anterior(dir_exp);
			pol->modifica(dir_coef, coef);
			if (coef == 0) {
				pol->suprime(dir_exp);
				pol->suprime(dir_coef);
			}
		}
		else
			cout << "No existe ese termino\n";
	}
}

void PoliL::poner_termino(int coef, int exp) {
	NodoL* dir_exp = buscar_exponente(exp);
	if (dir_exp != NULL) {
		NodoL* dir_coef = pol->anterior(dir_exp);
		int new_coef = pol->recupera(dir_coef) + coef;
		pol->modifica(dir_coef, new_coef);
		if (new_coef == 0) {
			pol->suprime(dir_exp);
			pol->suprime(dir_coef);
		}
	}
	else {
		if (coef != 0) {
			pol->inserta_ultimo(coef);
			pol->inserta_ultimo(exp);
		}
	}
}

int PoliL::numero_terminos() {
	return pol->longitud() / 2;
}

int PoliL::exponente(int nro_ter) {
	if (!es_cero()) {
		NodoL* dir_coef = buscar_termino_n(nro_ter);
		if (dir_coef != NULL) {
			NodoL* dir_exp = pol->siguiente(dir_coef);
			return pol->recupera(dir_exp);
		}
		else
			cout << "No existe ese termino\n";
	}
}

string PoliL::to_str() {
	string r = "";
	int n = numero_terminos();
	for(int i = 1;i <= n;i++){
		int exp = exponente(i);
		int coef = coeficiente(exp);
		if(coef > 0)
			r += "+";
        r += to_string(coef) + "x^" + to_string(exp);
	}
	return r;
}
