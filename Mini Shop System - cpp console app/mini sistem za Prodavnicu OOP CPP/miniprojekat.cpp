#include <iostream>
#include <string>
#define arrayNum 10
using namespace std;

class Proizvod {
protected:
	string naziv;
	float cena;
public:
	//konstruktor
	Proizvod(string naziv, float cena) {
		this->naziv = naziv;
		this->cena = cena;
	}
	
	//set
	void setNaziv(string naziv) {
		this->naziv = naziv;
	}
	void setCena(float cena) {
		this->cena = cena;
	}
	//get
	string getNaziv() {
		return this->naziv;
	}
	float getCena() {
		return this->cena;
	}

	//javna metoda
	void prikaziInfo() {
		cout << "== Informacija o proizvodu ==" << endl;
		cout << "Naziv proizvoda: " << this->naziv << " | cena: " << this->cena << " RSD | ";
	}
};

class Hrana : public Proizvod {
protected:
	string rokTrajanja;
public:
	//konstruktor
	Hrana(string naziv, float cena, string rokTrajanja) : Proizvod(naziv,cena) {
		this->rokTrajanja = rokTrajanja;
	}

	//public metoda
	void prikaziInfo() {
		Proizvod::prikaziInfo();
		cout << " rok trajanja: " << this->rokTrajanja << " | ";
	}
};

class Tehnika : public Proizvod {
protected:
	int garancija;
public:
	Tehnika(string naziv, float cena, int garancija) : Proizvod(naziv, cena) {
		this->garancija = garancija;
	}
	//public metoda
	void prikaziInfo() {
		Proizvod::prikaziInfo();
		cout << " duzina garancije: " << this->garancija << " | ";
	}
};

class Korpa {
protected:
	Hrana* hrana[10];
	int brHrane;

	Tehnika* tehnika[10];
	int brTehnike;

public:
	Korpa() {
		brHrane = 0;
		brTehnike = 0;
	}
	//javne metode
	void dodajHranu(Hrana* h) {
		if (brHrane < 100) {
			hrana[brHrane++] = h;
		}
	}
	void dodajTehniku(Tehnika* t) {
		if (brTehnike < 100) {
			tehnika[brTehnike++] = t;
		}
	}
	void prikaziSve() {
		cout << "Hrana u korpi:" << endl;
		for (int i = 0; i < brHrane; i++) {
			hrana[i]->prikaziInfo();
			cout << endl;
			cout << "----------------------------------------------------" << endl;
		}

		cout << "Tehnika u korpi: " << endl;
		for (int i = 0; i < brTehnike; i++) {
			tehnika[i]->prikaziInfo();
			cout << endl;
			cout << "----------------------------------------------------" << endl;
		}
	}

	float ukupnaCena() {
		float ukupno = 0;
		for (int i = 0; i < brHrane; i++) {
			ukupno += hrana[i]->getCena();
		}
		for (int i = 0; i < brTehnike; i++) {
			ukupno += tehnika[i]->getCena();
		}
		return ukupno;
	}
};

