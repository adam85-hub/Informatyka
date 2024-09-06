#include <iostream>

using namespace std;

#define N 9

void wypisz(int* t, int l) {
    for (int i = 0; i < l; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}

int main() {
    int t[N];
    for (int i = 0; i < N; i++) {
        t[i] = i + 1;
    }

    wypisz(t, N);    

    for (int i = 0; i < N / 2; i++) {
        int buff = t[i];
        t[i] = t[N - i-1];
        t[N - i-1] = buff;
    }

    wypisz(t, N);
}
