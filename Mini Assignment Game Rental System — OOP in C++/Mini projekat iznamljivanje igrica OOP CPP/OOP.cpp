#include <iostream>
#include <string>
using namespace std;

//bazna klasa
class Igrica{
protected:
	string naziv,zanr;
	int godina;
public:
	Igrica(string naziv,string zanr,int godina) {
		this->naziv = naziv;
		this->zanr = zanr;
		this->godina = godina;
	}
	void prikaziInfo() {
		cout << " == INFORMACIJE O IGRICI ==" << endl;
		cout << "Naziv: " << this->naziv << " | ";
		cout << "Zanr: " << this->zanr << " | ";
		cout << "Godina proizvodnje: " << this->godina;
	}
};

class PcIgrica : public Igrica {
protected:
	string minimalnaKonfiguracija;
public:
	PcIgrica(string naziv, int godina, string zanr, string minimalnaKonfiguracija) : Igrica(naziv, zanr, godina) {
		this->minimalnaKonfiguracija = minimalnaKonfiguracija;
	}
	void prikaziInfo() {
		Igrica::prikaziInfo(); //poziv metode iz bazne klase
		cout << " | " << this->minimalnaKonfiguracija;
	}
	~PcIgrica() {}
};


class KonzolnaIgrica : public Igrica {
protected:
	string tipKonzole;
public:
	KonzolnaIgrica(string naziv,int godina,string zanr,string tipKonzole) : Igrica(naziv,zanr,godina){
		this->tipKonzole = tipKonzole;
	}
	void prikaziInfo() {
		Igrica::prikaziInfo(); //poziv metode iz bazne klase
		cout << " | " << this->tipKonzole;
	}
	~KonzolnaIgrica() {}
};

class Korisnik {
protected:
	string ime;
	int brojIgrica;
	Igrica** igrice;
	int kapacitet;
public:
	Korisnik(string ime, int kapacitet = 10) {
		this->ime = ime;
		this->kapacitet = kapacitet;
		this->brojIgrica = 0;
		igrice = new Igrica*[kapacitet];
	}
	void dodajIgricu(Igrica* novaIgrica) {
		if (brojIgrica < kapacitet) {
			igrice[brojIgrica++] = novaIgrica;
		}
		else {
			cout << "Nema vise mesta za igrice!" << endl;
		}
	}
	void prikaziKorisnika() {
		cout << "Korisnik: " << this->ime << endl;
		for (int i = 0; i < brojIgrica; i++) 
			igrice[i]->prikaziInfo();
	}
	~Korisnik(){ delete[] igrice; }
};

int main(){

	PcIgrica* g1 = new PcIgrica("Minecraft", 2011, "Sandbox", "Intel i3, 4GB RAM");
	KonzolnaIgrica* g2 = new KonzolnaIgrica("FIFA 21", 2020, "Sportska", "PlayStation");
	

	g1->prikaziInfo();
	cout << endl;

	cout << endl;

	Korisnik korisnik("Mihajlo");
	korisnik.dodajIgricu(g1);
	korisnik.dodajIgricu(g2);
	korisnik.prikaziKorisnika();
	
	return 0;
}