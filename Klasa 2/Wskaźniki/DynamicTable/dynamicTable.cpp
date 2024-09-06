#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class DnTable {
    T *tab;
    long long size = 0;

public:
    DnTable(long long s) {
        size = s;
        tab = new T[size];
    }

    T* operator[](int index) {
        return &tab[index];
    }

};

int main() {
    DnTable<int> table(2);
    *table[0] = 10;
    *table[1] = 11;
    cout << *table[0] << endl;
    cout << *table[1] << endl;
}
