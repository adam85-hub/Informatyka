#include <iostream>
#include <cmath>

using namespace std;

void wypisz(string tytul, string wartosc, string jednostka) {
    cout.width(50);
    cout << left << tytul;
    cout.width(10);
    cout << wartosc << jednostka << endl;
}

int main() {
    float v0, h;
    float g = 9.81;
    cout << "Program oblicza parametry rzutu poziomego" << endl;
    cout << "Podaj v0(m/s): "; cin >> v0;
    cout << "Podaj h(m): "; cin >> h;
    cout << "Parametry rzutu:" << endl;
    float z = sqrt(2 * g * h * v0* v0);
    wypisz("Zasieg:", to_string(z), "m");
    float t = sqrt(2 * h / g);
    wypisz("Czas trwania:", to_string(t), "s");
    float vK = sqrt(2 * g * h + v0 * v0);
    float alfa = acos(v0/vK) * 180.0 / M_PI; // acos zwraca k¹t w radianach
    wypisz("Kat pomiedzy predkoscia koncowa, a poziomem:", to_string(alfa), " stopni.");
    return 0;
}
