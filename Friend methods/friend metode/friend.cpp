#include <iostream>
#include <string>

using namespace std;

class Klasa {
private:
	short godine;
	string ime;
public:
	Klasa(short brGod,string imeKlasa) {
		godine = brGod;
		ime = imeKlasa;
	}

	//deklaracija friend metode
	friend void printPodaci(Klasa obj);
	//klasicna metoda
	void zdravo() {
		cout << "Funkcija zavrsena!" << endl;
	}
	
};

class Upored {
private:
	int broj1;
	int broj2;
public:
	//konstuktor
	Upored(int numOne,int numtwo) {
		broj1 = numOne;
		broj2 = numtwo;
	}

	friend void uporediBrojeve(Upored obj);

};

void printPodaci(Klasa obj) {
	cout << "Printovanje podataka: " << endl;
	cout << "Ime: " << obj.ime << endl;
	cout << "Broj godina: " << obj.godine << endl;
	obj.zdravo();
}

void uporediBrojeve(Upored obj) {
	try {
		if (obj.broj1 > obj.broj2) {
			cout << "Broj " << obj.broj1 << " je veci od broja " << obj.broj2 << endl;
		}
		else if (obj.broj1 < obj.broj2) {
			cout << "Broj " << obj.broj1 << " je manji od broja " << obj.broj2 << endl;
		}
		else {
			cout << "Broj " << obj.broj1 << " je jednak broju " << obj.broj2 << endl;
		}
	}
	catch (exception) {
		throw new exception;
	}
}

int main() {
	/*Klasa objekat(17,"Mihajlo");
	printPodaci(objekat);*/
	Upored objekat(5,5);
	uporediBrojeve(objekat);
	return 0;
}