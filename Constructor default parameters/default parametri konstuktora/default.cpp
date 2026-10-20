#include <iostream>
#include <string>

using namespace std;

class Klasa {
private:
	string ime;
	int godine;
public:
	//kreiranje konstuktora sa default parametrima
	Klasa(string nekiString = "Mihajlo",int nekiInt = 17) {
		ime = nekiString;
		godine = nekiInt;
		cout << "Ime: " << ime << endl;
		cout << "Godine: " << godine << endl;
		cout << "---------------" << endl;
	}

};


int main() {
	Klasa klasa1("Miki",68);
	return 0;
}