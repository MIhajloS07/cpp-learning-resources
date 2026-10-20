#pragma once

class Datum {
private:
	int d, m, g; // dan mesec i godina
	bool prestupna(int g);
	int brojDanaUMesecu();
public:
	Datum(int d, int m, int g);
	void inicijalizacija(int d, int m, int g);
	void sledeciDan();
	void prethodniDan();
	void tekuciDatum();
};