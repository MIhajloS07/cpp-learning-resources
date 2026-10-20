#include <iostream>

using namespace std;

int main() {

	int promenljiva = 30;
	int* pointer = &promenljiva; //8B za 64bit sys a 4B za 32bit sys
	cout << pointer << endl;

	promenljiva = 10;

	cout << pointer << endl;


	return 0;
}