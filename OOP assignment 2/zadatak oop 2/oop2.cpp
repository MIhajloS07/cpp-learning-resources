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
	void setIme(string ime) {
		this->ime = ime;
	}
	void setGodine(int godine) {
		this->godine = godine;
	}

	//getteri
	string getIme() {
		return ime;
	}
	int getGodine() {
		return godine;
	}
	
	friend void prikaziZaposlenog(Zaposleni& z);

	/*~Zaposleni() {
		cout << "--- Zaposleni [" << ime << "] je obrisan ---" << endl;
	}*/
};

class Radnik : public Zaposleni {
private:
	int brojSati;
public:
	Radnik(string ime, int godine, int brojSati) : Zaposleni(ime, godine) {
		this->brojSati = brojSati;
	}

	Radnik() : Zaposleni("", 0) {
		brojSati = 0;
	}

	//setter
	void setBrojSati(int brojSati) {
		this->brojSati = brojSati;
	}
	//getter
	int getBrojSati() {
		return brojSati;
	}
	
	int izracunajPlatu() {
		return brojSati * 500;
	}

	friend void prikaziRadnika(Radnik& r);

	/*~Radnik() {
		cout << "--- Radnik [" << ime << "] je obrisan ---" << endl;
	}*/
};

void prikaziZaposlenog(Zaposleni& z) {
	cout << "[Zaposleni] | [ime] " << z.ime << " | [godine] " << z.godine << endl;
}

void prikaziRadnika(Radnik& r) {
	cout << "[Radnik] | [ime] " << r.ime << " | [godine] " << r.godine << " | [broj radnih sati] " << r.getBrojSati() << " | " << " [Plata] " << r.izracunajPlatu() << "rsd" << endl;
}

int main() {
	/*Zaposleni zaposleni1("Mihajlo", 19); prikaziZaposlenog(zaposleni1);
	Zaposleni zaposleni2("Marko", 25); prikaziZaposlenog(zaposleni2);


	Radnik radnik1("Nikola", 34, 160); prikaziRadnika(radnik1); 
	Radnik radnik2("Petar", 23, 45); prikaziRadnika(radnik2); */
	/*cout << endl;*/

	int n; cout << "Unesi broj radnika: "; cin >> n; // broj radnika
	Radnik* radnici = new Radnik[n]; //dinamicko alociranje memorije	
	
	string ime; int godine, brojSati;
	
	for (int i = 0; i < n; i++) {
		cout << "-------------------------------------" << endl;
		cout << "Radnik broj [" << i + 1 << "]" << endl;
		cout << "Unesi ime: "; cin >> ime;
		cout << "Unesi broj godina: "; cin >> godine;
		cout << "Unesi broj radnih sati: "; cin >> brojSati;
		radnici[i] = Radnik(ime,godine,brojSati);
	}

	

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (radnici[j].izracunajPlatu() > radnici[j + 1].izracunajPlatu()) {
				Radnik temp = radnici[j];
				radnici[j] = radnici[j + 1];
				radnici[j + 1] = temp;
			}
		}
	}

	cout << endl;
	cout << "--- Podaci o radnicima sortiranih po plati [rastuce]---" << endl;
	cout << endl;

	for(int i = 0; i < n; i++){
		prikaziRadnika(radnici[i]);
	}


	//petlja za pravljenje vise razmaka
	for (int i = 0; i < 4; i++) {
		cout << endl;
	}

	string imeTrazeno; cout << "Unesi trazeno ime: "; cin >> imeTrazeno;
	bool pronadjeno = false;

	for (int i = 0; i < n; i++) {
		if (radnici[i].getIme() == imeTrazeno) {
			cout << "--- Radnik pronadjen ---" << endl;
			prikaziRadnika(radnici[i]);
			pronadjeno = true;
			break;
		}
	}
	
	if (!pronadjeno) {
		cout << "Radnik sa imenom " << imeTrazeno << " nije pronadjen..." << endl;
	}

	delete[] radnici;
	return 0;
}