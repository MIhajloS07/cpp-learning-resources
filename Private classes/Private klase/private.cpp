#include <iostream>
#include <string>
using namespace std;

//private
class Person {
private:
	string ime = "Boban";
public:
	void print() {
		cout << ime << endl;
	}
};

//getteri i setteri - getters and setters
class Car {
private:
	string color;
public:
	//setter - metoda koja sluzi za setovanje vrednosti koja uzima private podatak
	void setColor(string carColor) {
		color = carColor;
	}

	//getter - metoda koja uzima private vrednost i radi nesto s njom
	string getColor() {
		return color; //najbolja praksa je da getteri budu povratne metode
	}
};

class Year {
private:
	int year;
public:
	//setter
	void setYear(int y) {
		year = y;
	}
	//getter
	int getYear() {
		return year;
	}
};

class Math {
private:
	float a;
	float b;
public:
	//setter
	void setNumbers(float numOne, float numTwo);

	//konstruktor - metoda koja ima ime klase i poziva se automatski nakon kreiranja instance objekta
	Math(float numOne, float numTwo) {
		a = numOne;
		b = numTwo;
	}


	//getters
	float getSum() {
		return a + b;
	}

	float getDifference() {
		return a - b;
	}

	float getMultiply() {
		return a * b;
	}

	float getDivide() {
		return (a > b) ? a / b : b / a; //ternarni operator za vracanje kolicnika
	}
};

//setter with resolution scope operator
void Math::setNumbers(float numOne, float numTwo) {
	a = numOne; //set a equal to numOne
	b = numTwo; //set b equal to numTwo
}

class Radnik{
private:
	string ime;
	string posao;
	int radniStaz;
public:
	//konstruktor
	Radnik(string imeR,string posaoR,int radniS) {
		ime = imeR;
		posao = posaoR;
		radniStaz = radniS;
	}
	
	//getteri pomocu scope resolution operatora
	string posaoRadnika();
	string imeRadnika();
	int radniStazRadnika();
};

string Radnik::posaoRadnika(){
	return posao;
}

string Radnik::imeRadnika() {
	return ime;
}

int Radnik::radniStazRadnika() {
	return radniStaz;
}

int main() {
	/*Person prs;
	prs.print();*/
	/*Car mercedes;
	mercedes.setColor("White");
	cout << mercedes.getColor() << endl;*/
	/*Year yr;
	yr.setYear(1985);
	cout << yr.getYear();*/
	/*POMOCU KONSTRUKTORA  Math obj1(3,6);*/
	//POMOCU SETTERA: obj1.setNumbers(3,6); // setting numbers to be a = 3, b = 6
	/*cout << obj1.getSum() << endl;
	cout << obj1.getMultiply() << endl;
	cout << obj1.getDivide() << endl;
	cout << obj1.getDifference(); */
	string ime, posao;
	int radniStaz;
	cin >> ime >> posao;
	cin >> radniStaz;
	if (radniStaz < 0) { cout << "Radni staz mora biti veci od 0"; }
	else {
		Radnik prvi(ime, posao, radniStaz);
		cout << prvi.imeRadnika() << endl;
		cout << prvi.posaoRadnika() << endl;
		cout << prvi.radniStazRadnika() << endl;
	}
	return 0;
}