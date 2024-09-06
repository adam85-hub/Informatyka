#include <iostream>
#include <fstream>

using namespace std;

string deszyfruj(string s, int k) {
    string zs = "";
    for(int i = 0; i < s.size(); i++) {
        int a = s[i]-65-k;
        while(a<0) {
            a = 26 + a;
        }
        zs += a+65;
    }

    return zs;
}

string szyfruj(string s, int k) {
    string zs = "";
    for(int i = 0; i < s.size(); i++) {
        zs += (s[i] - (int)'A' + k)%26 + (int)'A';
    }

    return zs;
}

int main() {
    ifstream inf("dane_6_2.txt");
    ofstream of("wyniki_6_2.txt");

    string s;
    int k;
    while(!inf.eof()) {
        inf >> s;
        inf >> k;
        if(inf.fail()) break;

        of << deszyfruj(s, k) << endl;
    }
    inf.close();
    of.close();
}
