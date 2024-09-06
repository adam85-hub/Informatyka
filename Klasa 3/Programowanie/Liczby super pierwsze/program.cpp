#include<iostream>
#include<fstream>

using namespace std;

bool pierwsza(int x) {
    if(x < 2) return false;

    for(int i = 2; i*i <= x; i++){
        if(x%i == 0) return false;
    }

    return true;
}

bool superpierwsza(int x) {
    if (!pierwsza(x)) return false;

    int suma = 0;
    while(x>0) {
        suma += x%10;
        x /= 10;
    }

    return pierwsza(suma);
}

bool sumap(int x) {
    int suma = 0;
    while(x>0) {
        suma += x%10;
        x /= 10;
    }

    return pierwsza(suma);
}

bool superBpierwsza(int x) {
    if(!superpierwsza(x)) return false;

    int suma = 0;
    while(x>0) {
        suma += x%2;
        x /= 2;
    }

    return pierwsza(suma);
}

int main() {
    ofstream o1("1.txt");
    ofstream o2("2.txt");
    ofstream o3("3.txt");
    int ile1 = 0, ile2 = 0, ile3 = 0, suma2 = 0;
    for(int i = 2; i <= 1000; i++) {
        if(superBpierwsza(i)) {
                ile1++;
                o1 << i << endl;
        }
    }
    for(int i = 100; i <= 10000; i++) {
        if(superBpierwsza(i)) {
                ile2++;
                o2 << i << endl;
                suma2 += i;
        }
    }
    for(int i = 1000; i <= 100000; i++) {
        if(superBpierwsza(i)) {
                ile3++;
                o3 << i << endl;
        }
    }
    o1.close(); o2.close(); o3.close();

    cout << "Dla przedzialu 1: " << ile1 << endl;
    cout << "Dla przedzialu 2: " << ile2 << endl;
    cout << "Dla przedzialu 3: " << ile3 << endl;

    int ilep = 0;
    for(int i = 100; i <= 10000; i++) {
        if(sumap(i)) ilep++;
    }

    cout << endl << "B)" << endl;
    cout << "Z pierwsza suma                                                                      cyfr jest: " << ilep << endl;
    cout << "Czy pierwsza: ";
    if(pierwsza(suma2)) cout << "Tak";
    else cout << "Nie";
    cout << endl;
}
