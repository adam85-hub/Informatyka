#include <iostream>

using namespace std;

bool* generateTable(int l) {
    bool *t = new bool[l];

    for (int i = 0; i < l; i++) {
        t[i] = true;
    }
    return t;
}

void sito(int l) {
    bool *t = generateTable(l-2);

    for (int i = 2; i * i <= l; i++) {
        if(t[i-2] != false) {
            for (int j = i * i; j <= l; j += i) {
                t[j-2] = false;
            }
        }
    }

    for (int i = 0; i < l; i++) {
        if(t[i] == true)
            cout << i + 2 << " ";
    }
    cout << endl;
}

int main() {
    sito(100);
}
