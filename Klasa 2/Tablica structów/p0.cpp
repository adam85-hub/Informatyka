#include <iostream>

using namespace std;

#define N 3

struct Osoba {
    string imie;
    string nazwisko;
    int nr_buta;

    void wypisz() {
        cout << imie << " " << nazwisko << ", nr buta: " << nr_buta << endl;
    }
};


int main() {
    Osoba klasa[N];
    for(int i = 1; i <= N; i++) {
        cout << "Podaj dane " << i << " osoby:" << endl;
        cout << "imie: "; cin >> klasa[i-1].imie;
        cout << "nazwisko: "; cin >> klasa[i-1].nazwisko;
        cout << "nr buta: "; cin >> klasa[i-1].nr_buta;
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < N; i++) {
        klasa[i].wypisz();
    }
}
