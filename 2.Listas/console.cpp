#include <iostream>
#include <string>
#include "UListaV.h"
#include "UListaP.h"
#include "UListaS.h"

using namespace std;

void menuV();
void menuP();
void menuS();

int main() {
	menuS();
	system("pause");
	return 0;
}

void menuV() {
	ListaV* list;
	int opcion;
	do {
		cout << "1.Crear Lista\n";
		cout << "2.Insertar inicio\n";
		cout << "3.Insertar final\n";
		cout << "4.Mostrar\n";
		cout << "5.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				list = new ListaV();
			} break;
		case 2: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_primero(e);
			} break;
		case 3: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_ultimo(e);
			} break;
		case 4: {
				cout << list->to_str() << endl;
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 5);
}

void menuP() {
	ListaP* list;
	int opcion;
	do {
		cout << "1.Crear Lista\n";
		cout << "2.Insertar inicio\n";
		cout << "3.Insertar final\n";
		cout << "4.Mostrar\n";
		cout << "5.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				list = new ListaP();
			} break;
		case 2: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_primero(e);
			} break;
		case 3: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_ultimo(e);
			} break;
		case 4: {
				cout << list->to_str() << endl;
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 5);
}

void menuS() {
	ListaS* list;
	CSMemoria* mem;
	int opcion;
	do {
		cout << "1.Crear Memoria\n";
		cout << "2.Pedir espacio\n";
		cout << "3.Liberar espacio\n";
		cout << "4.Crear Lista\n";
		cout << "5.Insertar inicio\n";
		cout << "6.Insertar final\n";
		cout << "7.Mostrar memoria\n";
		cout << "8.Mostrar lista\n";
		cout << "9.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				mem = new CSMemoria();
			} break;
		case 2: {
				string ids;
				cin.ignore();
				cout << "IDS a guardar: ";
				getline(cin, ids);
				mem->new_espacio(ids);
			} break;
		case 3: {
				int dir;
				cout << "Direccion a liberar\n";
				cin >> dir;
				mem->delete_espacio(dir);
			} break;
		case 4: {
				list = new ListaS(mem);
			} break;
		case 5: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_primero(e);
			} break;
		case 6: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_ultimo(e);
			} break;
		case 7: {
				mem->mostrar();
			} break;
		case 8: {
				cout << list->to_str() << endl;
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 9);
}

