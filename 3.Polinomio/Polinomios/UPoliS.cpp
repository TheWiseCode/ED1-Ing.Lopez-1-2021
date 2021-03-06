// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoliS.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliS::PoliS() {
    mem = new CSMemoria();
	ptr_poli = NULO;
	nt = 0;
}

PoliS::PoliS(CSMemoria* m) {
	mem = m;
	ptr_poli = NULO;
	nt = 0;
}

int PoliS::buscar_exponente(int exp) {
	int aux = ptr_poli;
	while (aux != NULO) {
        int aux_exp = mem->obtener_dato(aux, expPo);
		if (aux_exp == exp)
			return aux;
		aux = mem->obtener_dato(aux, sigPo);//aux->sig;
	}
	return NULO;
}

int PoliS::buscar_termino_n(int i) {
	int c = 1;
	int aux = ptr_poli;
	while (aux != NULO) {
		if (c == i)
			return aux;
		c++;
		aux = mem->obtener_dato(aux, sigPo);//aux->sig;
	}
	return NULO;
}

bool PoliS::es_cero() {
	return ptr_poli == NULO;
}

int PoliS::grado() {
	if (!es_cero()) {
		int max = mem->obtener_dato(ptr_poli, expPo);//ptr_poli->exp;
		int aux = ptr_poli;
		while (aux != NULO) {
            int aux_exp = mem->obtener_dato(aux, expPo);
			if (aux_exp > max)
				max = aux_exp;
			aux = mem->obtener_dato(aux, sigPo);
		}
        return max;
	}
}

int PoliS::coeficiente(int exp) {
	int dir = buscar_exponente(exp);
	if (dir != NULO)
		return mem->obtener_dato(dir, coefPo);//dir->coef;
	else
		cout << "No existe ese termino" << endl;
}

int PoliS::anterior(int dir) {
	int aux = ptr_poli;
	int ant = NULO;
	while (aux != NULO && aux != dir) {
		ant = aux;
		aux = mem->obtener_dato(aux, sigPo);
	}
	return ant;
}

void PoliS::suprime(int dir) {
	if (dir == ptr_poli) {
		ptr_poli = mem->obtener_dato(ptr_poli, sigPo);//ptr_poli->sig;
	}
	else {
		// --
		int aux = ptr_poli;
		int ant = NULO;
		while (aux != NULO && aux != dir) {
			ant = aux;
			aux = mem->obtener_dato(aux, sigPo);
		}
		// --
		int ante = ant;
        int dir_sig = mem->obtener_dato(dir, sigPo);
        mem->poner_dato(ante, sigPo, dir_sig);
		//ante->sig = dir->sig;
	}
	mem->delete_espacio(dir);
    //delete(dir);
}

void PoliS::asignar_coeficiente(int coef, int exp) {
	int dir = buscar_exponente(exp);
	if (dir != NULO) {
        mem->poner_dato(dir, coefPo, coef);
		//dir->coef = coef;
		if (coef == 0){
			suprime(dir);
            nt--;
		}
	}
}

void PoliS::poner_termino(int coef, int exp) {
	int dir = buscar_exponente(exp);
	if (dir == NULO) {
		if (coef != 0) {
			//int nuevo = new NodoPo();
            int nuevo = mem->new_espacio(datosPo);
            mem->poner_dato(nuevo, coefPo, coef);
			//nuevo->coef = coef;
            mem->poner_dato(nuevo, expPo, exp);
			//nuevo->exp = exp;
            mem->poner_dato(nuevo, sigPo, ptr_poli);
			//nuevo->sig = ptr_poli;
			ptr_poli = nuevo;
            nt++;
		}
	}
	else {
		//int new_coef = coef + dir->coef;
		int new_coef = coef + mem->obtener_dato(dir, coefPo);
		//dir->coef = new_coef;
        mem->poner_dato(dir, coefPo, new_coef);
		if (new_coef == 0){
			suprime(dir);
            nt--;
		}
	}
}

int PoliS::numero_terminos() {
	return nt;
}

int PoliS::exponente(int nro_ter) {
	int dir = buscar_termino_n(nro_ter);
	if (dir != NULO)
		return mem->obtener_dato(dir, expPo);//dir->exp;
	else
		cout << "No existe ese termino" << endl;
}

string PoliS::to_str() {
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

void PoliS::mostrar_integral() {
	for (int i = 0; i < numero_terminos(); i++) {
		int exp = exponente(i + 1);
		int coef = coeficiente(exp);
		cout << "("<<coef << "x^" << (exp+1)<<")/"<<(exp+1);
		if(i < numero_terminos() - 1)
			cout << "+";
	}
	cout << endl;
}
