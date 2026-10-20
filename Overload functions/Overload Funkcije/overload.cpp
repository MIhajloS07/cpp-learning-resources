#include <iostream>
#include <string>

using namespace std;

string ispis(string text) {
	return text;
}

unsigned int ispis(int num1,int num2) {
	return num1 + num2;
}

float ispis(float RealNum) {
	return RealNum;
}

int main() {
	string text = "Neki tekst";
	int num1 = 2;
	int num2 = 5;
	float RealNum = 3.14;

	cout << ispis(text) << endl;
	return 0;
}