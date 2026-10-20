#include <iostream>
#include <string>
using namespace std;

class Zaposleni {
protected:
	int godine;
	float plata;
	string ime;
public:
	Zaposleni(string ime,int godine,float plata) {
		this->ime = ime;
		this->godine = godine;
		this->plata = plata;
	}

	string getIme() {
		return this->ime;
	}

	virtual void prikaziInfo() {
		cout << endl;
		cout << "== Prikaz zaposlenog ==" << endl;
		cout << "Ime: " << this->ime << " | ";
		cout << "Godine: " << this->godine << " | ";
		cout << "Plata: " << this->plata << "RSD ";
	}
};

class Direktor : public Zaposleni {
protected:
	string sektor;
	float bonus;
public:
	Direktor(string ime, int godine, float plata, string sektor, int bonus) 
		: Zaposleni(ime, godine, plata) {
		this->sektor = sektor;
		this->bonus = bonus;
	}
	void prikaziInfo() override {
		Zaposleni::prikaziInfo();
		cout << " | Sektor: " << this->sektor << " | ";
		cout << "Bonus: " << this->bonus << "RSD " << endl;
	}
};

class Radnik : public Zaposleni {
protected:
	string pozicija;
	int radnoVreme;
public:
	Radnik(string ime, int godine, float plata,string pozicija,int radnoVreme) 
		: Zaposleni(ime,godine,plata) {
		this->pozicija = pozicija;
		this->radnoVreme = radnoVreme;
	}
	void prikaziInfo() override {
		Zaposleni::prikaziInfo();
		cout << " | Pozicija: " << this->pozicija << " | ";
		cout << "Radno vreme: " << this->radnoVreme << "h ";
	}
};

class Firma {
protected:
	Direktor* direktor;
	Zaposleni** radnici;
	int brojRadnika;
	int kapacitet;
public:
	Firma(int kapacitet){
		this->kapacitet = kapacitet;
		brojRadnika = 0;
		radnici = new Zaposleni*[kapacitet];
		direktor = nullptr;
	}
	void dodajRadnika(Radnik* r) {
		if (brojRadnika < kapacitet) {
			radnici[brojRadnika++] = r;
		} else {
			cout << "-- Nema dovoljno mesta --" << endl;
		}
	}
	void dodajDirektora(Direktor* d) {
		if (direktor != nullptr) {
			delete direktor;
		}
		direktor = d;
	}
	void prikaziZaposlene() {
		if (direktor) {
			cout << "== Direktor ==" << endl;
			direktor->prikaziInfo();
		}
		cout << endl;
		cout << "== Radnici ==" << endl;
		for (int i = 0; i < brojRadnika; i++) {
			radnici[i]->prikaziInfo();
		}
	}
	void pretraziRadnikaPoImenu(string trazenoIme) {
		bool pronadjen = false;
		for (int i = 0; i < brojRadnika; i++) {
			if (radnici[i]->getIme() == trazenoIme) {
				cout << "-- Radnik pronadjen --" << endl;
				radnici[i]->prikaziInfo();
				pronadjen = true;
				break;
			} 
			if (!pronadjen){
				cout << "Radnik sa imenom " << trazenoIme << " nije pronadjen" << endl;
				break;
			}
		}
	}
	~Firma() {
		delete direktor;
		for (int i = 0; i < brojRadnika; i++)
			delete radnici[i];
		delete[] radnici;
	}
};

int main() {
	Firma f(10); // maksimalno 10 radnika
	f.dodajDirektora(new Direktor("Milica", 50, 150000, "Menadzment", 20000));
	cout << endl;
	f.dodajRadnika(new Radnik("Petar", 28, 70000, "Programer", 8));
	cout << endl;
	f.dodajRadnika(new Radnik("Ivana", 32, 68000, "Dizajner", 7));
	cout << endl;
	f.prikaziZaposlene();
	cout << endl;

	char opcija;
	cout << "Da li zelis da pronadjes nekog radnika ? (y-da,bilo sta drugo - ne): "; cin >> opcija;
	if (opcija == 'y') {
		string trazenoIme;
		cout << "Unesi trazeno ime: "; cin >> trazenoIme;
		f.pretraziRadnikaPoImenu(trazenoIme);
	} else {
		cout << "Izlaz..." << endl;
	}
	return 0;
}