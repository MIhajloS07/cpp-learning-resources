#include <iostream>
#include <string>
using namespace std;


class Klasa {
public:
	static int brojac;

	static void staticnaMetoda() {
		cout << "Staticna promenljiva ima vrednost: " << brojac << endl;
	}
	static void increment() {
		++brojac;
	}
	static void decrement() {
		--brojac;
	}

	//getter
	static int metodaZaInkrement() {
		return ++brojac;
	}
};

int Klasa::brojac = 0;

int main() {
	/*try {
		for (int i = 0; i < 5; i++) {
			Klasa::increment();
		}
	}
	catch (exception) {
		cout << "Error!" << endl;
	}
		Klasa::decrement();
		Klasa::staticnaMetoda();*/

	Klasa obj1;
	cout << obj1.metodaZaInkrement();
	cout << obj1.metodaZaInkrement();
	Klasa obj2;
	cout << obj2.metodaZaInkrement();
	Klasa obj3;
	cout << obj3.metodaZaInkrement();
	


	

	return 0;
}