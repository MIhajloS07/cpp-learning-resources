#include <iostream>
#include <string>
using namespace std;

class Covek {
public:
	string ime;
	short brojGodina;
	
	void ispis() {
		cout << ime << endl;
		cout << brojGodina << endl;
	}

	void ispisIme() {
		cout << "Tvoje ime je: " << ime << endl;
	}
};

int main() {
	Covek* obj1 = new Covek(); 
	obj1->brojGodina = 16;
	obj1->ime = "kimca";
	obj1->ispis();
	delete obj1;

	return 0;
}