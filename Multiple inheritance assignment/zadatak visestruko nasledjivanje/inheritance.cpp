#include <iostream>
#include <string>
using namespace std;

class Zaposleni {
protected:
	string firma;
	float plata;
public:
	//konstruktor
	Zaposleni(string firma,float plata) {
		this->firma = firma;
		this->plata = plata;
	}
	void prikaziZaposlenog() {
		cout << "Firma: " << this->firma << endl;
		cout << "Plata: " << this->plata << "RSD" << endl;
	}
};

class Student {
protected:
	string fakultet;
	float prosek;
public:
	//konstruktor
	Student(string fakultet,float prosek) {
		this->fakultet = fakultet;
		this->prosek = prosek;
	}
	void prikaziStudenta() {
		cout << "Fakultet: " << this->fakultet << endl;
		cout << "Prosek: " << this->prosek << endl;
	}
};

class PametnaOsoba : public Zaposleni,Student {
protected:
	string ime;
	int godine;
public:
	//konstruktor
	PametnaOsoba(string ime,int godine,string firma, float plata, string fakultet, float prosek) : Zaposleni(firma,plata),Student(fakultet,prosek){
		this->ime = ime;
		this->godine = godine;
	}

	void prikaziOsobu() {
		cout << "Ime: " << this->ime << endl;
		cout << "Godine: " << this->godine << endl;
	}

	void prikaziSve(){
		prikaziZaposlenog();
		prikaziStudenta();
		prikaziOsobu();
	}
};



int main() {
	const int DuzinaNiza = 10;
	PametnaOsoba* osobe[DuzinaNiza];
	int brojOsoba; cout << "Unesi koliko pametnih osoba zelis dodati: "; cin >> brojOsoba;

	for (int i = 0; i < brojOsoba; i++) {
		string ime, firma, fakultet;
		int godine; float plata, prosek;
		cout << "---------------------------------------" << endl;
		cout << "Osoba broj " << i + 1 << ":" << endl;
		cout << "Unesi ime: "; cin >> ime;
		cout << "Unesi broj godina: "; cin >> godine;
		cin.ignore();
		cout << "Unesi fakultet: "; getline(cin, fakultet);
		cout << "Unesi prosek na fakultetu: "; cin >> prosek;
		cin.ignore();
		cout << "Unesi firmu za koju radis: "; getline(cin,firma);
		cout << "Unesi platu koju dobijas: "; cin >> plata;
		osobe[i] = new PametnaOsoba(ime, godine, firma, plata, fakultet, prosek);
	}
	cout << endl;
	char opcija;
	cout << "Da li zelis da prikazes unete pametne osobe (y - da, n - ne) ? "; 
	cin >> opcija;
	if (opcija == 'y' || opcija == 'Y') {
		cout << endl;
		cout << "=== Prikaz informacija za pametne osobe ===" << endl;
		cout << endl;
		for (int i = 0; i < brojOsoba; i++) {
			cout << "-----------------------------------------" << endl;
			cout << "Osoba [" << i + 1 << "]: " << endl;
			osobe[i]->prikaziSve();
			cout << "-----------------------------------------" << endl;
			cout << endl;
		}
	}
	else if (opcija == 'n' || opcija == 'N') {
		cout << "Izlaz iz programa...";
	}
	else {
		cout << "Uneo si nevazecu opciju!" << endl;
	}

	for (int i = 0; i < brojOsoba; i++) { delete osobe[i]; }
	/*PametnaOsoba p1("Mihajlo",21,"Comtrade",96000,"Elektronski Fakultet Nis",9.67);
	p1.prikaziSve();*/
	return 0;
}