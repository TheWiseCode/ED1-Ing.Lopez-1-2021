#include <iostream>
#include "UPilaNum.h"
#include "UPilaStr.h"
#include "UPilaPInv.h"

using namespace std;

int main() {
	PilaPInv* p = new PilaPInv();
	p->meter(1);
	p->meter(2);
	p->meter(3);
	p->meter(4);
	p->meter(5);
	p->meter(11);
	cout << p->to_str() << endl;
	system("pause");
	return 0;
}
