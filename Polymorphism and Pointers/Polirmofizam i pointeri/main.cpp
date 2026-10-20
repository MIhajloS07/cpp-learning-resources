#include <iostream>
#include <string>
using namespace std;

class Primarna {
public:
	virtual void print() {
		cout << "Primarna" << endl;
	}
};
class Sekundarna : public Primarna {
public:
	void print() {
		cout << "Sekundarna" << endl;
	}
};
int main() {
	Sekundarna sekundar;

	Primarna* ptr = &sekundar;
	ptr->print();

	return 0;
}