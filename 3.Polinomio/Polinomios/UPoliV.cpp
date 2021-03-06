// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoliV.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliV::PoliV() {
	nt = 0;
	vc = new int[MAX_VP];
	ve = new int[MAX_VP];
}

bool PoliV::es_cero() {
	return nt == 0;
}

int PoliV::buscar_exponente(int exp) {
	for (int i = 0; i < nt; i++) {
		if (ve[i] == exp)
			return i;
	}
	return -1;
}

int PoliV::grado() {
	if (!es_cero()) {
		int max = ve[0];
		for (int i = 1; i < nt; i++) {
			if (ve[i] > max)
				max = ve[i];
		}
		return max;
	}
	else
		cout << "Polinomio vacio\n";
}

int PoliV::coeficiente(int exp) {
	if (exp >= 0 && exp <= grado()) {
		for (int i = 0; i < nt; i++) {
			if (ve[i] == exp)
				return vc[i];
		}
	}
	cout << "No existe termino con ese exponente\n";
}

void PoliV::asignar_coeficiente(int coef, int exp) {
	int dir_exp = buscar_exponente(exp);
	if (dir_exp != -1) {
		vc[dir_exp] = coef;
		if (coef == 0) {
			for (int i = dir_exp; i < nt; i++) {
				vc[i] = vc[i + 1];
				ve[i] = ve[i + 1];
			}
			nt--;
		}

	}
	else
		cout << "No existe ese termino\n";
}

void PoliV::poner_termino(int coef, int exp) {
	int dir_exp = buscar_exponente(exp);
	if (dir_exp == -1) {
		if (nt < MAX_VP && coef != 0) {
			vc[nt] = coef;
			ve[nt] = exp;
			nt++;
		}
	}
	else {
		int new_coef = coef + vc[dir_exp];
		vc[dir_exp] = new_coef;
		if (new_coef == 0) {
			for (int i = dir_exp; i < nt; i++) {
				vc[i] = vc[i + 1];
				ve[i] = ve[i + 1];
			}
			nt--;
		}
	}
}

int PoliV::numero_terminos() {
	return nt;
}

int PoliV::exponente(int nro_ter) {
	if (nro_ter > 0 && nro_ter <= nt)
		return ve[nro_ter - 1];
}

string PoliV::to_str() {
	string r = "";
	int n = numero_terminos();
	for (int i = 1; i <= n; i++) {
		int exp = exponente(i);
		int coef = coeficiente(exp);
		if (coef > 0)
			r += "+";
		r += to_string(coef) + "x^" + to_string(exp);
	}
	return r;
}

PoliV* PoliV::producto(PoliV* a, PoliV* b) {
	PoliV* p = new PoliV();
	for (int i = 1; i <= b->numero_terminos(); i++) {
		int expB = b->exponente(i);
		int coefB = b->coeficiente(expB);
		for (int j = 1; j <= a->numero_terminos(); j++) {
			int expA = a->exponente(j);
			int coefA = a->coeficiente(expA);
			int new_coef = coefA * coefB;
			int new_exp = expA + expB;
			p->poner_termino(new_coef, new_exp);
		}
	}
	return p;
}
