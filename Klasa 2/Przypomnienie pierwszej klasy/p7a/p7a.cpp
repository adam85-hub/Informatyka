#include <iostream>
#include <time.h>

using namespace std;

void printT(int* w, int c, string sep) {
    for(int i = 0; i < c; i++) {
        cout << w[i] << sep;
    }
    cout << endl;
}

int main() {
    int w[11], t[10];
    for(int i = 0; i <= 10; i++) {
        w[i] = 0;
    }

    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        int l = 0;
        while(true){
            l = rand()%11+10;
            if(w[l-10] == 0) {
                w[l-10] += 1;                
                t[i] = l;
                break;
            }
            w[l-10] += 1;                
        }
    }

    printT(t, 10, " ");
    cout << "Ile razy: " << endl;
    for(int i = 0; i <= 10; i++) {
        cout << i + 10 << " ";
    }
    cout << endl;
    printT(w, 11, "  ");
}
