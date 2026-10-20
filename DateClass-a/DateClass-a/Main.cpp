#define _CRT_SECURE_NO_WARNINGS

#include "Datum.h"
#include <iostream>
using namespace std;


int main(void) {
    // Testiranje konstruktora
    Datum datum1(28, 2, 2024);

    cout << "Trenutni datum: ";
    datum1.tekuciDatum();

    // Testiranje sledeceg dana
    datum1.sledeciDan();

    cout << "Sledeci dan: ";
    datum1.tekuciDatum();

    // Testiranje prethodnog dana
    datum1.prethodniDan();

    cout << "Prethodni dan: ";
    datum1.tekuciDatum();

    // Testiranje inicijalizacije
    datum1.inicijalizacija(31, 12, 2025);

    cout << "Novi datum: ";
    datum1.tekuciDatum();

    datum1.sledeciDan();

    cout << "Sledeci dan: ";
    datum1.tekuciDatum();

    datum1.prethodniDan();

    cout << "Prethodni dan: ";
    datum1.tekuciDatum();

    return 0;
}