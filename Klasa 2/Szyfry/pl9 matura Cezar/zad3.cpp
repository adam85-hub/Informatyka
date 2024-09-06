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
    ifstream inf("dane_6_3.txt");
    ofstream of("wyniki_6_3.txt");

    string s1;
    string s2;
    while(!inf.eof()) {
        inf >> s1;
        inf >> s2;
        if(inf.fail()) break;

        bool good = false;
        for(int i = 1; i < ((int)'Z'-(int)'A')*2; i++) {
            if(szyfruj(s1, i) == s2) {
                good = true;
                break;
            }
        }

        if(!good) {
            of << s1 << endl;
        }
    }
    inf.close();
    of.close();
}
