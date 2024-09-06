#include <iostream>

using namespace std;


int main()
{
    string a;
    cout << "Podaj string: ";
    getline(cin, a);
    for(int i = a.size()-1; i > 0; i--) {
        if(a[i] != ' ') {
            a.insert(i, " ");
        }
    }
    cout << a << ".";
    return 0;
}
