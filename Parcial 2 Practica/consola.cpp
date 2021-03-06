#include <iostream>
#include "UMemoria.h"
#include "UListaS.h"
#include "UDicola1.h"
#include "UPilaD.h"
#include "UColaP.h"

using namespace std;

string infija_postfija(string infija);
int evaluar_postfija(string exp);
void invertir(PilaD* p);

int main() {
	PilaD* p = new PilaD();
	p->meter(1);
	p->meter(2);
	p->meter(3);
	p->meter(4);
	cout << p->to_str() << endl;
	invertir(p);
	cout << p->to_str() << endl;
	system("pause");
	return 0;
}

void invertir(PilaD* p) {
	ColaP* aux = new ColaP();
	while (!p->vacia()) {
		int e;
		p->sacar(e);
		aux->poner(e);
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		p->meter(e);
	}
}

void pregu2() {
	string exp = "(20+3)*5";
	string postfija = infija_postfija(exp);
	cout << postfija << endl;
	int valor = evaluar_postfija(postfija);
	cout << valor << endl;
}

bool es_operador(char c) {
	char opers[] = {'^', '*', '/', '+', '-', '('};
	for (int i = 0; i < 6; i++) {
		if (opers[i] == c)
			return true;
	}
	return false;
}

int prioridad_infija(char c) {
	if (c == '^')
		return 4;
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	if (c == '(')
		return 5;
}

int prioridad_pila(char c) {
	if (c == '^')
		return 3;
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	if (c == '(')
		return 0;
}

// (20+3)*5
string infija_postfija(string infija) {
	PilaD p;
	string postfija = "";
	for (int i = 0; i < infija.length(); i++) {
		char c = infija[i];
		if (c >= '0' && c <= '9') {
			string num = "";
			while (c >= '0' && c <= '9') {
				num += c;
				i++;
				c = infija[i];
			}
			i--;
			postfija += num;
			postfija += " ";
		}
		else {
			if (es_operador(c)) {
				bool salir = false;
				while (!salir) {
					char aux = p.cima();
					if (p.vacia() || (prioridad_infija(c) >
						prioridad_pila(aux))) {
						p.meter(c);
						salir = true;
					}
					else {
						int x;
						p.sacar(x);
						postfija += x;
					}
				}
			}
			else {
				if (c == ')') {
					int aux;
					do {
						p.sacar(aux);
						if (aux != '(')
							postfija += aux;
					}
					while (aux != '(');
				}
			}
		}

	}
	while (!p.vacia()) {
		int aux;
		p.sacar(aux);
		postfija += aux;
	}
	return postfija;
}

int evalua(int a, int b, char c) {
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	if (c == '/')
		return a / b;
	if (c == '^')
		return pow(a, b);
}

int evaluar_postfija(string exp) {
	PilaD p;
	for (int i = 0; i < exp.length(); i++) {
		char c = exp[i];
		if (c >= '0' && c <= '9') {
			string num = "";
			while (c >= '0' && c <= '9') {
				num += c;
				i++;
				c = exp[i];
			}
			i--;
			int n = atoi(num.c_str());
			p.meter(n);
		}
		else {
			if (es_operador(c)) {
				int op1, op2;
				p.sacar(op2);
				p.sacar(op1);
				int z = evalua(op1, op2, c);
				p.meter(z);
			}
		}
	}
	return p.cima();
}

void pregu1() {
	Dicola1* d = new Dicola1();
	d->poner(1);
	d->poner(2);
	d->poner(3);
	d->poner(4);
	d->poner_frente(5);
	cout << d->to_str() << endl;
	cout << d->ultimo() << endl; ;
	cout << d->to_str() << endl;
}
