#include <iostream>
using namespace std;

const int N = 2;            // ilosc bajtow
const int R = 4;            // ilosc roznych znakow
const int BITY = 3;         //ilosc bitow do zakodowania 1 znaku

unsigned char v[N];

struct
{
    char znak;
    unsigned char kod;
} t[R];

int i;
string s;
unsigned char kod, dlugosc_vliczby;
unsigned short vliczba, maska;

//----------------------------------------------------------------
main()
{
t[0].znak= 'H';     t[0].kod= 1;
t[1].znak= 'A';     t[1].kod= 2;
t[2].znak= 'N';     t[2].kod= 3;
t[3].znak= 'I';     t[3].kod= 4;

v[0]= 41;
v[1]= 196;
//-------------------------------------
vliczba = v[0]*256 + v[1];
while(vliczba) {
    kod = vliczba>>13;
    vliczba = vliczba<<3;
    if(kod == 0) break;
    s = s + t[kod-1].znak;
}

cout << "odkodowano: " << s <<endl;
}
