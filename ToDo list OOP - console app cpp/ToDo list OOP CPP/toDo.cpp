#include <iostream>
#include <string>
using namespace std;


class Zadatak {
protected:
	string opis;
	bool zavrsen;
public:
	Zadatak(string opis) {
		this->opis = opis;
		this->zavrsen = false;
	}
	void prikaziZadatak(int indeks) {
		cout << (zavrsen ? "[X]" : "[ ]");
		cout << indeks + 1 << ". " << opis << endl;
	}
	void zavrsiZadatak() {
		zavrsen = true;
	}
};

#define MAX_ZADATKA 100

class ToDo {
protected:
	Zadatak* zadaci[MAX_ZADATKA];
	int brojZadatka;
public:

	ToDo() {
		brojZadatka = 0;
	}

	void dodajZadatak(string opis) {
		if (brojZadatka < MAX_ZADATKA) {
			zadaci[brojZadatka++] = new Zadatak(opis);
		}
	}
	void prikaziListu() {
		if (brojZadatka == 0) {
			cout << "--------------------------" << endl;
			cout << "Lista je prazna..." << endl;
			cout << "--------------------------" << endl;
		}
		else {
			for (int i = 0; i < brojZadatka; i++) {
				zadaci[i]->prikaziZadatak(i);
			}
		}
	}
	void oznaciKaoZavrsen(int indeks) {
		if (indeks >= 0 && indeks < brojZadatka) {
			zadaci[indeks]->zavrsiZadatak();
			cout << "Zadatak oznacen kao zavrsen!" << endl;
		}
		else {
			cout << "Nepostojeci indeks!" << endl;
		}
	}

	~ToDo() {
		for (int i = 0; i < brojZadatka; i++) { delete zadaci[i]; }
	}
};


int main() {
	ToDo lista;
	int opcija;
	
	do {
		cout << "=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|" << endl;
		cout << "-- ToDo Lista --" << endl;
		cout << "1. Dodaj zadatak" << endl;
		cout << "2. Prikazi listu" << endl;
		cout << "3. Oznaci zadatak kao zavrsen" << endl;
		cout << "4. Izlaz" << endl;
		cout << "=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|" << endl;
		cout << endl;
		cout << ">> ";
		cin >> opcija;
		cin.ignore();
		
		if (opcija == 1) {
			string opis;
			cout << "Unesite opis zadatka: "; getline(cin, opis);
			lista.dodajZadatak(opis);
			cout << endl;
		} else if (opcija == 2) {
			lista.prikaziListu();
			cout << endl;
		} else if(opcija == 3){
			int broj; cout << "Unesite broj zadatka koji zelite da oznacite kao zavrsen: "; cin >> broj;
			lista.oznaciKaoZavrsen(broj - 1);
			cout << endl;
		}
	} while (opcija != 4);

	cout << "Izlaz..." << endl;
	return 0;
}