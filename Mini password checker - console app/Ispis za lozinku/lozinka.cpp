#include <iostream>
#include <string>
using namespace std;

string enkripcija(string recenica) {
	char space = ' ';
	int i;
	for (i = 0; i < recenica.size(); i++) {
		if (recenica[i] == space) {
			recenica[i] = space;
		}
		else {
			recenica[i] = '*';
		}
	}
	cout << "--------------------" << endl;
	return recenica;
}

int main() {
	string recenica; cout << "Unesi recenicu: " << endl; getline(cin, recenica);
	string enRecenica = enkripcija(recenica);
	char opcija; // y/n
	cout << "Da li zelis da ispises ekriptovanu recenicu (y/n)? "; cin >> opcija;
	if (opcija == 'y' || opcija == 'Y') {
		cout << enRecenica << endl;
		cout << "=======================" << endl;
	}
	else {
		cout << "Izlaz...";
		return 0;
	}
	return 0;
}
