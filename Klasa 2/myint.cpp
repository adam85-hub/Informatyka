#include <iostream>

using namespace std;

class liczba {
    int value;

    public:
    liczba(int v)
    {
        value = v;
    }

    int toInt() {
        return value;
    }

    operator int() {
        return toInt();
    }

    //post-increment
    liczba operator++(int) {
        int v = value;
        value++;
        return liczba(v);
    }

    //pre-increment
    liczba operator++() {
        value++;
        return liczba(value);
    }
};

int main() {
    liczba a(10), b(10);
    cout << a++ << endl;
    cout << ++b << endl;
    cout << "Po:" << endl;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
