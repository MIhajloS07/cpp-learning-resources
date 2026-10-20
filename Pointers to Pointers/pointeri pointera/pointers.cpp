#include <iostream>

using namespace std;

int main() {
	int val = 500;
	int* prviPtr;
	int** drugiPtr;

	prviPtr = &val;
	cout << "Adresa: " << prviPtr << endl;

	drugiPtr = &prviPtr;
	cout << "Adresa: " << drugiPtr << endl;

	cout << "----------------------" << endl;

	cout << "Vrednost: " << val << endl;
	cout << "Vrednost: " << *prviPtr << endl;
	cout << "Vrednost: " << **drugiPtr << endl;

	return 0;
}