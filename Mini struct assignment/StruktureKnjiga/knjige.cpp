#include <iostream>
#include <string>
//Za 5 knjiga uneti naslov do 30 karaktera, broj strana int autor do 20 karaktera ispisi naslove knjiga koji imaju vise od 200 strana
using namespace std;

int main() {
	struct knjiga {
		string naslov;
		short BrojStrana;
		string imeAutora;
	};

	int i,brojKnjiga;
	cout << "Unesi broj knjiga: "; cin >> brojKnjiga;
	knjiga* k = new knjiga[brojKnjiga]; //kreiranje instance strukture (objekta) knjiga i vrsenje alokacije memorije
 

	//unos 5 knijga
	for (i = 0; i < brojKnjiga; i++) {
		cout << "-----------------------" << endl;
		cout << "Knijga broj " << i + 1 << ": " << endl;
		cout << "Naslov knjige: ";
		cin.ignore();
		getline(cin, k[i].naslov);
		cout << "broj strana: ";
		cin >> k[i].BrojStrana;
		cin.ignore();
		cout << "Ime autora: ";
		getline(cin, k[i].imeAutora);
	}

	//ispis naslova knjiga koje imaju vise ili jednako od 200 strana
	cout << endl;
	bool postoji = false;
	cout << "" << endl;
	cout << "---------- Knjige ----------" << endl;
	for (i = 0; i < brojKnjiga; i++) {
		if (k[i].BrojStrana >= 200) {
			cout << "Knjiga broj " << i + 1 << ". : ";
			cout << k[i].naslov << endl;
			postoji = true;
		}
	}

	if (!postoji) cout << "Nema knjiga koje imaju 200 ili vise strana!.";

	return EXIT_SUCCESS;
}