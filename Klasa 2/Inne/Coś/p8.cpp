#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "Podaj a: ";
    cin >> a;

    int j;
    for(j = 1; j < a; j*=10);

    int suma = 0;
    for(int i = j; i >= 1; i/=10){
        suma += a/i;
        a = a%i;
    }

    cout << suma;
}
