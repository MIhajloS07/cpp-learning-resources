#include <iostream>
#include <fstream>
using namespace std;


int main() {
	int broj = 54;

	//otvaranje fajla
	ofstream izlaz("broj.dat", ios::binary);

	if (!izlaz.is_open()) { //ako datoteka nije otvorena
		cout << "Greska pri otvaranju datoteke!" << endl;
		return 1;
	}

	izlaz.write((char*)&broj, sizeof(broj));

	if (izlaz.fail()) { //ako ima greske pri pisanju u datoteku
		cout << "Greska pri pisanju u datoteku!" << endl;
		return 2;
	}

	izlaz.close(); //zatvaranje fajla

	//pisanje u fajl
	int procitan = 0;
	ifstream ulaz("broj.dat", ios::binary);

	if (!ulaz.is_open()) { //ako datoteka nije otvorena
		cout << "Greska pri otvaranju datoteke!" << endl;
		return 3;
	}

	ulaz.read((char*)&procitan, sizeof(procitan));

	if (ulaz.eof()) { // ako je doslo do kraja fajla
		cout << "Stigli smo do kraja datoteke!" << endl;
	}

	if (ulaz.fail()) { //ako ima greske pri pisanju u datoteku
		cout << "Greska pri pisanju u datoteku!" << endl;
		return 4;
	}

	cout << "Uspesno procitan broj: " << procitan << endl;
	ulaz.close(); //zatvaranje datoteke
	return 0;
}


