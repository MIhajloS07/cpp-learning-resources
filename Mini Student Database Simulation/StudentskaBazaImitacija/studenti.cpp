#include <iostream>
#include <string>
using namespace std;

int main() {
	struct student {
		int id_s;
		string firstName_s;
		string lastName_s;
		short grade_s;
	};


	unsigned int numS = 10,i;
	cout << "Enter number of students: "; 
	cin >> numS;
	student students[numS];

	for (i = 0; i < numS; i++) {
		cout << "Enter student ID: "; cin >> students[i].id_s;
		cout << "Enter student first name: "; cin >> students[i].firstName_s;
		cout << "Enter student last name: "; cin >> students[i].lastName_s;
		cout << "Enter student grade: "; cin >> students[i].grade_s;
	}


	return 0;
}