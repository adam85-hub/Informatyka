#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main() {
    ifstream in("slowa.txt");

    string s;
    vector najs;
    int odp1 = 0;
    int odp2 = 0;
    int naj0 = 0;
    while(!in.eof()){
        in >> s;
        if(in.fail())break;
        int z = 0, j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') z++;
            else j++;
        }
        if(z>j) odp1++;

        bool jedynki = false;
        bool dobre = true;
        for (int i = 0; i < s.size(); i++) {
            if(s[0] != '0') {
                dobre = false;
                break;
            }
            if(jedynki==false) {
                if(s[i]=='1') jedynki = true;
            }
            else {
                if(s[i]=='0'){
                    dobre = false;
                    break;
                }
            }
        }
        int zera = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                zera++;
                if(zera > naj0) {
                    naj0 = zera;
                    najs.clear();
                }
                else if (zera == naj0) {
                    najs.push_back(s);
                }
            }
            else {
                zera = 0;
            }

        }

        if(dobre&&jedynki)odp2++;
    }

    in.close();
    ofstream swynik("wynik4.txt");
    swynik << "4.1) " << odp1 << endl;
    swynik << "4.2) " << odp2 << endl;
    swynik.close();
}
