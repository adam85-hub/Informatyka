// w pliku lmale.txt zapisano kilkaset calkowitych,nieujemnych liczb maksymalnie 3-cyfrowych.
//Napisz program, ktory obliczy srednia arytmetyczna z liczb z pliku lmale.txt

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int srednia = 0, l, c = 0;
    ifstream f;
    f.open("lmale.txt");
    
    while(!f.eof()) {
        f >> l;

        if(f.fail())
            break;

        c++;
        srednia += l;
    }

    f.close();
    srednia /= c;
    cout << "Srednia wynosi: " << srednia << endl;
}
