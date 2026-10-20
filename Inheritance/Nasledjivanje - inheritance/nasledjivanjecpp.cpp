#include <iostream>
#include <string>
using namespace std;


// bazna ili osnovna klasa
class Zivotinja { 
protected:
	short tezina;
public:
	string ime;
	short godine;	

	void dodavanje(){
		cout << "Jos jedna zivotinaj dodata :) " << endl;
	}
};

//Izvedene klase
class Pas : public Zivotinja {
public:
	
	Pas(string imeZivotinje, short godineZivotinje) {
		this->ime = imeZivotinje;
		this->godine = godineZivotinje;
	}
	~Pas() {
		cout << "Zavrsen razgovor oko psa..." << endl;
	}
	void imePsa(){
		cout << "Ime psa: " << ime << endl;
	}
	void godinePsa() {
		cout << "Starost psa: " << godine << " godine" << endl;
	}

	//setter
	void tezinaPsa(short tezinaZivotinje) {
		tezina = tezinaZivotinje;
	}
	short ispisTezinePsa() {
		return tezina;
	}
};

class Macka : public Zivotinja {
public:
	Macka(string imeZivotinje, short godineZivotinje) {
		ime = imeZivotinje;
		godine = godineZivotinje;
	}
	~Macka() {
		cout << "Zavrsen razgovor oko macke..." << endl;
	}
	void imeMacke() {
		cout << "Ime macke: " << ime << endl;
	}
	void godineMacke() {
		cout << "Starost macke: " << godine << " godine" << endl;
	}
	//setter
	void tezinaMacke(short tezinaZivotinje) {
		tezina = tezinaZivotinje;
	}
	//getter
	short ispisTezineMacke() {
		return tezina;
	}
};

class Konj : public Zivotinja {
public:
	Konj(string imeKonja,short godineKonja) {
		ime = imeKonja;
		godine = godineKonja;
	}
	~Konj(){
		cout << "Zavrsen razgovor oko konja..." << endl;
	}

	void imeKonja() {
		cout << "Ime: " << ime << endl;
	}
	void godineKonja() {
		cout << "Starost konja: " << godine << endl;
	}

	//setter
	void tezinaKonja(short tezinaZivotinje) {
		tezina = tezinaZivotinje;
	}
	//getter
	short ispisTezineKonja(){
		return tezina;
	}
};

class Ptica : public Zivotinja {
public:
	Ptica(string imePtice, short godinePtice) {
		ime = imePtice;
		godine = godinePtice;
	}
	~Ptica() {
		cout << "Zavrsen razgovor oko ptice..." << endl;
	}

	void imePtice() {
		cout << "Ime: " << ime << endl;
	}
	void godinePtice() {
		cout << "Godine: " << godine << endl;
	}
	//setter
	void tezinaPtice(short tezinaPt) {
		tezina = tezinaPt;
	}
	//getter
	short ispisTezinePtice() {
		return tezina;
	}
};


int main() {
	/*Pas mojPas("Rex",3);
	mojPas.tezinaPsa(2);
	cout << "Tezina psa je: " << mojPas.ispisTezinePsa() << "Kg" << endl;
	Konj mojKonj("Nenad",12);
	mojKonj.imeKonja();
	mojKonj.godineKonja();
	mojKonj.tezinaKonja(350);
	cout << "Tezina: " << mojKonj.ispisTezineKonja() << "Kg" << endl;*/

	Ptica mojaPtica("Djole",4);
	mojaPtica.dodavanje();
	mojaPtica.godinePtice();
	mojaPtica.imePtice();
	mojaPtica.tezinaPtice(1);
	cout << "Tezina: " << mojaPtica.ispisTezinePtice() << "kg" << endl;

	return 0;
}