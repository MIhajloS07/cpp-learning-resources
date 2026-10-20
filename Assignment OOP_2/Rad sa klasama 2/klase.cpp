#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#define PI 3.14
using namespace std;

//enkapsulacije

class Obracun {
private:
	int broj1;
	int broj2;
public:
	//konstruktor
	Obracun(int brojJedan, int brojDva) {
		broj1 = brojJedan;
		broj2 = brojDva;
	}  

	//metode (getteri)
	int Zbir() {
		return broj1 + broj2;
	}
	int Razlika() {
		return broj1 - broj2;
	}
	int Proizvod() {
		return broj1 * broj2;
	}
	int Kolicnik() {
		if (broj1 > broj2) {
			return broj1 / broj2;
		} else {
			cout << "Broj " << broj1 << " se ne moze podeliti sa " << broj2 << endl;
		}
	}
};

class Auto {
private:
	string marka;
	short godinaProizvodnje;
public:
	//konstruktor
	Auto(string markaAuta, short godinaAuta){
		marka = markaAuta;
		godinaProizvodnje = godinaAuta;
	}

	//getteri
	string prikaziMarkuAuta() {
		return marka;
	}
	short prikaziGodinuProizvodnjeAuta() {
		return godinaProizvodnje;
	}
};

class Kvadrat {
private:
	float broj;
public:
	//konstruktor
	Kvadrat(float br) {
		broj = br;
	}

	//getteri
	float povrsina() {
		return pow(broj,2);
	}
	float obim() {
		return 4 * broj;
	}
	float dijagonala() {
		return broj * sqrt(broj);
	}
};

class Pravougaonik {
private:
	float broj1;
	float broj2;
public:
	//konstruktor
	Pravougaonik(float brJedan, float brDva) {
		broj1 = brJedan;
		broj2 = brDva;
	}

	//getteri
	float obim() {
		return 2 * (broj1 + broj2);
	}
	float povrsina() {
		return broj1 * broj2;
	}
	float dijagonala() {
		return sqrt(pow(broj1, 2) + pow(broj2, 2));
	}
};

class Krug {
private:
	float poluprecnik;
public:
	//konstruktor
	Krug(float r) {
		poluprecnik = r;
	}

	//getteri
	float obim() const {
		return 2 * PI * poluprecnik;
	}
	float povrsina() const{
		return pow(poluprecnik, 2) * PI;
	}

};

class Kocka {
private:
	float stranica;
public:
	//konstruktor
	Kocka(float a) {
		stranica = a;
	}

	//getteri
	float stranicaA() {
		return stranica;
	}
	float povrsina() {
		return 6 * pow(stranica, 2);
	}
	float zapremina() {
		return pow(stranica, 3);
	}
	float prostornaDijagonala() {
		return sqrt(3 * pow(stranica,2));
	}
	float poprecniPresek() {
		return stranica * sqrt(2 * pow(stranica, 2));
	}
};

class Prizma {
private:
	float stranicaA;
	float stranicaB;
	float visinaH;
public:
	//konstuktor
	Prizma(float a, float b, float H) {
		stranicaA = a;
		stranicaB = b;
		visinaH = H;
	}

	//getteri
	float stranicaSlovoA() {
		return stranicaA;
	}
	float stranicaSlovoB() {
		return stranicaB;
	}
	float visina() {
		return visinaH;
	}
	float povrsina() {
		return 2 * (stranicaA * stranicaB + stranicaA * visinaH + stranicaB * visinaH);
	}
	float zapremina() {
		return stranicaA * stranicaB * visinaH;
	}
	float prostornaDijagonala() {
		return sqrt(pow(stranicaA, 2) + pow(stranicaB, 2) + pow(visinaH, 2));
	}
	float poprecniPresek() {
		return visinaH * sqrt(pow(stranicaA, 2) + pow(stranicaB, 2));
	}
};

class faktorijel {
private:
	int num;
	int fact;
public:
	//konstruktor
	faktorijel(int n) {
		num = n;
	}

