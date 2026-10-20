#include <iostream>

using namespace std;

int main() {
	int opcija; cout << "Unesi opciju (1 - 4): "; cin >> opcija;
		switch (opcija){
		case 1:
			cout << "Otvaranje notepad aplikacije..." << endl;
			system("notepad");
			break;
		case 2:
			cout << "Pingovanje google-a..." << endl;
			system("ping google.com");
			break;
		case 3:
			cout << "Otvaranje command prompta..." << endl;
			system("cmd");
			break;
		case 4:
			cout << "Otvaranje kalkulator aplikacije..." << endl;
			system("calc");
			break;
		default:
			cout << "Unesi opciju od 1 do 4";
	}
	return 0;
}