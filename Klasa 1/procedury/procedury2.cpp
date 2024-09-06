#include <iostream>
#include <math.h>

using namespace std;
double pole, obw; //! zmienne globalne

void kolo(double r) {
    pole = M_PI * r * r;
    obw = M_PI * 2 * r;
}

int main() {
    double r;
    cout << "Program oblicza pole i obwod kola." << endl;
    cout << "Podaj promien kola: "; cin >> r;

    kolo(r);

    cout << "Pole: " << pole << endl;
    cout << "Obwod: " << obw << endl;
}
