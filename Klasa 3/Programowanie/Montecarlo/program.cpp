#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

#define A 400

int main() {
    srand(time(NULL));
    long n;
    cout << "Podaj liczbe losowan: ";
    cin >> n;

    long in = 0;
    for (long i = 0; i < n; i++) {
        int x = rand() % A - A/2;
        int y = rand() % A - A/2;
        if(pow(x, 2) + pow(y, 2) <= pow(A/2, 2)) {
            in++;
        }
    }

    float pi = 4*(float)in / n;

    cout << "Wyliczone PI: " << pi << endl;
    cout << "M_PI: " << M_PI << endl;
    cout << "Blad: " << abs(M_PI - pi) << endl;
}
