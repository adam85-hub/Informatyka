#include <iostream>
//niegotowe
using namespace std;

int index(int* t, int szukana, int p = 0, int l = 0) {
    int srodek = (p+l)/2;
    if(t[srodek] == szukana) return srodek;
}

#define LENGTH 10

int main() {
    int t[LENGTH];
    for(int i = 0; i < LENGTH; i++) {
        t[i] = i*10;
    }

    cout << index(t, 30, LENGTH);
}
