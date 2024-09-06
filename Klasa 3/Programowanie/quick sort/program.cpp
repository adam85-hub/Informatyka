#include <iostream>

using namespace std;

template<class T>
void printt(T t[], int s) {
    for(int i = 0; i < s; i++)
        cout << t[i] << " ";

    cout << endl;
}

void qsort(int t[], int l, int p) {
    if(p-l < 1) return in;

    int k = in[(l+p)/2];
    int i = l; int j = p;
    while(i < j) {
        while(t[i]<k)
            i++;
        while(t[j]>k)
            j--;

        swap(t[i], t[k]);
        i++; j--;
    }
    if(i>l) qsort(t, l, i-1);
    if(i<p) qsort(t, j+1, p);
}

int main() {

}
