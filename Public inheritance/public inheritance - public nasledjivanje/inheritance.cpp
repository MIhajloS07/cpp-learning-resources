#include <iostream>
#include <string>
using namespace std;

class Primarna {
protected:
	string ime;
public:
	//setter
	void setIme(string ime) {
		this->ime = ime;
	}
	string getIme() {
		return ime;
	}
};

class Sekundarna : public Primarna {
public:
	void printIme(){
		cout << "Vase ime je: " << ime << endl;
	}
};

int main(void) {
	Sekundarna obj;
	obj.setIme("darko");
	cout << obj.getIme() << endl;
	obj.printIme();
}