// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoli1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void Poli1::poner_termino(int coef, int exp) {
	if (k->vacia()) { // Polinomio vacio
		k->inserta_ultimo(exp);
		k->inserta_ultimo(coef);
		k->inserta_ultimo(exp);
	}
	else { // Tiene datos
		// ----Buscar si existe el exp
		NodoL* aux = k->siguiente(k->primero());
		NodoL* res = NULL;
		while (aux != NULL) {
			NodoL* aux2 = k->siguiente(aux);
			if (exp == k->recupera(aux2)) {
				res = aux;
				break;
			}
			aux = k->siguiente(k->siguiente(aux));
		}
		// ----
		if (res == NULL) { // EXP NO EST?
			k->inserta_ultimo(coef);
			k->inserta_ultimo(exp);
			int grado = k->recupera(k->primero());
			if (exp > grado) // SE ACTUALIZA EL GRADO
					k->modifica(k->primero(), exp);
		}
		else { // EXP EST?
			int suma = k->recupera(aux) + coef;
			k->modifica(aux, suma);
			if (suma == 0) { // SE TIENE QUE SUPRIMIR
				NodoL* sig = k->siguiente(aux);
				k->suprime(sig);
				k->suprime(aux);
				int grado = k->recupera(k->primero());
				if (exp == grado) { // SE ACTUALIZA EL GRADO
					// ----Buscar si existe el exp
					NodoL* aux = k->siguiente(k->primero());
					int nuevoGrado = 0;
					while (aux != NULL) {
						NodoL* aux2 = k->siguiente(aux);
						if (k->recupera(aux2) > nuevoGrado)
							nuevoGrado = k->recupera(aux2);
						aux = k->siguiente(k->siguiente(aux));
					}
					// ----
					k->modifica(k->primero(), nuevoGrado);
				}
				if(k->longitud() == 1)//QUEDO VACIO, VACIAR
                    k->suprime(k->primero());
			}
		}
	}
}
