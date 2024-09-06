#include <iostream>

using namespace std;

#define N 3

typedef struct {
    string imie;
    string nazwisko;
    int nr_buta;
} typ_osoba;


int main() {
    typ_osoba klasa[N];
    for(int i = 1; i <= N; i++) {
        cout << "Podaj dane " << i << " osoby:" << endl;
        cout << "imie: "; cin >> klasa[i-1].imie;
        cout << "nazwisko: "; cin >> klasa[i-1].nazwisko;
        cout << "nr buta: "; cin >> klasa[i-1].nr_buta;
        cout << endl;
    }

    cout << endl;

    for(int i = 1; i <= N; i++) {
        cout << "Dane " << i << " osoby:" << endl;
        cout << "imie: " << klasa[i-1].imie << endl;
        cout << "nazwisko: " << klasa[i-1].nazwisko << endl;
        cout << "nr buta: " << klasa[i-1].nr_buta << endl;
        cout << endl;
    }
}
