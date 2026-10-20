//zad1.Ucitaj recenicu i izbroj koliko reci sadrzi
//#include <iostream>
//#include <string>
//using namespace std;
//
//int brojReci(string recenica) {
//	char razmak = ' '; int broj = 0; //deklaracija razmaka i brojaca 
//	for (int i = 0; i < recenica.length(); i++) {
//		if (recenica[i] == razmak) {
//			broj++;
//		}
//	}
//	return broj + 1; //vracamo broj razmaka + 1 za broj reci u recenici
//}
//
//int main() {
//	string recenica; cout << "Unesi recenicu: " << endl; 
//	getline(cin, recenica);
//	cout << "Broj reci u unetoj recenici je: " << brojReci(recenica);
//	return 0;
//}



//zad2. Ucitaj niz od n elemenata i ispisati sve brojeve koji su veci od aritmeticke sredine ucitanih parnih brojeva
//#include <iostream>
//using namespace std;
//
//int main() {
//	int n; cout << "Unesi broj elemenata niza: "; cin >> n;
//	int niz[100], i, br = 0, s = 0; 
//	float ars;
//
//	//ucitavanje niza:
//	for (i = 0; i < n; i++) {
//		cout << "niz[" << i << "]: "; cin >> niz[i];
//		br++; s += niz[i];
//	}
//
//	
//	cout << endl;
//	cout << "-------------------" << endl;
//	cout << endl;
//
//	//ispis niza:
//	cout << "Ispis neizmenjenog unetog niza:" << endl;
//	for (i = 0; i < n; i++) {
//		cout << "niz[" << i << "]: " << niz[i] << endl;
//	}
//
//	//aritmeticka sredina parnih brojeva
//	for (i = 0; i < n; i++) {
//		if (niz[i] % 2 == 0) {
//			ars = s / br;
//		}
//	}
//
//	cout << "--------------------------" << endl;
//	cout << "Aritmeticka sredina unetih parnih brojeva u nizu je: " << ars << endl;
//	cout << "--------------------------" << endl;
//
//	//ispis brojeva koji su veci od ars unetih parnih brojeva
//	cout << "Ispis brojeva koji su veci od ars unetih parnih brojeva: ";
//	for (i = 0; i < n; i++) {
//		if (niz[i] > ars) cout << niz[i] << " ";
//	}
//
//	return 0;
//}

//zad3. ucitati dva kompleksna broja (realni i imaginarni deo) koriscenjem strukture i ispisi njihov zbir i razliku
//#include <iostream>
//using namespace std;
//
////globalna stuktura (ima oblast vazenja i unutar funkcija i unutar main programa)
//struct kompleks { 
//	double re; //realni deo
//	double im; //imaginarni deo
//};
//
//kompleks zbir(kompleks a,kompleks b) { // kreiramo funkciju tipa kompleks koja ce da vrati vrednost koja je tipa kompleks
//	kompleks rez;
//	rez.re = a.re + b.re; // rezultat realnih brojeva (zbir)
//	rez.im = a.im + b.im; // rezultat imaginarnih brojeva (zbir)
//	return rez;
//}
//
//kompleks razlika(kompleks a, kompleks b) { // kreiramo funkciju tipa kompleks koja ce da vrati vrednost koja je tipa kompleks
//	kompleks rez;
//	rez.re = a.re - b.re; // rezultat realnih brojeva (razlika)
//	rez.im = a.im - b.im; // rezultat imaginarnih brojeva (razlika)
//	return rez;
//}
//
//int main() {
//	kompleks a, b;
//	cout << "Unesi prvi kompleksan broj (realni,imaginarni): " << endl; 
//	cin >> a.re >> a.im;
//
//	cout << "Unesi drugi kompleksan broj (realni,imaginarni): " << endl;
//	cin >> b.re >> b.im;
//
//	kompleks rezultatZbir = zbir(a, b); // kreiranje promenljive rezultatZbir koja sadrzi povratnu vrednost funkcije zbir
//	kompleks rezultatRazlika = razlika(a, b); // kreiranje promenljive rezultatRazlika koja sadrzi povratnu vrednost funkcije razlika
//	cout << "Zbir dva kompleksna broja (realni,imaginarni) je : " << rezultatZbir.re << " , " << rezultatZbir.im << endl; //ispis za zbir
//	cout << "Razlika dva kompleksna broja (realni,imaginarni) je : " << rezultatRazlika.re << " , " << rezultatRazlika.im << endl; //ispis za razliku
//
//	return 0;
//}

//zad4. Trebaju nam sledeci podaci o ucenicima (ime,prezime,razred).Uneti podatke za nekoliko ucenika i sortirati po razredu koristeci strukturu
//#include <iostream>
//#include <string>
//using namespace std;
//
//
//struct ucenik {
//	string ime;
//	string prezime;
//	short razred;
//};
//
//int main() {
//	int i,j,n; 
//	const int MAX_UCENIKA = 100;
//	cout << "Unesi broj ucenika: "; cin >> n;
//	ucenik ucenici[MAX_UCENIKA];
//	cout << "---------------------" << endl;
//
//	//unos ucenika
//	for (i = 0; i < n; i++) {
//		cout << "Ucenik broj " << i + 1 << ": " << endl;
//		cout << "Unesi ime: "; cin >> ucenici[i].ime;
//		cout << "Unesi prezime: "; cin >> ucenici[i].prezime;
//		cout << "Unesi razred: "; cin >> ucenici[i].razred;
//		cout << endl;
//		cout << "---------------------" << endl;
//	}
//
//	//bubble sort
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n - i - 1; j++) {
//			if (ucenici[j].razred > ucenici[j + 1].razred) { 
//				ucenik temp = ucenici[j];
//				ucenici[j] = ucenici[j + 1];
//				ucenici[j + 1] = temp;
//			}
//		}
//	}
//
//	//ispis ucenika sortiranih po razredu
//	for (i = 0; i < n; i++) {
//		cout << i + 1  << ". " << ucenici[i].ime << " , " << ucenici[i].prezime << " , " << ucenici[i].razred << endl;
//	}
//
//	return 0;
//}

//zad5. Upisati slovo,ceo broj i realan broj u datoteku primer.txt
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream datoteka("primer.txt"); //kreiranje datoteke primer.txt

	char a; int b; float c;
	cout << "Unesi karakter: "; cin >> a;
	cout << "Unesi ceo broj: "; cin >> b;
	cout << "Unesi realan broj: "; cin >> c;

	datoteka << a << endl;
	datoteka << b << endl;
	datoteka << c << endl;

	datoteka.close(); // zatvaranje datoteke

	cout << "Podaci su uspesno upisani u primer.txt";
	return 0;
}