#include <iostream>

using namespace std;

int main() {

    int i;
    for (i = 0; i < 6; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    for (i = 4; i >= 0; i--) {
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
