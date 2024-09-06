/*
Napisz program, ktory spyta o nazwe pliku zrodlowego i wynikowego, a nastepnie
wywola funkcje NumeryLinii, ktora z pliku tekstowego o podanej nazwie,
przepisze do pliku wynikowego o podanej nazwie, numery linii, w ktorych
w pliku zrodlowym wystepuje liczba wieksza od dwoch poprzednich, tworzac
jednoczesnie trzyliczbowy ciag niemalejacy.

W pliku lmale.txt zapisano kilkaset calkowitych, nieujemnych liczb maksymalnie 3-cyfrowych.

Pamietaj: wewnatrz funkcji nie uzywaj zmiennych globalnych
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void NumeryLinii(string iname, string oname) {
    ifstream fin;
    fin.open(iname);
    ofstream fout;
    fout.open(oname);
    vector<int> liczby;

    int liczba;
    while(!fin.eof()) {
        fin >> liczba;

        if(fin.fail()) break;

        liczby.push_back(liczba);
    }

    for(int i = 2; i < liczby.size(); i++) {
        if(liczby[i-2] <= liczby[i-1] && liczby[i-1] < liczby[i]){
            fout << i+1 << endl;
        }
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
