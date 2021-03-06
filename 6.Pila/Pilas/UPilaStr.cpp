// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPilaStr.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaStr::PilaStr() {
	k = "";
}

bool PilaStr::vacia() {
	return k == "";
}

void PilaStr::meter(int e) {
	k = to_string(e) + "," + k;
}

void PilaStr::sacar(int& e) {
	if (!vacia()) {
		int pos = k.find_first_of(",");
		string sub = k.substr(0, pos);
		e = atoi(sub.c_str());
		k.erase(0, pos + 1);
	}
}

int PilaStr::cima() {
	if (!vacia()) {
		int pos = k.find_first_of(",");
		string sub = k.substr(0, pos);
		return atoi(sub.c_str());
	}
}

string PilaStr::to_str() {
	string r = "";
	PilaStr* aux = new PilaStr();
	while (!vacia()) {
		int e;
		sacar(e);
		r += "| " + to_string(e) + " |\n";
		aux->meter(e);
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
	r += "+---+\n";
	return r;
}
