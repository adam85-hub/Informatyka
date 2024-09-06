#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream ifs("pi_przyklad.txt");
    vector<int> numbers;

    int l;
    while(!ifs.eof()) {
        ifs >> l;
        numbers.push_back(l);
        if(ifs.fail()) break;
    }
    ifs.close();
}
