#include <iostream>
using namespace std;

const int N = 2;            // ilosc bajtow
const int R = 4;            // ilosc roznych znakow
const int BITY = 3;         //ilosc bitow do zakodowania 1 znaku

unsigned char v[N];

struct
{
    char znak;
    string kod;
} t[R];

string s, vs, kod;
int i;
//-------------------------------------
//-------------------------------------
//-------------------------------------

//----------------------------------------------------------------

string DECtoBIN(unsigned char d) {
    string bin = "";
    if(d == 0) return "00000000";
    while(d > 0) {
        bin += to_string(d%2);
        d /= 2;
    }
    string nbin = "";
    for(int i = bin.size()-1; i >= 0; i--) {
        nbin += bin[i];
    }
    while(nbin.size()<8) nbin = "0" + nbin;
    return nbin;
}

string VtoS(unsigned char v[]) {
    string s = "";
    for(int i = 0; i < N; i++) {
        s += DECtoBIN(v[i]);
    }

    return s;
}

main()
{
t[0].znak= 'H';     t[0].kod= "001";
t[1].znak= 'A';     t[1].kod= "010";
t[2].znak= 'N';     t[2].kod= "011";
t[3].znak= 'I';     t[3].kod= "100";

v[0]= 41;
v[1]= 196;
//-------------------------------------

vs = VtoS(v);

do {
    kod = vs.substr(0, 3);
    vs.erase(0, 3);
    int i = 0;
    while(t[i].kod != kod) i++;
    s += t[i].znak;
} while(vs.find("1") != string::npos);



cout << "odkodowano: " << s <<endl;
}
