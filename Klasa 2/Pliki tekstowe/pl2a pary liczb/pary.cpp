/*
W pliku PARY_LICZB.TXT znajduje siê 1 000 par liczb. Ka¿da para w jednym wierszu.
Liczby w parze rozdzielone s¹ spacj¹. Wszystkie liczby s¹ ca³kowite dodatnie, nie wiêksze
ni¿ 30 000.

Napisz program(y), który(e) dla danych z pliku PARY_LICZB.TXT daje(¹) odpowiedzi
do poni¿szych podpunktów. Odpowiedzi zapisz w pliku ZADANIE5.TXT, a ka¿d¹
odpowiedŸ poprzedŸ liter¹ oznaczaj¹c¹ ten podpunkt.

    a) Ile jest wierszy, w których jedna z wystêpuj¹cych tam liczb jest wielokrotnoœci¹
        tej drugiej?
    b) Ile jest wierszy zawieraj¹cych pary liczb wzglêdnie pierwszych, czyli takich, których
        najwiêkszy wspólny dzielnik tych liczb równa siê 1?
    c) Ile jest wierszy, dla których suma cyfr pierwszej liczby jest równa sumie cyfr
        drugiej liczby?
*/

#include <iostream>
#include <fstream>

using namespace std;

int nwd(int a, int b) {
    if(b == 0) return a;
    return nwd(b, a%b);
}

int suma_cyfr(int a) {
    int j;
    for(j = 1; j < a; j*=10);

    int suma = 0;
    for(int i = j; i >= 1; i/=10){
        suma += a/i;
        a = a%i;
    }
    return suma;
}

int main() {
    ifstream f;
    f.open("PARY_LICZB.txt");

    string linia = "";
    int wielokrotnosci = 0;
    int wpierwsze = 0;
    int tssuma = 0;
    while(!f.eof()) {
        getline(f, linia);

        if(f.fail()) break;

        int a = atoi(linia.substr(0, linia.find(' ')).c_str());
        int b = atoi(linia.substr(linia.find(' ')).c_str());

        if(a%b == 0 || b%a == 0) wielokrotnosci++;
        if(nwd(a, b) == 1) wpierwsze++;
        if(suma_cyfr(a) == suma_cyfr(b)) tssuma++;
    }
    f.close();

    ofstream odp;
    odp.open("zadanie5.txt");
    odp << "a) " << wielokrotnosci << endl;
    odp << "b) " << wpierwsze << endl;
    odp << "c) " << tssuma << endl;
    odp.close();
}

