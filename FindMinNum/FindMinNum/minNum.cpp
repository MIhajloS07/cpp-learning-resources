#include <iostream>

using namespace std;

void findMin(int a1, int b1, int c1) {
	int min = a1;
	if (a1 < min) min = a1;
	if (b1 < min) min = b1;
	if (c1 < min) min = c1;
	cout << "Min is: " << min << endl;
}

void findMax(int a1, int b1, int c1) {
	int max = a1;
	if (a1 > max) max = a1;
	if (b1 > max) max = b1;
	if (c1 > max) max = c1;
	cout << "Max is: " << max << endl;
}

int main(){
	int a, b, c;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	findMin(a, b, c);
	findMax(a, b, c);
}