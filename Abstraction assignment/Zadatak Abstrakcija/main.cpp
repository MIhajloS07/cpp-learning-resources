#include <iostream>
#include <string>
using namespace std;

class Vozilo {
protected:
	string proizvodjac,model;
	int godinaProizvodnje;
public:
	//konstruktor
	Vozilo(string proizvodjac, string model, int godinaProizvodnje) {
		this->proizvodjac = proizvodjac;
		this->model = model;
		this->godinaProizvodnje = godinaProizvodnje;
	}
	//abstraktna metoda
	virtual void prikaziInformacije() = 0;
	//abstraktna metoda
	virtual void pokreni() = 0;
	//setteri
	void setProizvodjac(string proizvodjac) {
		this->proizvodjac = proizvodjac;
	}
	void setModel(string model) {
		this->model = model;
	}
	void setGodinaProizvodnje(int godinaProizvodnje) {
		this->godinaProizvodnje = godinaProizvodnje;
	}
	//getteri
	string getProizvodjac() {
		return this->proizvodjac;
	}
	string getModel() {
		return this->model;
	}
	int getGodinaProizvodnje() {
		return this->godinaProizvodnje;
	}
};

class Automobil : public Vozilo {
protected:
	int brojVrata;
public:
	//konstruktor
	Automobil(int brojVrata,string proizvodjac, string model, int godinaProizvodnje) 
		: Vozilo(proizvodjac, model, godinaProizvodnje) {
		this->brojVrata = brojVrata;
	}
	//setter
	void setBrojVrata(int brojVrata) {
		this->brojVrata = brojVrata;
	}
	//getter
	int getBrojVrata() {
		return this->brojVrata;
	}
	//abstraktne metode
	void prikaziInformacije() override{
		cout << " == INFO O AUTOMOBILU ==" << endl;
		cout << "Proizvodjac: " << proizvodjac << " | ";
		cout << "Model: " << model << " | ";
		cout << "Godina proizvodnje: " << godinaProizvodnje << " | ";
		cout << "Broj vrata: " << brojVrata << endl;;
	}
	void pokreni() override{
		cout << "Automobil [" << model << "] se pokrece..." << endl;
	}
};

class Motocikl : public Vozilo {
protected:
	string tipMotocikla;
public:
	//konstruktor
	Motocikl(string tipMotocikla, string proizvodjac, string model, int godinaProizvodnje) 
		: Vozilo(proizvodjac, model, godinaProizvodnje) {
		this->tipMotocikla = tipMotocikla;
	}
	//setter
	void setTipMotocikla(string tipMotocikla) {
		this->tipMotocikla = tipMotocikla;
	}
	//getter
	string getTipMotocikla() {
		return this->tipMotocikla;
	}
	//abstraktne metode
	void prikaziInformacije() override {
		cout << " == INFO O MOTOCIKLU ==" << endl;
		cout << "Proizvodjac: " << proizvodjac << " | ";
		cout << "Model: " << model << " | ";
		cout << "Godina proizvodnje: " << godinaProizvodnje << " | ";
		cout << "Tip motocikla: " << tipMotocikla << endl;
	}
	void pokreni() override {
		cout << "Motocikl [" << model << "] se pokrece..." << endl;
	}
};

class Garaza {
protected:
	Vozilo** vozila;
	int brojVozila;
	int kapacitet;
public:
	//konstruktor
	Garaza(int kapacitet) {
		this->kapacitet = kapacitet;
		this->brojVozila = 0;
		vozila = new Vozilo*[kapacitet];
	}
	//destruktor
	~Garaza() {
		for (int i = 0; i < brojVozila; i++) {
			delete vozila[i];
		}
		delete[] vozila;
	}
	void dodajVozilo(Vozilo* v) {
		if (brojVozila < kapacitet){
			vozila[brojVozila++] = v;
		}
		else {
			cout << "Nema dovoljno mesta u garazi..." << endl;
		}
	}
	void ukloniVozilo(int index) {
		if (index >= 0 && index < brojVozila) {
			delete vozila[index];
			//pomeranje vozila u garazi za vrednost 1
			for (int j = index; j < brojVozila - 1; j++) {
				vozila[j] = vozila[j + 1];
			}
			vozila[--brojVozila] = nullptr;
			cout << "Vozilo uklonjeno..." << endl;
		}
		else {
			cout << "Nevalidan indeks..." << endl;
		}
	}
	void prikaziSvaVozila() {
		for (int i = 0; i < brojVozila; i++) {
			cout << "Vozilo #" << i + 1 << endl;
			vozila[i]->prikaziInformacije();
		}
	}
	void pokreniSvaVozila() {
		for (int i = 0; i < brojVozila; i++) {
			cout << "Vozilo #" << i + 1 << endl;
			vozila[i]->pokreni();
		}
	};
};

int main() {
	int brojVozila; cout << "Unesi broj vozila koji zelis da smestis u garazu: "; cin >> brojVozila;
	int izbor; 
	Garaza garaza(brojVozila);

	while (true) {
		cout << "\n=== MENI ===" << endl;
		cout << "1. Dodaj automobil\n";
		cout << "2. Dodaj motocikl\n";
		cout << "3. Prikazi sva vozila\n";
		cout << "4. Pokreni sva vozila\n";
		cout << "5. Ukloni vozilo\n";
		cout << "0. Izlaz\n";
		cout << "Izbor: ";
		cin >> izbor;

		if (izbor >= 0 && izbor <= 5) {
			if (izbor == 0) { return 0; }
			if (izbor == 1) {
				int brojVrata, godinaProizvodnje;
				string proizvodjac, model;
				cout << "Unesi broj vrata: "; cin >> brojVrata;
				cout << "Unesi godinu proizvodnje: "; cin >> godinaProizvodnje;
				cout << "Unesi model auta: "; cin.ignore(); getline(cin, model);
				cout << "Unesi proizvodjac auta: "; cin.ignore(); getline(cin, proizvodjac);
				Vozilo* a = new Automobil(brojVrata, proizvodjac, model, godinaProizvodnje);
				garaza.dodajVozilo(a);
			}
			if (izbor == 2) {
				string tip, proizvodjac, model;
				int godina;
				cout << "Unesi tip motocikla: ";
				cin.ignore();
				getline(cin, tip);
				cout << "Unesi proizvodjaca: ";
				getline(cin, proizvodjac);
				cout << "Unesi model: ";
				getline(cin, model);
				cout << "Unesi godinu proizvodnje: ";
				cin >> godina;
				Vozilo* m = new Motocikl(tip, proizvodjac, model, godina);
				garaza.dodajVozilo(m);
			}
			if (izbor == 3) {
				garaza.prikaziSvaVozila();
			}
			if (izbor == 4) {
				garaza.pokreniSvaVozila();
			}
			if (izbor == 5) {
				int index;
				cout << "Unesi indeks vozila koji zelis da uklonis: "; cin >> index;
				garaza.ukloniVozilo(index - 1);

				cout << "\n--- Vozila nakon uklanjanja ---\n";
				garaza.prikaziSvaVozila();
			}
		}
		else {
			cout << "Nepoznata operacija..." << endl;
		}
	}
	return 0;
}