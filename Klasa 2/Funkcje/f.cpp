#include <iostream>
#include <time.h>

//void wypelnij_tablice(int t[], int n) {
//
//
//    for(int i = 0; i < n; i++) {
//        t[i] =
//    }
//}

using namespace std;

int p(int x, int n) {
    if(n < 0) return -1;
    if(n == 0) return 1;
    if(n == 1) return x;

    return x * p(x, n -1);
}

int ps(int x, int n) {
    if(n < 0) return -1;
    if(n == 0) return 1;
    if(n == 1) return x;

    return ps(x, n/2) * ps(x, n - n/2);
}

int main() {
    cout << ps(2, 15);
}
