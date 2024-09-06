#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream f("cyfry.txt");
    vector<int> ros;

    int l, k;
    int parzyste = 0;
    unsigned int max_suma = 0;
    unsigned int min_suma = -1;
    int m, mi;
    while(!f.eof()){
        f >> l;

        if(f.fail()) break;

        if(l%2==0) parzyste++;

        k = l;
        int suma = 0;

        vector<int> cyfry;
        while(k>0) {
            suma += k%10;
            cyfry.push_back(k%10);
            k/=10;
        }

        bool r = true;
        for(int i = 0; i < cyfry.size()-1; i++) {
            if(cyfry[i]<=cyfry[i+1]) {
                r = false;
                break;
            }
        }

        if(r) ros.push_back(l);

        if(suma > max_suma) {
            max_suma = suma;
            m = l;
        }
        if(suma < min_suma) {
            min_suma = suma;
            mi = l;
        }
    }

    cout << "Liczba parzystych: " << parzyste << endl;
    cout << "Max suma: " << m << endl;
    cout << "Min suma: " << mi << endl;
    cout << "Liczby:" << endl;
    for(int x : ros) {
        cout << x << endl;
    }
}
