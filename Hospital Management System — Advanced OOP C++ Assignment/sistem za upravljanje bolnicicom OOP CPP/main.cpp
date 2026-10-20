#include <iostream>
#include <string>
using namespace std;

class Osoba {
protected:
	string ime, prezime;
	int godine;
public:
	//konstruktor
	Osoba(string ime, string prezime, int godine) {
		this->ime = ime;
		this->prezime = prezime;
		this->godine = godine;
	}
	//destruktor
	~Osoba() {
		cout << "DESTRUKTOR : ON" << endl;
	}
	virtual void prikaziInfo() = 0;
};

class Pacijent : public Osoba {
protected:
	int IDKartona;
	float temperatura;
	string dijagnoza;
public:
	//konstruktor
	Pacijent(string ime,string prezime,int godine,int IDKartona,float temperatura,string dijagnoza) 
		: Osoba(ime, prezime, godine) {
		this->IDKartona = IDKartona;
		this->temperatura = temperatura;
		this->dijagnoza = dijagnoza;
	}
	//destruktor
	~Pacijent() {
		cout << "DESTRUKTOR: ON" << endl;
	}
	void prikaziInfo() override {
		cout << "== Pacijent ==" << endl;
		cout << "ID kartona: " << this->IDKartona << " | ";
		cout << "Temperatura: " << this->temperatura << " | ";
		cout << "Dijagnoza: " << this->dijagnoza << endl;
	}
	friend void izmeniDijagnozu(Pacijent& p ,string novaDijagnoza);
};

class Doktor : public Osoba {
protected:
	string specijalizacija;
	int brojGodinaIskustva;
public:
	//konstruktor
	Doktor(string ime, string prezime, int godine,string specijalizacija,int brojGodinaIskustva)
		: Osoba(ime,prezime,godine) {
		this->brojGodinaIskustva = brojGodinaIskustva;
		this->specijalizacija = specijalizacija;
	}
	//destruktor
	~Doktor() {
		cout << "DESTRUKTOR: ON" << endl;
	}
	void prikaziInfo() override {
		cout << "== Doktor ==" << endl;
		cout << "Specijalizacija: " << this->specijalizacija << " | ";
		cout << "broj godina iskustva: " << this->brojGodinaIskustva << " | ";
	}
};

class Bolnica {
protected:
	Pacijent** pacijenti;
	Doktor** doktori;
	int brojDoktora,brojPacijenta,kapacitet;
public:
	//konstruktor
	Bolnica(int kapacitet) {
		this->brojDoktora = 0;
		this->brojPacijenta = 0;
		this->kapacitet = kapacitet;
		this->pacijenti = new Pacijent * [kapacitet];
		this->doktori = new Doktor * [kapacitet];
	}
	~Bolnica() {
		obrisiSve();
	}
	void dodajPacijenta(Pacijent* p) {
		if (brojPacijenta < kapacitet) {
			pacijenti[brojPacijenta++] = p;
		}
		else {
			cout << "Nema dovoljno mesta za pacijente u bolnici..." << endl;
		}
	}
	void dodajDoktora(Doktor* d) {
		if (brojDoktora < kapacitet) {
			doktori[brojDoktora++] = d;
		} else {
			cout << "Nema dovoljno mesta za dodavanje zaposlenog -> Doktor" << endl;
		}
	}
	void prikaziSveOsobe() {
		cout << "== PRIKAZ PACIJENTA ==" << endl;
		for (int i = 0; i < brojPacijenta; i++) {
			pacijenti[i]->prikaziInfo();
		}
		cout << endl;
		cout << "== PRIKAZ DOKTORA ==" << endl;
		for (int i = 0; i < brojDoktora; i++) {
			doktori[i]->prikaziInfo();
		}
	}
	void obrisiSve() {
		//brisanje niza pacijenta
		for (int i = 0; i < brojPacijenta; i++) {
			delete pacijenti[i];
		}
		brojPacijenta = 0;
		//brisanje niza doktora
		for (int i = 0; i < brojDoktora; i++) {
			delete doktori[i];
		}
		brojDoktora = 0;
		delete[] pacijenti;
		delete[] doktori;

		pacijenti = nullptr;
		doktori = nullptr;

		cout << "Svi podaci su obrisani." << endl;
	}
};

void izmeniDijagnozu(Pacijent& p, string novaDijagnoza) {
	p.dijagnoza = novaDijagnoza;
}

int main() {
		Bolnica bolnica(10);

		Pacijent* p1 = new Pacijent("Milan", "Mikic", 45, 1001, 38.2, "Grip");
		Pacijent* p2 = new Pacijent("Ana", "Anic", 30, 1002, 37.4, "Prehlada");

		bolnica.dodajPacijenta(p1);
		bolnica.dodajPacijenta(p2);

		Doktor* d1 = new Doktor("Dragan", "Petrovic", 50, "Kardiolog", 20);
		Doktor* d2 = new Doktor("Ivana", "Ilic", 39, "Pediatar", 12);

		bolnica.dodajDoktora(d1);
		bolnica.dodajDoktora(d2);

		cout << "\n--- Trenutno stanje u bolnici ---\n";
		bolnica.prikaziSveOsobe();

		cout << "\n--- Azuriranje dijagnoze pacijentu 1001 ---\n";
		izmeniDijagnozu(*p1, "Upala pluca");

		cout << "\n--- Nakon izmene dijagnoze ---\n";
		bolnica.prikaziSveOsobe();

		cout << "\n--- Brisanje svih podataka ---\n";
		bolnica.obrisiSve();

		return 0;
}

