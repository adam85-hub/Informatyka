#include <iostream>
#include <math.h>

using namespace std;
//! zmiennie globalne
double v0 = 10;
double g = 10;
double z, t;

void rzut(double h) {
    t = sqrt(2 * h * g);
    z = v0 * t;
}

// Wypisuje w tabelce
void wypisz(string o1, string o2, string o3) {
    cout.width(10);
    cout << left << o1;
    cout.width(10);
    cout << o2;
    cout.width(10);
    cout << o3 << endl;
}

int main() {
    cout << "Program oblicza zasieg i czas rzutu poziomego dla zmieniajacej sie wysokosci" << endl;
    wypisz("h", "t", "z");
    for(double h = 1; h <= 10; h++) {
        rzut(h);
        wypisz(to_string(h), to_string(t), to_string(z));
    }
}
