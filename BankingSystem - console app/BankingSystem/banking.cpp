#include <iostream>
//banking system
using namespace std;


double deposit(double balance) {
	double amountOfDeposit;
	cout << "Enter amount of deposit: ";
	cin >> amountOfDeposit;
	cout << "=========================" << endl;
	cout << "You deposited: " << amountOfDeposit << endl;
	cout << "=========================" << endl;
	return amountOfDeposit;
}

double withdraw(double balance) {
	double amountOfWithDraw = 0;
	cout << "Enter amount of withdraw: ";
	cin >> amountOfWithDraw;
	if (amountOfWithDraw > balance) {
		cout << "Entered bigger num than balance,try again..." << endl;
		balance = 0;
	} else {
		cout << "=========================" << endl;
		cout << "You withdrawing: " << amountOfWithDraw << endl;
		cout << "=========================" << endl;
	}
	return amountOfWithDraw;
}

double checkBalance(double balance) {
	cout << "=========================" << endl;
	cout << "Your balance is: " << balance << endl;
	cout << "=========================" << endl;
	return balance;
}

int main() {
	cout << "----------------" << endl;
	cout << ":: Welcome to console banking system ::" << endl;
	cout << "----------------" << endl;
	cout << "d - deposit" << endl;
	cout << "w - withdraw" << endl;
	cout << "c - check balance" << endl;
	cout << "q - quit system" << endl;
	cout << "----------------" << endl;
	double balance = 0; //setting start balance to be 0
	char option;
	for (;;) {
		cout << "Enter option: ";
		cin >> option;
		switch (option) {
		case 'd':
			balance += deposit(balance);
			break;
		case 'w':
			balance -= withdraw(balance);
			break;
		case 'c':
			balance = checkBalance(balance);
			break;
		case 'q':
			cout << "Exiting system...";
				return 0;
			break;
		default:
			cout << "You entered wrong option,try again...";
		}
	}
	return EXIT_SUCCESS;
}