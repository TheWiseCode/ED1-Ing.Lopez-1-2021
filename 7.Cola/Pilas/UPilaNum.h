//---------------------------------------------------------------------------

#ifndef UPilaNumH
#define UPilaNumH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

class PilaNum{
	private:
		int datos;
	public:
		PilaNum();
		bool vacia();
		void meter(int e);
		void sacar(int& e);
		int cima();
		string to_str();
};
#endif
