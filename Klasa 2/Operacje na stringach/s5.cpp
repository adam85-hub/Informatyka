#include <iostream>

using namespace std;

//char string::operator[](int i) {
//    cout << i;
//    return 'x';
//}

int main()
{
    string a;
    cout << "Podaj string: ";
    getline(cin, a);
    for(int i = a.size()-2; i >= 0; i--) {
        if(a[i] == ' ' && a[i+1] == ' ') {
            a.erase(i, 1);
        }
    }
    if(a.size() != 0) {
        if(a[a.size()-1]==' ') a.erase(a.size()-1, 1);
        if(a[0]==' ') a.erase(0, 1);
    }
    cout << a << "*" << endl;
    return 0;
}
