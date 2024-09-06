#include <iostream>

using namespace std;

int silnia(int n) {
    if(n <= 1)
        return 1;

    return n * silnia(n - 1);
}

int main() {
    cout << "Program oblicza ilorazy kolejnych watosci funkcji silnia od 1 do 10" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << "silnia(" << i << ") / silnia(" << i - 1 << ") = " << silnia(i) / silnia(i - 1) << endl;
    }

    return 0;
}
