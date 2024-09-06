#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "Program oblicza ile razy w tablicy 30 losowych liczb znajduje sie liczba podana z klawiatury." << endl;
    int liczby[30];
    int x, x_count;
    srand(time(NULL));

    for(int i = 0; i < 30; i++) {
        liczby[i] = rand()%9+12;
    }

    cout << "Podaj liczbe: ";
    cin >> x;

    for(int i = 0; i < 30; i++) {
        if(liczby[i] == x) x_count++;
    }

    cout << "Liczba " << x << " wystepuje w tej tablicy " << x_count << " razy." << endl << endl;

    cout << "Liczba | Liczba wystapien" << endl;

    for(int i = 12; i <= 20; i++){
        int i_count = 0;
        for(int j = 0; j < 30; j++) {
            if(liczby[j] == i) i_count++;
        }
        cout << "+----+----+" << endl;
        cout << "|" << i << "  |" << i_count;
        if(i_count < 10) cout << "   |";
        else if(i_count < 100) cout << "  |";
        cout << endl;
    }
    cout << "+----+----+" << endl;

    return 0;
}
