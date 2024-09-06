#include <iostream>

using namespace std;

#define N 5

void wypisz(int t[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << t[i][j] << " ";
            if(t[i][j] <= 9)
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int t[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            t[i][j] = N*i+j+1;
        }
    }

    cout << "Przed: " << endl;
    wypisz(t);

    // Najpierw przerzucam przez jedną oś
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i; j++) {
            int buff = t[i][j];
            t[i][j] = t[N-j-1][N-i-1];
            t[N-j-1][N-i-1] = buff;
        }   
    }
 
    // a potem przez drugą
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++) {
            int buff = t[i][j];
            t[i][j] = t[j][i];
            t[j][i] = buff;
        }
    }

    cout << "Po: " << endl;
    wypisz(t);
}
