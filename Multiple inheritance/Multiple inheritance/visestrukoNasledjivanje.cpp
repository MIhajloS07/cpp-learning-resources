#include <iostream>
#include <string>
using namespace std;

class imeKlasa {
public:
	string ime;
	void printIme() {
		cout << "Ime: " << ime << endl;
	}
};

class prezimeKlasa {
public:
	string prezime;
	void printPrezime() {
		cout << "Prezime: " << prezime << endl;
	}
};

class Lice : public imeKlasa,prezimeKlasa {
public:

	//setter
	void setPodatke(string ime,string prezime) {
		this->ime = ime;
		this->prezime = prezime;
	}

	void globalPrint() {
		printIme();
		printPrezime();
	}

};

int main() {
	Lice obj;
	obj.setPodatke("Zoran","Stoiljkovic");
	obj.globalPrint();
	return 0;
}