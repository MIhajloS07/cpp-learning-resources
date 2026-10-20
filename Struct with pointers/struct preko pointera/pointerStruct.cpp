#include <iostream>
#include <cstring>

using namespace std;

//globalna struktura
struct Knjiga {
	string Autor;
	string imeKnjige;
	int BrojStrana;
};

void izvuciPodatak(Knjiga *instanca);

int main() {
	Knjiga knjiga1;

	knjiga1.Autor = "Mihajlo Pupin";
	knjiga1.BrojStrana = 265;
	knjiga1.imeKnjige = "Stvaralastvo";

	izvuciPodatak(&knjiga1);
	return 0;
}

void izvuciPodatak(Knjiga *instanca) {
	cout << instanca -> Autor << endl;
	cout << instanca -> BrojStrana << endl;
	cout << instanca -> imeKnjige << endl;
}