int main() {
	/*
	cout << "Unesi broj proizvoda [hrana]: "; cin >> brojHrana;
	cout << "Unesi broj proizvoda [tehnika]: "; cin >> brojTehnika;*/
	int brojHrane = 0, brojTehnike = 0;
	Hrana* hrana[arrayNum];
	Tehnika* tehnika[arrayNum];
	int izbor;
	int ukupnoProizvoda = 0;
	const int maxProizvoda = 10;
	do {
		cout << endl;
		cout << "-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|" << endl;
		cout << "\nUnesi opciju: \n 1.Dodaj hranu \n 2.Dodaj tehniku \n 3.Prikazi korpu \n 4.Obrisi proizvod \n 0. Izlaz" << endl;
		cout << endl;
		cout << "-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|" << endl;
		cout << endl;
		cout << "Unesi izbor: "; cin >> izbor;
		cout << endl;
		cin.ignore();

		if (izbor == 1) {
			string naziv, rok; float cena;
			cout << "-- UNOS HRANE --" << endl;
			cout << "Unesi naziv hrane: "; getline(cin, naziv);
			cout << "Unesi cenu hrane (RSD): "; cin >> cena;
			cin.ignore();
			cout << "Unesi rok hrane: "; getline(cin, rok);
			if (ukupnoProizvoda < maxProizvoda) {
				hrana[brojHrane++] = new Hrana(naziv, cena, rok);
				ukupnoProizvoda++;
				cout << "=============================" << endl;
				cout << "Trenutno imas " << ukupnoProizvoda << "/" << maxProizvoda << " proizvoda!" << endl;
				cout << "=============================" << endl;
			}
			else {
				cout << "Nema dovoljno mesta u korpi!" << endl;
			}
		}
		else if (izbor == 2) {
			string naziv; float cena; int garancija;
			cout << "-- UNOS TEHNIKE --" << endl;
			cout << "Unesi naziv tehnike: "; getline(cin, naziv);
			cout << "Unesi cenu tehnike (RSD): "; cin >> cena;
			cout << "Unesi garanciju (meseci) tehnike: "; cin >> garancija;
			cin.ignore();
			if (ukupnoProizvoda < maxProizvoda) {
				tehnika[brojTehnike++] = new Tehnika(naziv, cena, garancija);
				ukupnoProizvoda++;
				cout << "=============================" << endl;
				cout << "Trenutno imas " << ukupnoProizvoda << "/" << maxProizvoda << " proizvoda!" << endl;
				cout << "=============================" << endl;
			}
			else {
				cout << "Nema dovoljno mesta u korpi!" << endl;
			}
		}
		else if (izbor == 3) {
			int ukupnoKorpa = 1;
			cout << "== Hrana u korpi ==" << endl;
				for (int i = 0; i < brojHrane; i++) {
					cout << "[" << ukupnoKorpa++ << "] ";
					hrana[i]->prikaziInfo();
					cout << endl;
					cout << "------------------------------------------\n";		
				}
				cout << endl;
				cout << "== Tehnika u korpi ==" << endl;
				for (int i = 0; i < brojTehnike; i++) {
					cout << "[" << ukupnoKorpa++ << "] ";
					tehnika[i]->prikaziInfo();
					cout << endl;
					cout << "------------------------------------------\n";
				}
			float ukupno = 0;
			for (int i = 0; i < brojHrane; i++) {
				ukupno += hrana[i]->getCena();
			}
			for (int i = 0; i < brojTehnike; i++) {
				ukupno += tehnika[i]->getCena();
			}
			cout << "Ukupna cena: " << ukupno << " RSD\n";
			cout << "--------------------------------------------------------------" << endl;
			cout << "Ukupno namirnica smestenih u korpu [" << ukupnoProizvoda << "] , preostalo mesta u korpi [" << maxProizvoda - ukupnoProizvoda << "]" << endl;
		}
		else if (izbor == 4) {
			//delete
			int index;
			cout << "Unesi indeks proizvoda (1 - " << ukupnoProizvoda << ") : "; cin >> index; index--;
			if (index >= 0 && index < brojHrane) {
				delete hrana[index];

				for (int i = index; i < brojHrane - 1; i++) {
					hrana[i] = hrana[i + 1];
				}
				brojHrane--;
				ukupnoProizvoda--;
				cout << "------------------------------------------\n";
				cout << "Uspesno obrisan proizvod iz kategorije HRANA!" << endl;
				cout << "------------------------------------------\n";
			}
			else if (index >= brojHrane && index < brojHrane + brojTehnike) {
				
				int localIndex = index - brojHrane;
				delete tehnika[localIndex];
				for (int i = localIndex; i < brojTehnike - 1; i++) {
					tehnika[i] = tehnika[i + 1];
				}
				brojTehnike--;
				ukupnoProizvoda--;
				cout << "------------------------------------------\n";
				cout << "Uspesno obrisan proizvod iz kategorije TEHNIKA!" << endl;
				cout << "------------------------------------------\n";
			}
			else {
				cout << "Neispravan unos! Nema proizvoda pod tim rednim brojem." << endl;
			}
		}
	} while (izbor != 0);

	if (izbor == 0) {
		cout << endl;
		cout << "Izlaz..." << endl;
	}

	//oslobadanje resursa kreiranih istanci pri izlazu iz aplikacije
	for (int i = 0; i < brojHrane; i++) { delete hrana[i]; }
	for (int i = 0; i < brojTehnike; i++) { delete tehnika[i]; }


	//test
	/*Korpa korpa;

	Hrana* h1 = new Hrana("Jaja",15,"25.7.2025");
	Hrana* h2 = new Hrana("Mleko",130,"30.7.2025");
	Hrana* h3 = new Hrana("Sir",430,"17.7.2025");

	Tehnika* t1 = new Tehnika("Telefon",25000,24);

	korpa.dodajHranu(h1);
	cout << endl;
	korpa.dodajHranu(h2);
	cout << endl;
	korpa.dodajHranu(h3);
	cout << endl;
	korpa.dodajTehniku(t1);

	cout << endl;

	korpa.prikaziSve();


	cout << "Ukupna cena: " << korpa.ukupnaCena() << " RSD\n";

	delete h1;
	delete h2;
	delete t1;*/
	return 0;
}
