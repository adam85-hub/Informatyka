#include <iostream>

using namespace std;

// Zmodyfikuj program według algorytmu pokazanego w podręczniku (str jakaśtam)
// W sensie zoptymalizować trzeba

static int _main() {
    int n, k;
    int t[101], p[100];
    cout << "Program wypisuje liczby pierwsze od 1 do n." << endl;
    cout << "Podaj n(mniejsze od 100): "; cin >> n;

    for (int i = 1; i <= n; i++) {
        t[i] = i;
        cout << t[i] << " ";
    }
    cout << endl;

    for (int i = 2; i <= n; i++) {
        k = i;
        while (k+i <= n) {
            k = k + i;
            t[k] = 0;
        } 
    }

    cout << "====================" << endl;

    for (int i = 1; i <= n; i++) {
        if (t[i] != 0) {
            cout << t[i] << " ";
        }
    }

    k = 0;
    for (int i = 2; i <= n; i++) {
        if (t[i] != 0) {
            k++;
            p[k] = i;
        }
    }

    cout << endl << "===================" << endl;

    for (int i = 1; i <= k; i++) {
        cout << p[i] << " ";
    }

    cout << endl;

    cout << "Ktora kolejna liczbe pierwsza chcesz wypisac: "; cin >> k;
    cout << p[k] << endl;

    return 0;
}