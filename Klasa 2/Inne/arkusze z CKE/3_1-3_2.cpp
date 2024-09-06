#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("pi_przyklad.txt");
    vector<int> numbers;
    int wystapienia[100];
    for (int i = 0; i < 99; i++) {
        wystapienia[i] = 0;
    }

    int l;
    while(!ifs.eof()) {
        ifs >> l;
        numbers.push_back(l);
        if(ifs.fail()) break;
    }
    ifs.close();

    int c_90 = 0;
    for(int i = 0; i < numbers.size()-2; i++) {
        l = numbers[i]*10+numbers[i+1];
        if(l > 90) c_90++;
        wystapienia[l]++;
    }

    int x_min = 101;
    int x_min_pos;
    int x_max = 0;
    int x_max_pos;
    for(int i = 0; i < 99; i++) {
        if(wystapienia[i] < x_min) {
            x_min = wystapienia[i];
            x_min_pos = i;
        }

        if(wystapienia[i] > x_max) {
            x_max = wystapienia[i];
            x_max_pos = i;
        }
    }





    cout << "Wieksze od 90: " << c_90 << endl;
    cout << "Najmniej: " << x_min << " dla ";
    if(x_min_pos <= 9) cout << "0" << x_min_pos;
    else cout << x_min_pos;
    cout << endl;
    cout << "Najwiecej: " << x_max << " dla ";
    if(x_max_pos <= 9) cout << "0" << x_max_pos;
    else cout << x_max_pos;
    cout << endl;
}
