#include <iostream>
#include <string>
using namespace std;

class Primarna {
protected:
	string ime;
public:
	void setujIme(string ime) {
		this->ime = ime;
		cout << "Ime iz primarne je: " << this->ime << endl;
	}
};

class Sekundarna : private Primarna{
public:
	//setovanje nivoa pristupa:
	Primarna::ime;

	void isprintaj() {
		cout << "Ime iz sekundarne je: " << ime << endl;
	}
	void haloPozega(string neki) {
		setujIme(neki);
	}
};

class Tercijalna : public Sekundarna {
public:
	void tercijalnaMetoda(string neki2) {
		haloPozega(neki2);
	}
};



int main() {
	Tercijalna obj;
	obj.ime = "Nikola";
	obj.haloPozega(obj.ime);
	return 0;
}