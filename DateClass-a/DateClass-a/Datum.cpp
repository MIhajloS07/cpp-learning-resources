#include "Datum.h"
#include <iostream>

Datum::Datum(int d, int m, int g) {
	this->d = d;
	this->m = m;
	this->g = g;
}

bool Datum::prestupna(int g) {
	return (g % 400 == 0) || (g % 4 == 0 && g % 100 != 0);
}

int Datum::brojDanaUMesecu() {
	switch (m) {
		case 1: case 3: case 5: case 7: 
		case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return prestupna(g) ? 29 : 28;
		default:
			return 0;
	}
}

void Datum::inicijalizacija(int d, int m, int g) {
	this->d = d;
	this->m = m;
	this->g = g;
}

void Datum::sledeciDan() {
	d++;
	if (d > brojDanaUMesecu()) {
		d = 1;
		m++;
		if (m > 12) {
			m = 1;
			g++;
		}
	}
}

void Datum::prethodniDan() {
	d--;
	if (d < 1) {
		m--;
		if (m < 1) {
			m = 12;
			g--;
		}
		d = brojDanaUMesecu();
	}
}

void Datum::tekuciDatum() {
	std::cout << d << "." 
			  << m << "." 
			  << g << "god.";
}
