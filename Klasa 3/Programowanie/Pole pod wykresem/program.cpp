#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

template<class T>T get_number() {
    T number;
    cin >> number;
    while (cin.fail())
    {
        cin.clear();
        cin.sync();
        cout << "Podano nieprawidlowe dane, podaj jeszcze raz: ";
        cin >> number;
    }
    cin.clear();
    cin.sync();

    return number;
}

float toRad(float deg) {
    return deg / 180 * M_PI;
}

void wczytaj_dane(int& A, int& B, int& n) {
    cout << "Podaj zakres(A, B)" << endl;
    cout << "A: ";
    A = get_number<int>();
    cout << "B: ";
    B = get_number<int>();
    if(A > B) {
        swap(A, B);
        cout << "B jest wieksze od A wiec ich wartosci zamieniono miejscami." << endl;
    }
    do {
        cout << "Podaj gestosc podzialu: ";
        n = get_number<int>();
    } while (n <= 0);
}

template <class F>
float metoda_trapezow(int A, int B, int n, const F&& f) {
    float h = (B - A) / (float)n;
    float p = 0;
    for (int i = 0; i < n; i++) {
        p += (f(A + h * i) + f(A + h * (i + 1))) / 2;
    }
    return p * h;
}

void print_float(string desc, float number) {
    cout << desc << fixed << setprecision(10) << number << endl;
}

int main() {
    cout << "Program do liczenia pola pod wykresem metoda trapezow i calka" << endl;
    cout << "Nacisnij dowolny klawisz aby kontynuowac..." << endl;
    getch();
    
    while (true)
    {
        system("cls");
        cout << "Wybierz typ funkcji: " << endl;
        cout << "1) sin x (w stopniach)" << endl;
        cout << "2) ax^2 + bx + c" << endl;
        char selected_option = getch();
        while(selected_option != '1' && selected_option != '2')
            selected_option = getch();

        if(selected_option == '1') {
            int A, B, n;
            wczytaj_dane(A, B, n);
            float t = toRad(metoda_trapezow(A, B, n, [](float x){ return sinf(toRad(x)); }));
            print_float("Metoda trapezow: ", t);
            float c = -1 * cos(toRad(B)) + cos(toRad(A));
            print_float("Calka: ", c);
            print_float("Roznica: ", abs(t - c));
        }
        else if(selected_option == '2') {
            int A, B, n;
            float a, b, c;
            cout << "Podaj a: ";
            a = get_number<float>();
            cout << "Podaj b: ";
            b = get_number<float>();
            cout << "Podaj c: ";
            c = get_number<float>();
            wczytaj_dane(A, B, n);

            float t = metoda_trapezow(A, B, n, [a, b, c](float x){ return a * x * x + b * x + c; });
            print_float("Metoda trapezow: ", t);
            auto cf = [a, b, c](float x) { return a * x * x * x / 3 + b * x * x / 2 + c * x; };
            float cw = cf(B) - cf(A);
            print_float("Calka: ", c);
            print_float("Roznica: ", abs(t - c));
        }

        cout << endl << "Jeszcze raz? (y/n)";
        char w = getch();
        while (w != 'y')
        {
            if(w == 'n')
                return 0;
            w = getch();
        }
    } 
}

