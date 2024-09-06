#include <iostream>
#include <math.h>

using namespace std;

void print(string s) {
    cout << s << endl;
}

//Funkcja wypisuje objêtoœæ prostopad³oœcianu
double objP(double a, double b, double c) {
    return a*b*c;
}

//Funkcja wypisuje objêtoœæ ko³a
double objK(double r) {
    return (4/3) * M_PI * r * r * r;
}

//Funkcja wypisuje objêtoœæ walca
double objW(double r, double h) {
    return M_PI * r * r * h;
}

//Funkcja wypisuje objêtoœæ sto¿ka
double objS(double r, double h) {
    return M_PI * r * r * r * h * (1/3);
}

int main() {
    int w;
    print("Program oblicza objetosci bryl.");
    print("Menu:");
    print("1 - Prostopadloscian");
    print("2 - Kula");
    print("3 - Walec");
    print("4 - Stozek");
    cin >> w;

    //! Wybieranie opcji w menu:
    if(w == 1) {
        double a, b, c;
        cout << "Podaj dlugosc boku a: "; cin >> a;
        cout << "Podaj dlugosc boku b: "; cin >> b;
        cout << "Podaj dlugosc boku c: "; cin >> c;
        cout << "Objetosc prostopadloscianu wynosi: " << objP(a, b, c) << endl;
    }
    else if (w == 2) {
        double r;
        cout << "Podaj promien: "; cin >> r;
        cout << "Objetosc kuli wynosi: " << objK(r) << endl;
    }
    else if (w == 3) {
        double r, h;
        cout << "Podaj promien: " ; cin >> r;
        cout << "Podaj wysokosc: "; cin >> h;
        cout << "Objetosc walca wynosi: " << objW(r, h) << endl;
    }
    else if (w == 4) {
        double r, h;
        cout << "Podaj promien: " ; cin >> r;
        cout << "Podaj wysokosc: "; cin >> h;
        cout << "Objetosc stozka wynosi: " << objS(r, h) << endl;
    }
    else {
        print("Taka opcja nie istnieje");
    }

    return 0;
}
