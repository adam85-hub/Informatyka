#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, k;
    int p[101], t[100];
    cout << "Program wypisuje liczby pierwsze od 1 do n." << endl;
    cout << "Podaj n(mniejsze od 100): "; cin >> n;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        k = i;
        if (p[k] != 0)
        {
            while (k + i <= n) {
                k = k + i;
                p[k] = 0;
            }
        }
    }

    k = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] != 0 && p[i] != 1) {
            t[k] = p[i];
            cout << t[k] << " ";
            k++;
        }
    }

    cout << endl << "Podaj ktora z kolei liczbe pierwsza wypisac (od 1 do " << k << "): ";

    cin >> k;
    cout << k << " liczba pierwsza to " << t[k-1] << endl;
}
