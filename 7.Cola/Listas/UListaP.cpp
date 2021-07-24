// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaP::ListaP() {
	ptr_elementos = NULL;
	longit = 0;
}

direccionP ListaP::fin() {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		direccionP x = ptr_elementos;
		direccionP ptr_fin;
		while (x != NULL) {
			ptr_fin = x;
			x = x->sig;
		}
		return ptr_fin;
	}
}

direccionP ListaP::primero() {
	if (!vacia())
		return ptr_elementos;
	else
		return NULL;
}

direccionP ListaP::siguiente(direccionP d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == fin()) {
			//cout << "ERROR: DIRECCION ERRONEA\n";
			return NULL;
		}
		else
			return d->sig;
	}
}

direccionP ListaP::anterior(direccionP d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == primero())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else {
			direccionP x = ptr_elementos;
			direccionP ant = NULL;
			while (x != NULL) {
				if (x == d)
					return ant;
				ant = x;
				x = x->sig;
			}
			return NULL;
		}
	}
}

bool ListaP::vacia() {
	return longit == 0;
}

int ListaP::recupera(direccionP d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		return d->elemento;
}

int ListaP::longitud() {
	return longit;
}

void ListaP::inserta(direccionP d, int e) {
	NodoL* x = new NodoL;
	if (x != NULL) {
		x->elemento = e;
		x->sig = NULL;
		if (vacia()) {
			ptr_elementos = x;
			longit = 1;
		}
		else {
			longit++;
			if (d == primero()) {
				x->sig = d;
				ptr_elementos = x;
			}
			else {
				direccionP ant = anterior(d);
				ant->sig = x;
				x->sig = d;
			}

		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaP::inserta_primero(int e) {
	NodoL* x = new NodoL;
	if (x != NULL) {
		x->elemento = e;
		x->sig = ptr_elementos;
		ptr_elementos = x;
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaP::inserta_ultimo(int e) {
	NodoL* x = new NodoL;
	if (x != NULL) {
		x->elemento = e;
		x->sig = NULL;
		if (vacia())
			ptr_elementos = x;
		else
			fin()->sig = x;
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaP::suprime(direccionP d) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (d == ptr_elementos) {
		direccionP x = ptr_elementos;
		ptr_elementos = ptr_elementos->sig;
		delete(x);
	}
	else {
		direccionP ant = anterior(d);
		ant->sig = d->sig;
		delete(d);
	}
	longit--;
}

void ListaP::modifica(direccionP d, int e) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		d->elemento = e;
}

/*
 Recorrer con punteros
 direccion aux = ptr_elementos;
 while(aux != NULL){
 aux = aux->sig;
 }
 */
string ListaP::to_str() {
	string s = "[";
	direccionP aux = ptr_elementos;
	while (aux != NULL) {
		int el = aux->elemento;
		s += to_string(el);
		aux = aux->sig;
		if (aux != NULL)
			s += ",";
	}
	return s + "]";
}

direccionP ListaP::localiza(int e) {
	direccionP aux = ptr_elementos;
	while (aux != NULL) {
		if (aux->elemento == e)
			return aux;
		aux = aux->sig;
	}
	return NULL;
}

void ListaP::elimina_dato(int e) {
	direccionP aux = ptr_elementos;
	while (aux != NULL) {
		if (aux->elemento == e) {
			direccionP sup = aux;
			aux = aux->sig;
			suprime(sup);
		}
		else
			aux = aux->sig;
	}
}

void ListaP::anula() {
	while (!vacia())
		suprime(primero());
}
