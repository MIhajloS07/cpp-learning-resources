#include <iostream>

class Rectangle {
private:
    short width;
    short height;

public:
    Rectangle(short w, short h) : width(w), height(h) {}

	void setWidth(short w) {
		width = w;
	}
	void setHeight(short h) {
		height = h;
	}
	short getWidth() const { return width; }
	short getHeight() const { return height; }

	// Inline methods
    short calculateArea() const {
        return width * height;
    }

    short calculatePerimeter() const {
        return 2 * (width + height);
    }

    bool isSquare() const {
        return width == height;
    }
};

inline int add(int varone, int vartwo) {
	return varone + vartwo;
}

inline int multiply(int varone, int vartwo) {
	return varone * vartwo;
}

inline int square(int var) {
	return sqrt(var);
}

int main(void) {
	int a = 1, b = 2;
	int ressum = add(a, b);
	int resmult = multiply(a, b);
	int resultsquare = square(b);
	std::cout << "The sum of " << a << " and " << b << " is: " << ressum << std::endl;
	std::cout << "The multiplication of " << a << " and " << b << " is: " << resmult << std::endl;
	std::cout << "The square of " << b << " is: " << resultsquare << std::endl;

	Rectangle rect(5, 10);
	std::cout << rect.calculateArea() << std::endl;
	std::cout << rect.calculatePerimeter() << std::endl;;
	std::cout << rect.isSquare() << std::endl;;
	return 0;
}