	//getter
	int prikaziBroj() {
		return num;
	}
	int faktorijelBroja() {
		//prvi nacin:
		for (int i = 0; i <= num; i++) {
			(i == 0) ? fact = 1 : fact *= i;
		}
		//drugi nacin:
		/*(n <= 1) ? fact = 1  : fact = n * faktorijelBroja(n - 1);*/
		return fact;
	}
};

class apsolutnaVrednost {
private:
	double broj;
public:
	//konstuktor
	apsolutnaVrednost(double b) {
		broj = b;
	}
	//getter
	double prikaziBroj() {
		return broj;
	}
	double racunajAbs() {
		//prvi nacin:
		/*return abs(broj);*/

		//drugi nacin:
		if (broj >= 0) { return broj; }
		else { return broj * (-1); }
	}
};

class paranNeparan {
private:
	int broj;
public:
	//konstruktor
	paranNeparan(int b) {
		broj = b;
	}

	//getteri
	int prikaziBroj() {
		return broj;
	}
	bool proveriParnost() {
		return (broj % 2 == 0) ? true : false;
	}
};

int main() {
	/*int brJedan, brDva;
	cout << "Unesi prvi broj: "; cin >> brJedan; 
	cout << "Unesi drugi broj: "; cin >> brDva;
	Obracun skup(brJedan, brDva);
	cout << skup.Zbir() << endl;
	cout << skup.Razlika() << endl;
	cout << skup.Proizvod() << endl;
	cout << skup.Kolicnik() << endl;*/

	/*Auto auto1("Bmw",2025);
	cout << auto1.prikaziGodinuProizvodnjeAuta() << endl;
	cout << auto1.prikaziMarkuAuta() << endl;*/

	/*Kvadrat kvadratJedan(5);
	cout << kvadratJedan.obim() << endl;
	cout << kvadratJedan.povrsina() << endl;
	cout << setprecision(4) << kvadratJedan.dijagonala() << endl;*/
	
	/*Pravougaonik prav(5,6);
	cout << setprecision(4) << prav.obim() << endl;
	cout << setprecision(4) << prav.povrsina() << endl;
	cout << setprecision(4) << prav.dijagonala() << endl;*/

	/*Krug krug1(6);
	cout << krug1.obim() << endl;
	cout << krug1.povrsina() << endl;*/

	/*Kocka kocka1(2);
	cout << setprecision(3) << kocka1.stranicaA() << endl;
	cout << setprecision(3) << kocka1.povrsina() << endl;
	cout << setprecision(3) << kocka1.zapremina() << endl;
	cout << setprecision(3) << kocka1.poprecniPresek() << endl;
	cout << setprecision(3) << kocka1.prostornaDijagonala() << endl;*/
	
	
	/*Prizma prvaPrizma(5,6,7);
	cout << setprecision(4) << prvaPrizma.stranicaSlovoA() << endl;
	cout << setprecision(4) << prvaPrizma.stranicaSlovoB() << endl;
	cout << setprecision(4) << prvaPrizma.visina() << endl;
	cout << setprecision(4) << prvaPrizma.povrsina() << endl;
	cout << setprecision(4) << prvaPrizma.zapremina() << endl;
	cout << setprecision(4) << prvaPrizma.prostornaDijagonala() << endl;
	cout << setprecision(4) << prvaPrizma.poprecniPresek() << endl;*/
	
	/*faktorijel fact1(6); 
	cout << fact1.prikaziBroj() << "! = " << fact1.faktorijelBroja();*/

	/*apsolutnaVrednost broj1(-14.445);
	cout << broj1.prikaziBroj() << " (abs) = " << broj1.racunajAbs() << endl;*/
	
	/*paranNeparan broj(620);
	if (broj.proveriParnost()) {
		cout << "Broj je paran!" << endl;
	} else {
		cout << "Broj je naparan!" << endl;
	}*/
	return 0;
}