#include <iostream>

using namespace std;

int main() {
	//NULL POINTER
	/* NULL pointer se koristi kada nasa promenljiva koja predstavlja pointer ne pokazuje na nikakvu adresu i kako 
	nebi vukao iz kes memorije neke random stvari postavljamo njegovu vrednost kao NULL gde ce imati vrednost 0 dok se
	ne promeni u programu */

	//int	*ptr = NULL; // deklaracija NULL pointera
	//cout << ptr << endl; // izlaz 0
	//
	//if (ptr == NULL) cout << "Pointer ne pokazuje na ni jednu mem. lokaciju!" << endl;
	//else cout << "Pointer pokazuje na neku mem lokaciju!" << endl;



	//POINTERI I ARRAYS(NIZOVI)

	int niz[3] = { 1 , 2 , 3 }; // niz koji se sastoji iz 3 elementa odnosno u ovom slucaju broja
	int* ptr = NULL; // deklaracija pointera

	ptr = niz; // ptr pokazuje na prvi element niza (niz)

	for (int i = 0; i < 3; i++) {
		cout << "---------------------------" << endl;
		cout << "Adresa " << i + 1 << ". elementa je: " << ptr << endl;
		cout << "Vrednost " << i + 1 << ". elementa je: " << *ptr << endl;
		ptr++; //prelazak na sledeci element niza
	}


	return 0;
}