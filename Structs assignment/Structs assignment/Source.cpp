#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

struct Pixel {
	unsigned int height;
	unsigned int width;
};

unsigned int createPixelScreen(const Pixel& p1) {
	return p1.height * p1.width;
}

int main() {
	//kreiramo strukturu person koji predstavlja neki realni objekat tj covek iz realnog sveta
	struct Person {
		int age;
		string First_name;
		string Last_name;
		string gender;

		//funkcija za ispis podataka
		void writeAll() {
			cout << age << endl;
			cout << First_name << endl;
			cout << Last_name << endl;
			cout << gender << endl;
		}
	};

	struct Krug {
		const float PI = 3.14156;
		float r;

		void obimKruga() {
			cout << "Obim je: " << 2 * r * PI << setprecision(2) << endl;
		}
		void povrsinaKruga() {
			cout << "Povrsina je: " << pow(r, 2) * PI << setprecision(2) << endl;
		}
	};

	//kreiramo strukturu auto koja predsavlja neki realni objekat tj u ovom primeru auto iz realnog sveta
	struct Car {
		int ageOfCar;
		string carModel;
		string carType;

		//kreiramo funkciju za ispis nekog automobila
		void showCar() {
			cout << carModel << endl;
			cout << carType << endl;
			cout << ageOfCar << endl;
		}
	};

	//kreiramo strukturu Pc koja predstavlja neki realni objeat tj u ovom primeru komponente racunara iz realnog sveta
	struct Pc {
		string processor;
		int ramCapacity;
		string graphicsCard;

		//kreiramo funkciju za ispis specifikacija komponenata racunara
		void showSpecs() {
			cout << processor << endl;
			cout << ramCapacity << " GB" << endl;
			cout << graphicsCard << endl;
		}
	};

	struct Animal {
		string animalName;
		string animalType;
		unsigned short animalAge;

		void showAnimalInfo() {
			cout << animalName << endl;
			cout << animalType << endl;
			cout << animalAge << endl;
		}
	};

	struct actionFigure {
		string actionFigureName;
		string actionFigureSize;
		unsigned float actionFigureWeight;
		void showFigureStats() {
			cout << actionFigureName << endl;
			cout << actionFigureSize << endl;
			cout << actionFigureWeight << " kg " << endl;
		}
	};


	Person p1; //kreiramo istancu strukture person
	Car c1; //kreiramo instancu strukture car
	Krug circle1; //kreiramo instancu strukture Krug
	Pc comp1; //kreiramo  instancu strukture Pc
	Pixel px1; //kreiramo instancu strukture Pixel
	Animal dog1; //kreiramo instancu strukture Animal
	actionFigure action1; //kreiramo instancu strukture actionFigure

	//input za krug
	cout << "Enter radius: ";
	cin >> circle1.r;
	cin.ignore();

	//input za actionFigure
	cout << "Enter action figure name: ";
	getline(cin, action1.actionFigureName);
	cout << "Enter action figure size(big,medium,small): ";
	getline(cin, action1.actionFigureSize);
	cout << "Enter action figure weight: ";
	cin >> action1.actionFigureWeight;
	cin.ignore();

	//input za Animal
	cout << "Enter name of the animal: ";
	getline(cin, dog1.animalName);
	cout << "Enter type of the animal: ";
	getline(cin, dog1.animalType);
	cout << "Enter age of the animal: ";
	cin >> dog1.animalAge;
	cin.ignore();

	//input za Pc
	cout << "Enter model of processor : ";
	getline(cin, comp1.processor);

	cout << "Enter model of graphics card: ";
	getline(cin, comp1.graphicsCard);
	cout << "Enter capacity of ram memory (in GB): ";
	cin >> comp1.ramCapacity;
	cin.ignore();


	//input za person
	cout << "Enter first name: ";
	cin >> p1.First_name;
	cout << "Enter last name: ";
	cin >> p1.Last_name;
	cout << "Enter age num: ";
	cin >> p1.age;
	cout << "Enter your gender: ";
	cin >> p1.gender;
	cin.ignore();

	//input za car
	cout << "Enter car model: ";
	getline(cin, c1.carModel);
	cout << "Enter car type: ";
	getline(cin, c1.carType);
	cout << "Enter age of car: ";
	cin >> c1.ageOfCar;
	cin.ignore();

	//input za Pixel
	cout << "Enter height (in px): ";
	cin >> px1.height;
	cout << "Enter widrt (in px): ";
	cin >> px1.width;

	//output
	cout << "\n--- Person Info ---\n";
	p1.writeAll();

	cout << endl;
	cout << "======================" << endl;
	cout << endl;

	cout << "\n--- Car Info ---\n";
	c1.showCar();

	cout << endl;
	cout << "======================" << endl;
	cout << endl;

	cout << "\n--- Circle Calculations ---\n";
	circle1.obimKruga();
	circle1.povrsinaKruga();

	cout << endl;
	cout << "======================" << endl;
	cout << endl;

	cout << "\n--- PC Specifications ---\n";
	comp1.showSpecs();

	cout << endl;
	cout << "======================" << endl;
	cout << endl;

	cout << "\n--- Pixel Screen Resolution ---\n";
	cout << "Total pixels: " << createPixelScreen(px1) << "px" << endl;

	cout << endl;
	cout << "======================" << endl;
	cout << endl;

	cout << "\n--- Animal Info ---\n";
	dog1.showAnimalInfo();

	cout << endl;
	cout << "======================" << endl;
	cout << endl;

	cout << "\n--- Action figure Info ---\n";
	action1.showFigureStats();


	return 0;
}