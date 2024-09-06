#include <iostream>
#include <fstream>

using namespace std;

bool palindrom(string word) {
    for (int i = 0; i < word.size() / 2; i++) {
        if(word.at(i) != word.at(word.size()-i-1))
            return false;
    }

    return true;
}

bool isBinA(string a, string b) {
    if(a.find(b) != -1)
        return true;
    return false;
}

int main() {
    ifstream inf("dane.txt");
    ofstream of_s("slowa.txt");

    int palindromy = 0, zawarte = 0, niezawarte = 0;
    string a, b;
    while(!inf.eof()) {
        inf >> a;
        inf >> b;

        if(inf.fail())
            break;

        if(palindrom(a))
            palindromy++;
        if(palindrom(b))
            palindromy++;

        if(isBinA(a, b))
            zawarte++;

        if(a == b)
            of_s << a << endl;
        else {
            int fromLeft = 0;
            for (int i = 0; i < b.size(); i++) {
                bool fits = true;
                for (int j = 0; j <= i; j++) {
                    if(b.at(b.size() - (j) -1) != a.at(i-j)) {
                        fits = false;
                        break;
                    }
                }
                if(fits)
                    fromLeft = i + 1;
            }

            int fromRight = 0;
            for (int i = 0; i < b.size(); i++) {
                bool fits = true;
                for (int j = 0; j <= i; j++) {
                    // cout << "a pos: " << a.size() - 1 - i + j << " b pos: " << j << endl;
                    if(b.at(j) != a.at(a.size() -1 - i + j)) {
                        fits = false;
                        break;
                    }
                }
                if(fits)
                    fromRight = i + 1;
                // cout << "fromRight: " << fromRight << endl;
            }

            if(fromLeft > fromRight) {
                of_s << b.substr(0, b.size() - fromLeft) + a << endl;
            } else {
                of_s << a.substr(0, a.size() - fromRight) + b << endl;
            }

            if(fromLeft == 0 && fromRight == 0)
                niezawarte++;

            // cout << fromLeft << " " << fromRight << endl;
        }
    }

    of_s.close();
    inf.close();
    ofstream of_zad5("zad_5.txt");
    of_zad5 << "a " << palindromy << endl;
    of_zad5 << "b " << zawarte << endl;
    of_zad5 << "c " << niezawarte << endl;
    cout << "Palindromy: " << palindromy << endl;
    cout << "B zawarte w A: " << zawarte << endl;
    cout << "B niezawarte w A: " << niezawarte << endl;
    of_zad5.close();
}
