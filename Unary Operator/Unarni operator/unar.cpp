#include <iostream>

using namespace std;

//globalna promenljiva
int a = 556;

void printVariable();

int main() {
	int a = 5;
	cout << a << endl; // 5
	cout << ::a << endl; //556
	printVariable(); //556
	return 0;
}

void printVariable() {
	cout << a << endl;
}
