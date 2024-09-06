#include <iostream>

using namespace std;

// 1 , 2 , 3 , 4 , 5 , 6 , 7  , 8
// 1 , 1 , 2 , 3 , 5 , 8 , 13 , 21
int fib(int n) {
    if(n <= 2) return 1;

    return fib(n-1) + fib(n-2);
}

int fibit(int n) {
    int a, b, c;
    a = 1;
    b = 1;

    for(int i = 2; i < n; i++) {
        c = a;
        a = a + b;
        b = c;
    }

    return a;
}

int main() {
    cout << (int)'9';
    return 0;
    int n;
    cin >> n;
    cout << fibit(n);
}
