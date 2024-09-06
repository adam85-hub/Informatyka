/*
Plik dane.txt zawiera w każdej linii pewne słowo.
Z pliku dane.txt przepisz do pliku wyniki.txt tylko te słowa,
które są palindromami.
*/

#include <iostream>
#include <fstream>

using namespace std;

class oFile : public ofstream {
public:
    ~oFile() {
//        cout << "close";
        close();
    }
};

int main() {
    ifstream f;
    f.open("dane.txt");
    oFile o;
    o.open("wyniki.txt");

    string line;
    while(!f.eof()) {
        getline(f, line);

        if(f.fail()) break;

        bool good = true;
        for(int i = 0; i < line.size()/2; i++){
            if(line[i] != line[line.size()-1-i]) {
                good = false;
                break;
            }
        }
        if(good) o << line << endl;
    }
}
