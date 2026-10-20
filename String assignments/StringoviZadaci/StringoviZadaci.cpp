#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main() {
	string niska;
	int brojCifara = 0; //deklaracija brojaca
	cout << "Unesi nisku:" << endl;
	getline(cin, niska); //Kako bi racunao i razmake i drugu neku rec

	for (int i = 0; i < niska.length(); i++) {
		if (niska[i] >= '0' && niska[i] <= '9') { //proverava ako ima u stringu neki broj izmedju 0 i 9 jer se ti brojevi koriste
			brojCifara++; //povecava se brojac koji broji koliko ima u datom stringu cifre
		}
	}

	cout << "Broj cifara u unetom stringu je: " << brojCifara;

	return 0;
}