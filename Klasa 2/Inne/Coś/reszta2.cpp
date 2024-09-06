#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int x;
    cout << "Podaj kwote do wydania: ";
    cin >> x;
    int c = 0;
    for (int i = 0; i < 9; i++) {
        if(n[i] <= x)
            c++;
        while(n[i] <= x)x -= n[i];
    }
    cout <<  "Ilosc roznych nominalow: " << c;
}
