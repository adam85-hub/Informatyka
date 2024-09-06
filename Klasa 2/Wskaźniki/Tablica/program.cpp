#include <iostream>

using namespace std;

int main() {

    #define SIZE 10
    int* tab = new int[SIZE];

    for (int i = 0; i < SIZE; i++)
        tab[i] = i + 1;

        for (int *w = tab; w - tab < SIZE; w++) {
            cout << *w << endl;
        }

    delete [] tab;
    return 0;
}
