/*
Napisz program, ktory spyta o nazwe pliku zrodlowego i wynikowego, a nastepnie
wywola funkcje NumeryLinii, ktora z pliku tekstowego o podanej nazwie,
przepisze do pliku wynikowego o podanej nazwie, numery linii, w ktorych
w pliku zrodlowym wystepuja liczby pierwsze.

W pliku lmale.txt zapisano kilkaset calkowitych, nieujemnych liczb maksymalnie 3-cyfrowych.

Pamietaj: wewnatrz funkcji nie uzywaj zmiennych globalnych
   oraz : zoptymalizuj sprawdzanie liczb pierwszych.
*/

#include <iostream>
#include <fstream>

using namespace std;

bool pierwsza(int a) {
    if(a<2) return false;
    for(int i = 2; i * i <= a; i++) {
        if(a%i==0) return false;
    }
    return true;
}

void NumeryLinii(string iname, string oname) {
    ifstream fin;
    fin.open(iname);
    ofstream fout;
    fout.open(oname);

    int numer = 1;
    int liczba = 0;
    while(!fin.eof()) {
        fin >> liczba;

        if(fin.fail()) break;

        if(pierwsza(liczba)) {
            fout << numer << endl;
        }

        numer++;
    }

    fin.close();
    fout.close();
}

int main() {
    string iname, oname;
    cout << "Podaj plik wejscowy: ";
    cin >> iname;
    cout << "Podaj plik wyjsciowy: ";
    cin >> oname;
    NumeryLinii(iname, oname);
}
