#include <iostream>
#include <math.h>

//Program napisany pierwszym sposobem (ustawanie przez funkcjê obliczParametry zmiennych globalnych)
using namespace std;

//! Zmienne globalne
double l, vk, t;
double g=10;

double stopnieNaRadiany(double stopnie) {
    return stopnie * M_PI / 180;
}
// Oblicza parametry ciała zsuwaj¹cego siê po równi pochy³ej
void obliczParametry(double alfa)
{
    double a = g * sin(stopnieNaRadiany(alfa));
    t = sqrt(2 * l / a);
    vk = a * t;
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
    cout << "Program oblicza parametry ciala zsuwajacego sie po rowni pochylej o dlugosci l podanej z klawiatury" << endl;
    cout << "Podaj l: "; cin >> l;

    wypisz("alfa", "t", "Vk");
    for (double alfa = 5; alfa <= 90; alfa += 5) {
        obliczParametry(alfa);
        wypisz(to_string(alfa), to_string(t), to_string(vk)); // Wypisuje na ekran w tabeli
    }
}
