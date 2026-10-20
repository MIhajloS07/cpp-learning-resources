#include <iostream>
#include <cmath>
using namespace std;

void kub(int* ptr);

int main() {

	int prom = 10;
	int* promPtr = &prom; //deklaracija pointera
	cout << "Adresa prom je: " << &prom << endl;
	cout << "Vrednost pre izmene je: " << *promPtr << endl;
	kub(&prom);
	cout << "Adresa prom je: " << &prom << endl;
	cout << "Vrednost nakon izmene je: " << *promPtr << endl;
	kub(&prom);
	cout << "Adresa prom je: " << &prom << endl;
	cout << "Vrednost nakon izmene je: " << *promPtr << endl;
	return 0;
}

void kub(int* ptr) {
	*ptr = pow(*ptr,3);
}