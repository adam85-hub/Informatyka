#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool isDouble(string x) {
    for (int i = 0; i < x.size(); i++) {
        if(((int)x[i] < (int)'0' || (int)x[i] > (int)'9') && (int)x[i] != (int)'-' && (int)x[i] != (int)'.')
            return false;
    }

    return true;
}

double wczytaj(string x) {
    string v;
    cout << "Podaj " << x << ": ";
    cin>>v;
    while(cin.fail() || !isDouble(x)) {
        cin.clear();
        cin.sync();
        cout << "Zrobiles blad podaj jeszcze raz: ";
        cin>>v;
    }
    return stod(v);
}

int main() {
    double a = wczytaj("a");
    while(a == 0) {
        cout << "a nie moze byc zerem, ";
        a = wczytaj("a");
    }
    double b = wczytaj("b");
    double c = wczytaj("c");


    double delta = b * b - 4 * a * c;

    if(delta >= 0) {
        double x1 = ((-b) - sqrt(delta)) / 2 * a;
        double x2 = ((-b) + sqrt(delta)) / 2 * a;

        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } else {
        double k = (-b)/2*a;
        double l = sqrt(-delta)/2*a;

        if(l>0) {
            cout << "x1 = " << k << " - j" << l << endl;
            cout << "x1 = " << k << " + j" << l << endl;
        }
        else {
            cout << "x1 = " << k << " + j" << -l << endl;
            cout << "x1 = " << k << " - j" << -l << endl;
        }
    }

    return 0;
}
