#include <iostream>
#include <string>
using namespace std;

int main() {
	string temp,ime[100],prezime[100];
	int godine[100],n, i, j, x;
	cout << "Unesi broj korisnika: ";
	cin >> n;
	//unos
	if (n == NULL) {
		cout << "Greska pri unosu ERROR::" << endl;
		return 0;
	}
	cout << "Unesi podatke za korisnike: " << endl;
	for (i = 0; i < n; i++) {
		cout << "-----------------" << endl;
		cout << "Korisnik broj:" << i + 1 << endl;
		cout << "Unesi ime: ";
		cin >> ime[i];
		cout << "Unesi prezime: ";
		cin >> prezime[i];
		cout << "Unesi broj godina: ";
		cin >> godine[i];
		cout << "-----------------" << endl;
	}

	//sortiranje
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (godine[i] > godine[j]) {
				//ime
				temp = ime[i];
				ime[i] = ime[j];
				ime[j] = temp;
				//prezime
				temp = prezime[i];
				prezime[i] = prezime[j];
				prezime[j] = temp;
				//godine
				x = godine[i];
				godine[i] = godine[j];
				godine[j] = x;
			}
		}
	}
	//ispis
	for (i = 0; i < n; i++) {
		cout << i + 1 << ". Ime: " << ime[i] << " , prezime: " << prezime[i] << " , godine:" << godine[i] << endl;
	}

	return 0;
}