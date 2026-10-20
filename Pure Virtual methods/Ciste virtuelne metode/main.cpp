#include <iostream>
#include <string>
using namespace std;

//abstraktna klasa
class Primarna {
public:
	//cista virtuelna metoda i tada klasa postaje apstraktna
	virtual void info() = 0;
};

class Sekundarna : public Primarna{
public:
	void info() {
		cout << "Funkcionalna metoda" << endl;
	}
};

int main() {
	Sekundarna obj;
	obj.info();
	return 0;
}