#include <iostream>
#include <string>
using namespace std;

class Klasa {
public:
	//konstruktor
	Klasa() {
		cout << "Kreiranje instance (objekta) klase..." << endl;
	}
	//destruktor - specijalna metoda unutar klase koja se automatski poziva i unistava objekat kada izadje iz opsega radi oslobadjanja resursa koje je objekat koristio
	~Klasa() {
		cout << "Unistavanje kreiranog objekta..." << endl;
	}
};

int main() {
	Klasa klasa1;
	return 0;
}