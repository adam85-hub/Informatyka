#include <iostream>
#include <math.h>

using namespace std;
//! zmiennie globalne
double v0 = 10;
double g = 10;
double z, t;

double rzut(double h) {
    double vk;
    t = sqrt(2 * h * g);
    z = v0 * t;
    vk = sqrt(2 * g * h  + v0 * v0);
    return vk;
}

// Wypisuje z odstêpami
void wypisz(string o1, string o2, string o3, string o4) {
    cout.width(10);
    cout << left << o1;
    cout.width(10);
    cout << o2;
    cout.width(12);
    cout << o3;
    cout.width(10);
    cout << o4 << endl;
}

int main() {
    double vk;
    cout << "Program oblicza zasieg i czas rzutu poziomego dla zmieniajacej sie wysokosci" << endl;
    wypisz("h", "t", "z", "vk");
    for(double h = 1; h <= 10; h++) {
        vk = rzut(h);
        wypisz(to_string(h), to_string(t), to_string(z), to_string(vk)); // Wypisuje z odstêpami
    }
}
