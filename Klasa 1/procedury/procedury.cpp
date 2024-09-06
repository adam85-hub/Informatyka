#include <iostream>
#include <math.h>

using namespace std;

//Funkcja wypisuje na ekranie pole i obwód ko³a
void kolo(double r) {
    double pole, obw;
    pole = M_PI * r * r;
    obw = M_PI * 2 * r;
    cout << "Pole: " << pole << endl;
    cout << "Obwod: " << obw << endl;
}

int main() {
    double r;
    cout << "Program oblicza pole i obwod kola." << endl;
    cout << "Podaj promien kola: "; cin >> r;
    kolo(r); // <- wywo³anie
}
