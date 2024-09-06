#include <iostream>

using namespace std;

int horner(int w[4], int x) {
    int wynik = w[3];

    for(int i = 2; i >= 0; i--) {
        wynik = wynik * x + w[i];
    }

    return wynik;
}

int horner2(int w[4], int x, int i = 0) {
    if(i == 2) {
        return w[3]*x + w[2];
    }

    return horner2(w, x, i+1) * x + w[i];
}

int main() {
    int w[4], x;
    for(int i = 3; i >= 0; i--) {
        cout << "Podaj a" << i+1 << ": ";
        cin >> w[i];
    }

    cout << "Podaj x: ";
    cin >> x;

    cout << "W(x) = " << horner(w, x) << endl;
    cout << "W(x) = " << horner2(w, x) << endl;
}
