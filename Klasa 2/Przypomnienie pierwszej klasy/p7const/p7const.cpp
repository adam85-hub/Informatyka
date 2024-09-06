#include <iostream>
#include <time.h>

using namespace std;

const int L = 10;
const int A = 20;
const int B = 29;

void printT(int* w, int c) {
    for(int i = 0; i < c; i++) {
        cout << w[i] << " ";
    }
    cout << endl;
}

int main() {
    int w[B-A+1];
    int t[L];
    for(int i = 0; i <= B-A+1; i++) {
        w[i] = 0;
    }

    srand(time(NULL));

    for(int i = 0; i < L; i++) {
        int l = 0;
        while(true){
           l = rand()%(B-A+1)+A;
            if(w[l-A] == 0) {
                w[l-A] = 1;
                t[i] = l;
                break;
            }
        }
    }

    printT(t, L);
}
