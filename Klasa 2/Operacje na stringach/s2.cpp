#include <iostream>

using namespace std;

int f(string a, string b, int start) {
    for(int i = start; i < a.size(); i++) {
        if(a[i] == b[0]) {
            bool is = true;
            if(i+b.size() > a.size()) return -1;
            for(int j = i; j < b.size(); j++) {
                if(a[i+j] != b[j]) is = false;
            }
            if(is) return i;
        }
    }
    return -1;
}

int main()
{
    string a, b;
    cout << "Podaj caly string: ";
    getline(cin, a);
    cout << "Podaj szukany fragment: ";
    getline(cin, b);
    int i = 0;
    int w = 0; // liczba wystapien
    while(i < a.size()){
        int c = f(a, b, i);
        if(c != -1) {
            w++;
            i = c+b.size();
        }
        else {
            break;
        }
    }
    cout << w << endl;
    return 0;
}
