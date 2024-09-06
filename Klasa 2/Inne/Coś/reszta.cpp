#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int x;
    cout << "Podaj kwote do wydania: ";
    cin >> x;
    for (int i = 0; i < 9; i++) {
        while(n[i] <= x) {
            cout << n[i] << " ";
            x -= n[i];
        }
    }
}
