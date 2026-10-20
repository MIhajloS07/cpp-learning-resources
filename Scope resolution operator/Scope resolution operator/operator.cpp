#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	string ime;
	
	void printName();
};

void Student::printName() {
	cout << ime << endl;
}

int main() {
	Student obj;
	obj.ime = "nebitno";
	obj.printName();
	return 0;
}