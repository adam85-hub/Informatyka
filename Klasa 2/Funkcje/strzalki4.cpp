#include <iostream>

using namespace std;

int main() {
    int a,b;
    cout << "Podaj a:";
    cin >> a;
    cout << "Podaj b:";
    cin >> b;
    while(b>a) b=b/2;
    if(b==a) cout << "Da sie";
    else cout << "Nie da sie";
}
