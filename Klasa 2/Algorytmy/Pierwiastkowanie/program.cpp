#include <iostream>
#include <math.h>

using namespace std;

double dabs(double x) {
    if(x < 0) return -1*x;
    return x;
}

double pierwiastek(double p) {
    double x = p;
    int i = 0;
    while(dabs(p - x*x) > 0.001) {
        x = (x + p/x)/2;
        i++;
    }

    cout << "ilosc iteracji: " << i << endl;
    return x;
}

int main() {
    double l;
    cout << "Podaj liczbe: ";
    cin >> l;
    cout << pierwiastek(l);
}
