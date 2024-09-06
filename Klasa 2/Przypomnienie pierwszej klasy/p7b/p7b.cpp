#include <iostream>
#include <time.h>

using namespace std;

void printT(int* w, int c, string sep = " ") {
    for(int i = 0; i < c; i++) {
        cout << w[i] << sep;
    }
    cout << endl;
}

int main() {
    int w[11];
    int t[10], c[10];
    for(int i = 0; i <= 10; i++) {
        w[i] = 0;
        c[i] = 0;
    }

    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        int l = 0;
        while(true){
            c[i]++;
            l = rand() % 11 + 20;
            if(w[l-20] == 0) {
                w[l-20] = 1;
                t[i] = l;
                break;
            }
        }
    }

    printT(t, 10);
    printT(c, 10, "  ");
}
