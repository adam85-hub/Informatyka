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
    cout << "Program znajduje miejsce zerowe funkcji metoda bisekcji" << endl;
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

    int i = 0;
    float x0;
    while(true) {
        i++;
        x0 = (a + b) / 2;
        if(abs(a-x0) < epsx) {
            break;
        }

        if(f(a) * f(x0) < 0) {
            b = x0;
        } else {
            a = x0;
        }
    }

    cout << "x0 = " << x0 << endl;
    cout << "i = " << i;
}
