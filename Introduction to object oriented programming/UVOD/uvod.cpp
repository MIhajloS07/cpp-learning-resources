#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//ENKAPSULACIJA -> public,private,protected
//NASLEDJIVANJE -> inheritance
//POLIMORFIZAM -> organizacija koda
//ABSTRAKCIJA

//GET i SET metode (GETTERI i SETTERI)

class Car {
private:
	string color;
	int carYear;
public:
	//setter
	void setColor(string carColor) {
		color = carColor;
	}
	//getter
	string getColor() {
		return color;
	}
	//metoda
	void printColor() {
		cout << "Color: " << color;
	}
	void printYear() {
		cout << "Year: " << carYear;
	}
	void accelerate() {
		cout << "brm brm..." << endl;
	}
};

//objekat -> INSTANCA KLASE

class Pravougaonik {
private:
	float stranicaA;
	float stranicaB;
public:
	//setteri
	void setA(float A) {
		stranicaA = A;
	}
	void setB(float B) {
		stranicaB = B;
	}
	//getteri
	float getA() {
		return stranicaA;
	}
	float getB() {
		return stranicaB;
	}

	//metode
	void Obim() {
		cout << "Obim: " << 2 * (stranicaA + stranicaB) << "cm" << endl;
	}
	void Povrsina() {
		cout << "Povrsina: " << stranicaA * stranicaB << "cm2" << endl;
	}
	void Dijagonala() {
		cout << "Dijagonala: " << sqrt(pow(stranicaA, 2) + pow(stranicaB, 2)) << "cm" << endl;
	}
};

class Broj {
private:
	int ucitanBroj;
public:
	Broj(int nekiBroj) {
		ucitanBroj = nekiBroj;
	}
	~Broj() {
		cout << "brisanje resursa objekta.." << endl;
	}
	
	void setBroj(int nekiBroj) {
		ucitanBroj = nekiBroj;
	}
	void proveriParnost() {
		if (ucitanBroj % 2 == 0) {
			cout << "Broj je paran!" << endl;
		}
		else {
			cout << "Broj je neparan!" << endl;
		}
	}
};

int main() {
	/*Car objekat;
	objekat.setColor("green");
	objekat.printColor();*/
	/*objekat.printYear();
	objekat.accelerate();*/

	/*Pravougaonik obj;
	obj.setA(4);
	obj.setB(6);
	obj.Obim();
	obj.Dijagonala();
	obj.Povrsina();
	cout << obj.getA();*/

	Broj ucitan(621);
	ucitan.proveriParnost();
	ucitan.proveriParnost();
	return 0;
}