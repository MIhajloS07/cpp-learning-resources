#include <iostream>
#include <string>
using namespace std;

class Zaposleni {
protected:
	string ime;
	int godine;
public:
	//konstruktor
	Zaposleni(string ime,int godine) {
		this->ime = ime;
		this->godine = godine;
	}
	//setteri
	void setIme(string ime){
		this->ime = ime;
	}
	void setGodine(int godine) {
		this->godine = godine;
	}
	//getter
	string getIme() {
		return ime;
	}
	int getGodine() {
		return godine;
	}
};

class Programer : protected Zaposleni {
private:
	string programskiJezik;
public:
	Programer(string ime, string programskiJezik, int godine) : Zaposleni(ime,godine) {
		this->programskiJezik = programskiJezik;
	}
	//setter
	void setJezik(string programskiJezik) {
		this->programskiJezik = programskiJezik;
	}
	//getter
	string getJezik() {
		return programskiJezik;
	}

	//metoda koja poziva metode iz osnovne klase radi pristupa
	void unesiPodatke(string ime, string programskiJezik, int godine) {
		setIme(ime);
		setGodine(godine);
		setJezik(programskiJezik);
	}

	//metoda za ispis podataka
	void prikaziPodatke() {
		cout << "Ime: " << ime << endl;
		cout << "Godine: " << godine << endl;
		cout << "Programski jezik: " << programskiJezik << endl;
	}
};

int main() {
	Programer p("Mihajlo", "C++", 17);
	p.prikaziPodatke();
	return 0;
}