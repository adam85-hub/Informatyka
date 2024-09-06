#include <iostream>
#include <fstream>

using namespace std;

bool pierwsza(int x) {
    if(x < 2)
        return false;
    if(x == 2)
        return true;

    for (int i = 2; i * i <= x; i++) {
        if(x%i == 0)
            return false;
    }

    return true;
}

string repeat(char x, int c) {
    string s = "";
    for (int i = 0; i < c; i++) {
        s += x;
    }

    return s;
}

#define FILE "pary.txt"

int main() {
    ifstream in(FILE);
    ofstream out("wynik4.txt");

    out << "1)" << endl;
    int l;
    string s;
    while(!in.eof()) {
        in >> l;
        in >> s;

        if(in.fail())
            break;

        if(l%2 != 0)
            continue;

        for (int i = 2; i * 2 <= l; i++) {
            if(pierwsza(i) && pierwsza(l-i)) {
                out << l << " " << i << " " << l - i << endl;
                break;
            }
        }
    }

    in.close();
    in.open(FILE);

    out << "2)" << endl;
    unsigned int snumber = -1;
    string sword;
    while(!in.eof()) {
        in >> l;
        in >> s;

        if(in.fail())
            break;

        char last = s[0];
        int c = 1;
        int longest = 1;
        char lchar = last;
        for (int i = 1; i < s.size(); i++) {
            if(s[i] == last) {
                c++;
            } else {
                if(c > longest) {
                    longest = c;
                    lchar = last;
                }
                last = s[i];
                c = 1;
            }
        }

        out << repeat(lchar, longest) << " " << longest << endl;

        if(l == s.size()) {
            if(l < snumber) {
                snumber = l;
                sword = s;
            }
            else if(l == snumber) {
                for (int i = 0; i < l; i++) {
                    if(s[i] < sword[i]) {
                        sword = s;
                        break;
                    }
                }
            }
        }
    }

    out << "3)" << endl;
    out << snumber << " " << sword << endl;

    in.close();
    out.close();
}
