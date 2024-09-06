#include <iostream>
#include <fstream>

using namespace std;

string szyfruj(string s, int k) {
    string zs = "";
    for(int i = 0; i < s.size(); i++) {
        zs += (s[i] - (int)'A' + k)%26 + (int)'A';
    }

    return zs;
}

int main() {
    ifstream inf1("dane_6_1.txt");
    ofstream of1("wyniki_6_1.txt");

    string s;
    while(!inf1.eof()) {
        inf1 >> s;
        if(inf1.fail()) break;

        of1 << szyfruj(s, 107) << endl;
    }
    inf1.close();
    of1.close();
}
