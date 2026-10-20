#include <iostream>

using namespace std;


int main() {
	int matrix[100][100];
	unsigned short row,column;
	cout << "-- Matrix writeing --" << endl;
	cout << "Enter row: ";
	cin >> row;
	cout << "Enter column: ";
	cin >> column;
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "A(" << i << ")(" << j << "): ";
			cin >> matrix[i][j];
		}
	} 

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	// najjace

	cout << endl;
	cout << "-------------------" << endl;
	char option;
	cout << "You want to write only on main diagonal? (y/n): ";
	cin >> option;
		if (option == 'y') {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					if (i == j) {
						cout << matrix[i][j] << "\t";
					}
				}
				cout << endl;
			}
		}
		else if (option == 'n') {
			cout << "Exiting..." << endl;
		}
		else {
			cout << "You entered a wrong decision!,try again..." << endl;
		}
	
	return EXIT_SUCCESS;
}