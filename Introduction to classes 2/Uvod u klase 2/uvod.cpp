#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
public:
	float prosek;
	unsigned short godina;
	string ime;
};


int main() {
	Student stdThree[3];
	int i, j;
	//ucitavanje ucenika
	for (i = 0; i < 3; i++) {
		cout << i + 1 << ". ucenik: " << endl;
		cout << "Unesi ime: "; cin >> stdThree[i].ime;
		cout << "Unesi prosek: "; cin >> stdThree[i].prosek;
		cout << "Unesi godinu koju pohadja: "; cin >> stdThree[i].godina;
	}

	//od najvece ka najmanje sortirana godina skolovanja
	for (i = 0; i < 3 - 1; i++) {
		for (j = 0; j < 3 - i - 1; j++) {
			if (stdThree[i].godina > stdThree[j].godina) {
				Student temp = stdThree[i];
				stdThree[i] = stdThree[j];
				stdThree[j] = temp;
			}
		}
	}

	//ispis ucenika
	for (i = 0; i < 3; i++) {
		cout << i + 1 << ". ucenik: " << endl;
		cout << "Ime: " << stdThree[i].ime << endl;
		cout << "Prosek: " << stdThree[i].prosek << setprecision(2) << endl;
		cout << "Godina koju pohadja: " << stdThree[i].godina << endl;
	}


	return 0;
}