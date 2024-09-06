#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ifstream dziennik("dziennik.txt");

    int wynik;
    int poprzedni = -1;
    int p_backup;
    int d_s = 0, i_s = 0;
    int najd = 0, najk = 9999999;
    int najdm, najkm;
    int naj_s = 0, w_s = 0, pzs = 0;
    int i = 0;
    while(!dziennik.eof()){
        i++;
        dziennik >> wynik;

        if(dziennik.fail()) break;
        p_backup = poprzedni;

        if(wynik > poprzedni) {
            if(d_s == 0){
                pzs = poprzedni;
                d_s++;
            }
            d_s++;
        } else {
            if(d_s != 0) {
                if(d_s > naj_s) {
                    naj_s = d_s;
                    w_s = poprzedni - pzs;
                }
                if(d_s > 3) i_s++;
                d_s = 0;
            }
        }
        poprzedni = wynik;

        if(wynik > najd){
            najd = wynik;
            najdm = i;
        }
        if(wynik < najk){
            najk = wynik;
            najkm = i;
        }
    }
    if(d_s > naj_s) {
        naj_s = d_s;
        w_s = poprzedni - pzs;
    }
    if(d_s > 3) i_s++;
    dziennik.close();

    ofstream odp("wyniki5.txt");
    odp << "1) " << i_s << endl;
    odp << "2) Najdluzszy: " << najd << " nr: " << najdm << " Najkrotszy: " << najk << " nr: " << najkm << endl;
    odp << "3) Dni: " << naj_s << " Wynik poprawil o: " << w_s << "cm" << endl;
    odp.close();
}
