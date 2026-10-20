#include <iostream>

using namespace std;

class System {
public:
	void cmd() {
		system("cmd");
	}
	void date() {
		system("date");
	}
};

class Person {
public:
	string name = "Mihajlo";
	void printName() {
		cout << "Your name is: " << name << endl;
	}
};

class Book {
public:
	string nameOfTheBook;
	string Author;
	char rateOfBook;
	short pageNumber;

	void printBook() {
		cout << "Name: " << nameOfTheBook << endl;
		cout << "Author: " << Author << endl;
		cout << "Rate of the book: " << rateOfBook << endl;
		cout << "Numbers of page: " << pageNumber << endl;
	}
};

int main() {
	/*System instancaObjekta;
	instancaObjekta.date();*/

	/*Person person1;
	person1.name = "Mihajlo";
	person1.printName();*/

	/*Book firstBook,secondBook;
	
	firstBook.nameOfTheBook = "Elden Ring";
	firstBook.Author = "Sasa Espanol";
	firstBook.rateOfBook = 'A';
	firstBook.pageNumber = 620;


	secondBook.nameOfTheBook = "Elden Ring";
	secondBook.Author = "Sasa Espanol";
	secondBook.rateOfBook = 'A';
	secondBook.pageNumber = 620;

	firstBook.printBook();
	cout << endl;
	secondBook.printBook();*/

	Person* pointer = new Person();
	Person* pointerTwo = new Person();
	pointer->printName();
	pointerTwo->printName();
	delete pointer;
	delete pointerTwo;
	return 0;
}