#include <iostream>
#include <fstream>

using namespace std;

class oFile : public ofstream {
public:
    ~oFile() {
        cout << "close";
        close();
    }
};

int main() {
    ifstream f;
    f.open("./imiona.txt");
    ofstream o;
    o.open("./imiona2.txt");

    string line;
    while(!f.eof()) {
        getline(f, line);

        if(f.fail()) break;

        cout << line << endl;
        o << line << endl;
    }

    f.close();
    o.close();

    oFile test;
    test.open("t.txt");
    test << "Test";
}
