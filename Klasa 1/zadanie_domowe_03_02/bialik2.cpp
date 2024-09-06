#include <iostream>
#include <math.h>

//Program napisany pierwszym sposobem (wypisywanie wyniku bezpoœrednio przez funkcjê obliczParametry)
using namespace std;


double stopnieNaRadiany(double stopnie) {
    return stopnie * M_PI / 180;
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

// Oblicza parametry cia³a zsuwaj¹cego siê po równi pochy³ej
void obliczParametry(double alfa, double l, double g)
{
    double t, vk;
    double a = g * sin(stopnieNaRadiany(alfa));
    t = sqrt(2 * l / a);
    vk = a * t;
    wypisz(to_string(alfa), to_string(t), to_string(vk)); //Wypisuje na ekran w tabeli
}

int main() {
    double g=10, l;
    cout << "Program oblicza parametry ciala zsuwajacego sie po rowni pochylej o dlugosci l podanej z klawiatury" << endl;
    cout << "Podaj l: "; cin >> l;

    cout << "####################" << endl;
    wypisz("alfa", "t", "Vk");
    for (double alfa = 5; alfa <= 90; alfa += 5) {
        obliczParametry(alfa, l, g);
    }
    cout << "####################" << endl;
}
