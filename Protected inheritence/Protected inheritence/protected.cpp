#include <iostream>
#include <string>
using namespace std;

// Protected nasleđivanje je tip nasleđivanja kod kojeg članovi osnovne klase
// postaju zaštićeni u izvedenoj klasi. Da bismo omogućili pristup tim metodama
// izvan izvedene klase, u izvedenoj klasi pravimo javnu metodu koja prima parametar
// i prosleđuje ga odgovarajućoj metodi osnovne klase.

class Primarna {
protected:
	string ime;
public:
	void setIme(string ime) {
		this->ime = ime;
	}
	void getIme() {
		cout << "Vase ime: " << ime << endl;
	}
};

class Sekundarna : protected Primarna{
public:
	void setIzSekundarne(string ime) {
		setIme(ime);
	}
	void print(){
		cout << "Vase ime je: " << ime << endl;
	}

};

class Tercijalna : protected Primarna {
public:
	void setIzTercijalne(string ime) {
		setIme(ime);
	}
	void printIme() {
		cout << "Vase ime je : " << ime << endl;
	}
};

int main(){
	/*Sekundarna obj;
	obj.setIzSekundarne("neki str");
	obj.print();*/
	/*Primarna obj;
	obj.setIme("Zoran");
	obj.getIme();*/
	Sekundarna obj;
	obj.setIzSekundarne("Darko JNA");
	obj.print();
	return 0;
}