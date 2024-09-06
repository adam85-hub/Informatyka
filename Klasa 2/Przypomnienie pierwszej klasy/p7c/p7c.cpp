#include <iostream>
#include <time.h>

using namespace std;

const int L = 10;
const int A = 20;
const int B = 29;

void printT(int* w, int c) {
    for(int i = 0; i < c; i++) {
        cout << w[i] << " ";
    }
    cout << endl;
}

int main() {
    int w[B-A+1];
    int t[L];
    for(int i = 0; i <= B-A+1; i++) {
        w[i] = i+A;
    }


    srand(time(NULL));

    for(int i = 0; i < L; i++) {
        int l = rand()%(L-i)-1;
        t[i] = w[l];
        w[l] = w[L - i];
        printT(w, B - A + 1);
    }

    printT(t, L);
}
