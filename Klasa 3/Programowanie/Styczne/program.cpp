#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>
#include <string>

using namespace std;

typedef function<float(float)> Function;

Function f_create(vector<float> w) {
    auto f = [w](float x) -> float
    {
        float value = 0;
        for (int i = 0; i < w.size(); i++)
        {
            value += pow(x, i) * w[i];
        }

        return value;
    };

    return f;
}

Function pochodna(vector<float> w) {
    w[0] = w[1];
    for (int i = 1; i < w.size()-1; i++) {
        w[i] = w[i + 1] * (i + 1);
    }
    w.pop_back();

    return f_create(w);
}

int get_int(string q) {
    string v_str;
    int v;
    size_t l;
    do {
        cout << q;
        cin >> v_str;
        v = stoi(v_str, &l, 10);
    } while (l != v_str.length());

    return v;   
}


float get_float(string q) {
    string v_str;
    float v;
    size_t l;
    do {
        cout << q;
        cin >> v_str;
        v = stof(v_str, &l);
    } while (l != v_str.length());

    return v;   
}

int main() {
    float epsx, a, b;
    int s;
    vector<float> w;
    cout << "Program znajduje miejsce zerowe funkcji metoda stycznych(Metoda Newtona)" << endl;
    s = get_int("Podaj stopien wielomianu: ");
    for (int i = s; i >= 0; i--) {
        w.push_back(get_float("Podaj wspolczynnik przy x^"  + to_string(i) + ": "));
    }
    reverse(w.begin(), w.end());
    Function f = f_create(w);
    a = get_float("Podaj kraniec przedzialu a: ");
    b = get_float("Podaj kraniec przedzialu b: ");
    if(b < a) {
        swap(a, b);
        cout << "b bylo mniejsze od a wiec program je zamienil." << endl;
    }
    epsx = get_float("Podaj dokladnosc: ");

    if(f(a) * f(b) > 0) {
        cout << "Krańce przedzialu nie maja roznych znakow!!!" << endl;
        return 0;
    }

    #define IMAX 100
    int i = 0;
    float x, x_old = a;
    while(true) {
        i++;
        x = x_old - f(x_old) / pochodna(w)(x_old);

        if(abs(x-x_old) <= epsx) {
            break;
        }
        x_old = x;
        if(i > IMAX) {
            cout << "Przekroczono limit iteracji(" << IMAX << ")" << endl;
            return 0;
        }
    }

    cout << "x = " << x << endl;
    cout << "i = " << i;
}
