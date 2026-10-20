#include <iostream>
#include <string>
//overload konstruktora
using namespace std;

class Klasa {
private:
	string ime = "Mihajlo";
	short godine = 17;
public:
	//default konsturktor
	Klasa() {
		cout << "Podaci nisu promenjeni!" << endl;
		cout << ime << " " << godine << endl;
	}
	Klasa(string temp) {
		cout << "Menjamo string!" << endl;
		ime = temp;
	}
	Klasa(short brGod) {
		cout << "Menjamo broj godina!" << endl;
		godine = brGod;
	}
	Klasa(string nekiStr, int brGodina) {
		cout << "Menjamo i ime i broj godina!" << endl;
		ime = nekiStr;
		godine = brGodina;
	}
	

	//getter
	void printPodatke() {
		cout << "-----------------------------" << endl;
		cout << "Ime: " << ime << endl;
		cout << "Broj godina: " << godine << endl;
	}
};

class Auto {
private:
	short godiste = 1999;
	string boja = "crna";
	string marka = "BMW";
public:
	Auto() {
		cout << "Ispis default auta: " << endl;
		cout << "Marka: " << marka << endl;
		cout << "Godiste: " << godiste << endl;
		cout << "Boja: " << boja << endl;
	}
	Auto(string markaAuta) {
		cout << "Izmenjena marka auta!" << endl;
		marka = markaAuta;
	}
	Auto(short godisteAuta) {
		cout << "Izmenjeno godiste auta!" << endl;
		godiste = godisteAuta;
	}
	Auto(string bojaAuta, short godisteAuta) {
		cout << "Izmenjena boja i godiste auta!" << endl;
		boja = bojaAuta;
		godiste = godisteAuta;
	}
	Auto(string markaAuta,string bojaAuta,short godisteAuta) {
		cout << "Izmenjeni su svi podaci!" << endl;
		marka = markaAuta;
		boja = bojaAuta;
		godiste = godisteAuta;
	}

	void printujPodatke() {
		cout << "--------------------" << endl;
		cout << "Marka: " << marka << endl;
		cout << "Boja: " << boja << endl;
		cout << "Godiste: " << godiste << endl;
	}
};

class Student {
private:
	short godine;
	string ime;
	short espb_bodovi;
public:
	//default konstuktor
	Student(short brgodine, short brespb_bodovi, string StudentIme) {
		godine = brgodine;
		espb_bodovi = brespb_bodovi;
		ime = StudentIme;
	}

	//metode
	void StudentPodaci() {
		cout << "----------------------" << endl;
		cout << "Ime: " << ime << endl;
		cout << "Godine: " << godine << endl;
		cout << "Zaradjeni ESPB: " << espb_bodovi << endl;
	}
};
int main(void) {
	/*Klasa klasa1("Sasa Espanol",40);
	klasa1.printPodatke();*/

	/*Auto kola("audi");
	kola.printujPodatke();*/

	Student prviStudent(21,240,"Darko Stosic");
	prviStudent.StudentPodaci();
}