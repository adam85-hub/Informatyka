#include <iostream>

using namespace std;

int* i;

int main() {
    i = new int;
    *i = 5;
    cout << *i << endl;
    delete i;
}
