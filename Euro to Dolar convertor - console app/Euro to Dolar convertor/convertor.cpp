#include <iostream>

using namespace std;

int main() {
	float amount;
	const double euro = 0.88263267;
	bool running = true;
	while(running){
		cout << "Enter amount (in dolar): "; 
		cin >> amount;
		cout << "Converting... " << endl; cout << endl;
		cout << "----------------------------" << endl;
		cout << amount << " dolars is: " << amount * euro << " euros" << endl;
		cout << "----------------------------" << endl;
	} 
		return EXIT_SUCCESS;
}